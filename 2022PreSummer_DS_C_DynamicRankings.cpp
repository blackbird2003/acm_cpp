//
// Created by vv123 on 2022/5/1.
//
//静态查询区间和，可以用前缀和(套单点)..
//动态查询区间和，可以用树状数组(套单点)..
//类似的..
//静态查询第k小，可以用主席树(前缀和套权值线段树(具有可减性))..
//动态查询第k小，可以用树状数组套权值线段树..
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct Query {
    int op, l, r, k;
} q[N];
struct Node {
    int l, r, cnt;
} tr[N << 9];
int n, m, a[N], root[N], idx, siz = 32768;

#define ls tr[u].l,l,mid
#define rs tr[u].r,mid+1,r
#define mid (l + r >> 1)
void update(int& u, int l, int r, int pos, int d) {
    if (!u) u = ++idx;
    tr[u].cnt += d;
    if (l == r) return;
    if (pos <= mid) update(ls, pos, d);
    else update(rs, pos, d);
}
void add(int i, int d) {
    int pos = a[i];
    //printf("(%d,%d)\n", i, d);
    //cout << "->" << a[i] << endl;
    for (; i <= n; i += i & -i)
        update(root[i], 0, siz - 1, pos, d);
}

int node[2][30], cnt0, cnt1;//0:加结点 1:减结点
int query(int l, int r, int k) {
    if (l == r) return l;
    int cnt = 0;
    for (int i = 1; i <= cnt0; i++) //统计差树左子树的cnt
        cnt += tr[tr[node[0][i]].l].cnt;
    for (int i = 1; i <= cnt1; i++)
        cnt -= tr[tr[node[1][i]].l].cnt;
    if (k <= cnt) {
        for (int i = 1; i <= cnt0; i++)
            node[0][i] = tr[node[0][i]].l;
        for (int i = 1; i <= cnt1; i++)
            node[1][i] = tr[node[1][i]].l;
        return query(l, mid, k);
    } else {
        for (int i = 1; i <= cnt0; i++)
            node[0][i] = tr[node[0][i]].r;
        for (int i = 1; i <= cnt1; i++)
            node[1][i] = tr[node[1][i]].r;
        return query(mid + 1, r, k - cnt);
    }
}
int get(int l, int r, int k) {
    memset(node, 0, sizeof node);
    cnt0 = cnt1 = 0;
    for (int i = r; i; i -= i & -i)
        node[0][++cnt0] = root[i];
    for (int i = l - 1; i ; i -= i & -i)
        node[1][++cnt1] = root[i];
    return query(0, siz - 1, k);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        string op;
        cin >> op;
        if (op == "Q") {
            cin >> q[i].l >> q[i].r >> q[i].k;
            q[i].op = 1;
        } else {
            cin >> q[i].l >> q[i].r;
            q[i].op = 2;
        }
    }
    for (int i = 1; i <= n; i++)
        add(i, 1);
    for (int i = 1; i <= m; i++) {
        if (q[i].op == 1) {
            cout << get(q[i].l, q[i].r, q[i].k)<< "\n";
        } else {
            add(q[i].l, -1);
            a[q[i].l] = q[i].r;
            add(q[i].l, 1);
        }
    }
    return 0;
}