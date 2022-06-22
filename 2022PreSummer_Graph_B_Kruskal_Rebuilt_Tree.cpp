//
// Created by vv123 on 2022/4/9.
//
//modified on 2022/4/19:
//我们是否可以这样做？
//把颜色离散化，并二分预处理出每一种颜色不能匹配的L和R,则匹配数为sum_all-sum[L,R]。
//这样，我们需要对每一个新增父节点维护一个树状数组，和一个vector。vector不需要有序。
//每次查询是把小树vector里的点扔到大bit里查询
//那直接把小vector的颜色加到大树状数组上，同时编号push_back到大vector上，可以知道这个过程的复杂度是nlogn的。
//我们可以把每一个树上结点写成一个结构体，里面有一个指针指向vector,另一个指向BIT(逐渐离谱)
//我的数据结构水平十分有限，目前暂时无法AC本题（但没想到竟然可以过样例((）,等水平进一步提高后再回来补qwq
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;

struct Edge {
    int u, v, w;
    bool operator < (const Edge& x) const {
        return w < x.w;
    }
} e[N];

vector<int> G[N];
int n, m, L, cnt, fa[N], d[N];
long long ans = 0;
struct node{
    int color, l, r, pos;
    bool operator < (const node& x) const {
        return color < x.color;
    }
    bool operator < (const int& x) const {
        return color < x;
    }
} c[N];
struct BIT {
    int t[N] = {0};
    void add(int i, int x) {
        for (; i <= n; i += i & -i)
            t[i] += x;
    }
    int sum(int i) {
        int res = 0;
        for (; i; i -= i & -i)
            res += t[i];
        return res;
    }
};
struct treenode {
    int val;
    vector<int>* v;
    BIT* T;
}a[N];

int find(int x) { return x == fa[x] ? fa[x] : fa[x] = find(fa[x]); }

treenode merge(int x, int y, int w) {
    treenode res;
    res.val = w;
    if (a[x].v->size() > a[y].v->size())
        swap(x, y);
    treenode &s = a[x], &t = a[y];
    int siz = t.v->size();
    for (auto i : *s.v) {
        if (i > n) continue;
        ans += w * (siz - (t.T->sum(c[i].r) - t.T->sum(c[i].l-1)));
    }
    for (auto i : *s.v) {
        t.v->push_back(i);
        t.T->add(c[i].color, 1);
    }
    res.T = t.T;
    res.v = t.v;
    return res;
}

void kruskal() {
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; i++) {
        int fu = find(e[i].u), fv = find(e[i].v);
        if (fu != fv) {
            a[++cnt] = merge(fu, fv, e[i].w);
            fa[fu] = fa[fv] = cnt;
            G[cnt].push_back(fu); G[fu].push_back(cnt);
            G[cnt].push_back(fv); G[fv].push_back(cnt);
            if (cnt - n == n - 1) break;
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &L);
    cnt = n;    //重构树点数
    for (int i = 1; i <= n * 2; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i].color);
        c[i].pos = i;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    }
    //----------处理c[i]--------------
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++) {
        c[i].l = lower_bound(c + 1, c + 1 + n, c[i].color - L) - c + 1;
        c[i].r = lower_bound(c + 1, c + 1 + n, c[i].color + L) - c - 1;//[l,r]表示半径为r的开邻域内的颜色，这部分是不被匹配的
    }
    for (int i = 1; i <= n; i++) {
        c[i].color = i;
    }
    sort(c + 1, c + 1 + n, [&](node a, node b) { return a.pos < b.pos; });
    //----------初始化树的叶节点---------
    for (int i = 1; i <= n; i++) {
        a[i].v = new vector<int>;
        a[i].v->push_back(i);
        a[i].T = new BIT;
        a[i].T->add(c[i].color, 1);
    }
    kruskal();
    cout << ans << endl;
    return 0;
}

