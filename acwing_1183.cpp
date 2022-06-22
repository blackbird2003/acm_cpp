//
// Created by vv123 on 2022/4/21.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 10010, M = 30010;

int n, m;
vector<int> G[N];
struct Edge {
    int u, v;
};
int dfn[N], low[N], dfs_clock, bcc_cnt;
int root, ans;

void tarjan(int u) {
    dfn[u] = low[u] = ++dfs_clock;

    int cnt = 0;
    for (auto v: G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]) cnt++;
        } else low[u] = min(low[u], dfn[v]);
    }

    if (u != root && cnt) cnt++;

    ans = max(ans, cnt);
}

int main() {
    while (cin >> n >> m, n || m) {
        root = ans = dfs_clock = bcc_cnt = 0;
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        for (int i = 0; i < n; i++) G[i].clear();
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v), G[v].push_back(u);
        }
        int cnt = 0;
        for (root = 0; root < n; root++) {
            if (!dfn[root]) {
                cnt++;
                tarjan(root);
            }
        }
        cout << ans + cnt - 1 << "\n";
    }
    return 0;
}

