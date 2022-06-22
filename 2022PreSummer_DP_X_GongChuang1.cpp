//
// Created by vv123 on 2022/5/17.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const int inf = 1e18;

int n, s, f1[N], f2[N], f[N], M, ans;
struct Edge { int v, w; };
vector<Edge> g[N];

void dfs(int u, int fa) {
    for (auto e : g[u]) {
        int v = e.v, w = e.w;
        if (v == fa) continue;
        dfs(v, u);
        f1[u] = max(f1[u], f1[v] + w);
        M = max(M, f1[u]);
    }
}
bool vis[N];
inline void bfs() {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        if (u != s) {//printf("%d %d %d\n", u, f1[u], f2[u]);
            ans += M - f1[u] - f2[u];
            f2[u] = M - f1[u];
        }
        for (auto e : g[u]) {
            int v = e.v, w = e.w;
            if (vis[v]) continue;
            f2[v] = f2[u] + w;
            q.push(v);
        }
    }
}

signed main() {
    cin >> n >> s;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(s, 0);//for (int i = 1; i <= n; i++) cout << f1[i] << " ";cout << M << endl;
    bfs();//for (int i = 1; i <= n; i++) cout << f2[i] << " ";
    cout << ans << endl;
    return 0;
}

