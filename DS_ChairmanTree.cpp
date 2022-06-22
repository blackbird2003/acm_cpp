//
// Created by vv123 on 2022/5/1.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, a[N];

struct Node {
    int l, r, cnt;
}tr[N << 5];
int root[N], idx;

vector<int> val;
inline int getid(int x) {
    return lower_bound(val.begin(), val.end(), x) - val.begin() + 1;
}

int build(int l, int r) {
    int p = ++idx;
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
    return p;
}

int insert(int u, int l, int r, int x) {
    int v = ++idx;
    tr[v] = tr[u];
    if (l == r) {
        tr[v].cnt++;
        return v;
    }
    int mid = l + r >> 1;
    if (x <= mid) tr[v].l = insert(tr[u].l, l, mid, x);
    else tr[v].r = insert(tr[u].r, mid + 1, r, x);
    tr[v].cnt = tr[tr[v].l].cnt + tr[tr[v].r].cnt;
    return v;
}

int query(int u, int v, int l, int r, int k) {
    if (l == r) return r;
    int cnt = tr[tr[v].l].cnt - tr[tr[u].l].cnt;
    int mid = l + r >> 1;
    if (k <= cnt) return query(tr[u].l, tr[v].l, l, mid, k);
    else return query(tr[u].r, tr[v].r, mid + 1, r, k - cnt);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val.push_back(a[i]);
    }
    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    int cnt = val.size();
    root[0] = build(1, cnt);
    for (int i = 1; i <= n; i++)
        root[i] = insert(root[i - 1], 1, cnt, getid(a[i]));
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << val[query(root[l - 1], root[r], 1, cnt, k) - 1] << "\n";
    }
    return 0;
}
