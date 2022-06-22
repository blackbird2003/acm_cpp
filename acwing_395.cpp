//
// Created by vv123 on 2022/4/21.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 5010, M = 20010;
vector<int> G[N];

stack<int> s;
int dfn[N], low[N], dfs_clock;
int id[N], dcc_cnt, d[N];
struct Edge {
    int u, v;
};
vector<Edge> bridge;


void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++dfs_clock;
    s.push(u);
    for (auto v:G[u]) {
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (dfn[u] < low[v])
                bridge.push_back({u, v});
        } else if (v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        dcc_cnt++;
        int x;
        do {
            x = s.top(); s.pop();
            id[x] = dcc_cnt;
        } while (x != u);
    }
}

int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    tarjan(1, -1);
    int cnt = 0;
    for (auto e: bridge)
        d[id[e.u]]++, d[id[e.v]]++;
    for (int i = 1; i <= dcc_cnt; i++)
        if (d[i] == 1) cnt++;
    if (n == 2) puts("0");
    else cout << (cnt + 1) / 2 << endl;
    return 0;
}
