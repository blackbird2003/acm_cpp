//
// Created by vv123 on 2022/4/11.
//
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510;
const int INF = 1e15;
int n, m, d[N][N], rk[N][N];

struct Edge { int u, v, w; } e[N * N];

inline void Floyd() {
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

inline int solve() {
    Floyd();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) rk[i][j] = j;
        sort(rk[i] + 1, rk[i] + 1 + n,  [&](int a, int b) { return d[i][a] < d[i][b]; });
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) ans = min(ans, 2 * d[i][rk[i][n]]);
    for (int i = 1; i <= m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        //重点解释下面这个循环，可以看作是乱搞的结果：
        //设f(x)表示如果”中心点“选在当前边上离u点x单位远处，它离最远点的距离，这有可能成为图的“半直径”
        //我们需要求出它的最小值*2来更新ans
        //观察OI-WIKI上的折线图，极小值点满足对于两个点i、j，从u、v两个方向走的距离一个左小右大，一个左大右小（否则，还不如选端点）
        //也就是说极小值点是在d(u,i)<d(u,j)但d(v,i)>d(v,j)时,函数y=d(v,i) + x和y=d(v,j) + w - x的交点，
        //极小值=d(u,i)+x=d(v,j)+w-x
        //=( d(u,i)+x + d(v,j)+w-x ) / 2
        //=(d(u,i)+d(v,j)+w)/2
        //于是树的直径ans可能被极小值*2=d(u,i)+d(v,j)+w更新。
        //进一步观察得到，我们依次选择距离u由第n-1远到近处的i，与之相交的d(v,j)的j一定是上次相交的i(当然，j从n开始)
        //因为两个交点之间上方的折线来自同一个单峰函数，只是左边来自u，右边来自v。(注意观察折线下方的一排平行四边形，可以得到这个结论）
        for (int j = n, i = n - 1; i >= 1; i--) {
            if (d[v][rk[u][i]] > d[v][rk[u][j]]) {
                ans = min(ans, d[u][rk[u][i]] + d[v][rk[u][j]] + w);
                j = i;
            }
        }
    }
    return ans;
}

signed main() {
    //memset(d, 0x3f, sizeof(d)); //never forget!
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            d[i][j] = INF;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (d[u][v] > w) d[u][v] = d[v][u] = w;
        e[i] = {u, v, w};
    }
    cout << solve() << endl;
    return 0;
}
