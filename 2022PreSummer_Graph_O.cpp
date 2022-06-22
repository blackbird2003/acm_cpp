//
// Created by vv123 on 2022/4/11.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int inf = 1e15;
struct Edge { int v, w; };
vector<Edge> G[N];
int n, m, s, d[N], vis[N];
inline void solve() {
    priority_queue<pair<int, int> > q;
    for (int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (Edge& e: G[u]) {
            int v = e.v, w = e.w;
            if (d[v] > d[u] + w) d[v] = d[u] + w, q.push({-d[v], v});
        }
    }
    for (int i = 1; i <= n; i++)
        if (d[i] < inf) cout << d[i] << endl;
        else cout << -1 << endl;
}

signed main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    solve();
    return 0;
}
