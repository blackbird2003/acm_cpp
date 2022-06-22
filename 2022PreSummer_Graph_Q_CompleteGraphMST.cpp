//
// Created by vv123 on 2022/4/12.
//
//点对之间的边权为|i-j|*D+Ai+Aj
//我们考虑某一连续区间，将它分为左右两边，如果j在左边，i在右边，则左右之间连边的边权为。
//	     (Ai + i × D) + (Aj - j × D)
//假设当前左右两个子区间没有边，那么我们一定要选一条边将它们连接，这条边要如何选择呢？
//先引入一个经典的性质：MST不可能包含一个环上的严格最大边。
//大概可以这样证明：假设我们选了环上最大边，我们加一条边就能复原这个环，则断开环上的一条边，图仍然联通，显然可以断开那个最大边，得到更小生成树
//我们定义Aj - j × D和Ai + i × D为左边和右边的点的权值

//那么结论是:连接左右的边，至少有一个端点是权值最小的点

//我们设在右子区间中(Ai + i × D)最小点为a,次小点为b,左子区间中(Aj - j × D)最小点为x，次小点为y
//则a<->x<->b<->y<->a构成一个环，则MST一定不包含严格最大边y<->b,符合上述结论
//接下来只需证明有一边相等，即a和b权值相等的情况。
//假设x和y已经联通，那显然不会选y，符合上述结论
//如果我们不通过a和b而是通过更左边的点联通x和y，则情况没有变化。下面考虑通过a和b使x和y联通
//假设a和b未联通，则需从4条边中选三条，显然可以选a<->y、a<->x、b<->x
//假设a和b已联通，则显然可以选a<->y、a<->x
//综上，“连接左右的边，至少有一个端点是权值最小的点”是正确的，我们可以对将区间分治递归连上需要的边，边数变为O(NlogN)

#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 5e6 + 5;

int n, D, f[N], A[N], wl[N], wr[N];
struct Edge {
    int u, v, w;
    bool operator < (const Edge& x) const {
        return w < x.w;
    }
} e[M];

void init() { for (int i = 1; i <= n; i++) f[i] = i; }
int find(int x) { return x == f[x] ? f[x] : f[x] = find(f[x]); }
int merge(int x, int y) { return find(x) == find(y) ? 0 : f[find(x)] = find(y);}

int cnt = 0;
void add_edge(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1, minl = l, minr = mid + 1;
    for (int i = l; i <= mid; i++)
        if (wl[i] < wl[minl]) minl = i;
    for (int i = mid + 1; i <= r; i++)
        if (wr[i] < wr[minr]) minr = i;
    for (int i = l; i <= mid; i++)
        e[++cnt] = {i, minr, wl[i] + wr[minr]};
    for (int i = mid + 1; i <= r; i++)
        e[++cnt] = {minl, i, wl[minl] + wr[i]};
    add_edge(l, mid);
    add_edge(mid + 1, r);
}

int kruskal() {
    int res = 0;
    init();
    sort(e + 1, e + 1 + cnt);
    for (int i = 1; i <= cnt; i++) {
        int fu = find(e[i].u), fv = find(e[i].v);
        if (fu == fv) continue;
        f[fu] = fv;
        res += e[i].w;
        if (++cnt == n - 1) break;
    }
    return res;
}

signed main() {
    cin >> n >> D;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        wl[i] = A[i] - i * D;
        wr[i] = A[i] + i * D;
    }
    add_edge(1, n);
    cout << kruskal();
    return 0;
}



