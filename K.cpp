//
// Created by vv123 on 2022/5/1.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
int n, f[N], vis[N];
struct Edge {
    int v, w;
};
vector<Edge> g[N];
int find(int x) {
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}
bool ok;
void dfs(int u, int fa) {
    //printf("->%d f[%d]=%d\n", u, u, f[u]);
    for (auto e:g[u]) {
        int v = e.v, w = e.w;
        if (!vis[v]) {
            vis[v] = 1;
            f[v] = f[u] ^ w;
            dfs(v, u);
        } else if (v != fa && (f[u] ^ w ^ f[v]) != 0) {
            //printf("find cycle %d->%d\n", u, v);
            ok = false;
            return;
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) f[i] = 0, g[i].clear(), vis[i] = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ok = true; vis[1] = 1;
    dfs(1, 0);
    if (ok) puts("Yes");
    else puts("No");
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}


