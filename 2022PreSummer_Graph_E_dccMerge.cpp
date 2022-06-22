//
// Created by vv123 on 2022/4/21.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> G[N], dcc[N];
int n, m, q, w[N], dfs_clock, dfn[N], low[N], dcc_cnt, iscut[N], dccno[N], root;
stack<int> s;

vector<int> nG[N];
int nw[N];
struct Edge {
    int u, v;
} e[N];

void tarjan(int u) {
    dfn[u] = low[u] = ++dfs_clock;
    s.push(u);
    /*
    if (u == root && G[u].empty()) {
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }
     */
    int cnt = 0;//分支数量
    for (auto v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                //printf("%d-%d\n", u, v);
                cnt++;
                if (u != root || cnt > 1) iscut[u] = 1;
                dcc_cnt++;
                int x;
                do {
                    x = s.top(); s.pop();
                    dccno[x] = dcc_cnt;
                    dcc[dcc_cnt].push_back(x);
                    nw[dcc_cnt] = min(nw[dcc_cnt], w[x]);
                } while (x != v);
                dccno[u] = dcc_cnt;
                dcc[dcc_cnt].push_back(u);
                nw[dcc_cnt] = min(nw[dcc_cnt], w[u]);
            }
        } else low[u] = min(low[u], dfn[v]);
    }
    //printf("%d dfn=%d low=%d\n", u, dfn[u], low[u]);
}

int vis[N], ans[N];
void dfs(int u, int minw) {
    vis[u] = 1;
    ans[u] = minw;
    //printf("->%d, minw = %d\n", u, minw);
    for (auto v:nG[u]) {
        if (!vis[v]) dfs(v, min(minw, nw[v]));
    }
}
/*
7 6 7
-1 -2 -1 -3 -2 -4 -2 -5 -3 -6 -3 -7
7 6 5 4 3 2 1
1 2 3 4 5 6 7
 */

void print_dcc_content() {
    for (int i = 1; i <= dcc_cnt; i++) {
        cout << i << ":";
        for (auto u:dcc[i])
            cout << u << " ";
        printf("nw=%d\n", nw[i]);
    }
}

void print_dccno() {
    for (int i = 1; i <= n; i++)
        cout << dccno[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(nw, 0x3f, sizeof nw);
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u = -u; v = -v;
        //e[i] = {u, v};
        G[u].push_back(v); G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    root = 1;
    tarjan(1);

    for (int i = 1; i <= n; i++) {
        if (iscut[i]) {
            dcc_cnt++;
            dccno[i] = dcc_cnt;
            dcc[dcc_cnt].push_back(i);
            nw[dcc_cnt] = min(nw[dcc_cnt], w[i]);
        }
    }

    for (int i = 1; i <= dcc_cnt; i++) {
        for (auto u:dcc[i]) {
            if (iscut[u]) {
                nG[dccno[u]].push_back(i);
                nG[i].push_back(dccno[u]);
            }
        }
    }
    //缩点后的图由 割点 和 点双 两部分组成
    //点双有性质：任意两点间都存在至少两条简单路径，并且这两条路径不经过相同的点。
    //print_dcc_content();
    //print_dccno();
    /*
    for (int i = 1; i <= m; i++) {
        int u = dccno[e[i].u], v = dccno[e[i].v];
        nG[u].push_back(v); nG[v].push_back(u);
    }
    */
    dfs(dccno[1], nw[dccno[1]]);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) cout << w[1] << "\n";
        else cout << ans[dccno[t]] << "\n";
    }
    return 0;
}



