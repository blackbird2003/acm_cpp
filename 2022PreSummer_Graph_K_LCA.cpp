//
// Created by vv123 on 2022/4/10.
//
//这题事lca的板题
//显然，树上两点之间的最短路径可以用d[u] + d[v] - 2 * d[lca(u, v)]求出
//我们通过假设1号点是根节点，从1开始dfs一遍处理出每个结点u的深度d[u]和i级祖先f[u][i]
//查询lca的大致步骤是，
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int f[N][30], d[N], n, q;
vector<int> G[N];

void dfs(int u, int fa) {
    d[u] = d[fa] + 1; f[u][0] = fa;
    for (int i = 1; (1 << i) < d[u]; i++)
        f[u][i] = f[f[u][i-1]][i-1];
    for (auto v:G[u])
        if (v != fa) dfs(v, u);
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x, y);
    int k = d[x] - d[y];
    for (int i = 25; i >= 0; i--)
        if ((1 << i) & k) x = f[x][i];
    if (x == y) return x;
    for (int i = 25; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return f[x][0];
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << d[u] + d[v] - 2 * d[lca(u, v)] << endl;
    }
    return 0;
}
