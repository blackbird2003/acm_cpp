//
// Created by vv123 on 2022/4/11.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
vector<int> G[N], bcc[N];
int n, m, dfs_clock, cut_cnt, bridge_cnt, bcc_cnt, bcc_maxsize;
int pre[N], post[N], bccno[N], iscut[N], isbridge[N][N];

struct Edge { int u, v; };
stack<Edge> S;

int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock, child = 0;
    for (auto v:G[u]) {
        Edge e = {u, v};
        if (!pre[v]) {
            S.push(e); child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) {
                iscut[u] = true; //cut_cnt++;是错误的， 因为一个点会被多次判定为割点,割边同理。
                if (lowv > pre[u]) isbridge[u][v] = isbridge[v][u] = true;
                bcc_cnt++; bcc[bcc_cnt].clear();
                int edge_cnt = 0;
                for(;;) {
                    Edge x = S.top(); S.pop(); edge_cnt++;
                    if (bccno[x.u] != bcc_cnt)
                        bccno[x.u] = bcc_cnt, bcc[bcc_cnt].push_back(x.u);
                    if (bccno[x.v] != bcc_cnt)
                        bccno[x.v] = bcc_cnt, bcc[bcc_cnt].push_back(x.v);
                    if (x.u == u && x.v == v) {
                        bcc_maxsize = max(bcc_maxsize, edge_cnt);
                        break;
                    }
                }
            }
        } else if (pre[v] < pre[u] && v != fa) {
            S.push(e);
            lowu = min(lowu, pre[v]);
        }
    }
    if (fa < 0 && child == 1) iscut[u] = 0;
    return lowu;
}

inline void find_bcc() {
    dfs_clock = bcc_cnt = 0;
    for (int i = 1; i <= n; i++)
        if (!pre[i]) dfs(i, -1);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    find_bcc();
    for (int i = 1; i <= n; i++)
        if (iscut[i]) cut_cnt++;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (isbridge[i][j]) bridge_cnt++;
    printf("%d %d %d %d\n", cut_cnt, bridge_cnt, bcc_cnt, bcc_maxsize);
    return 0;
}
