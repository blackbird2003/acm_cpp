//
// Created by vv123 on 2022/4/20.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

vector<int> G[N], bcc[N];
int n, m, q, w[N], dfs_clock, cut_cnt, bridge_cnt, bcc_cnt, bcc_maxsize, neww[N];
int pre[N], post[N], bccno[N], iscut[N], ans[N], ans2[N];

struct Edge { int u, v; } e[N];
stack<Edge> S;

//这里把J题的板子直接粘过来了,不过有些内容是多余的
int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock, child = 0;
    printf("%d:%d\n", u, dfs_clock);
    for (auto v:G[u]) {
        Edge e = {u, v};
        if (!pre[v]) {
            S.push(e); child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) {
                iscut[u] = true; //cut_cnt++;是错误的， 因为一个点会被多次判定为割点
                //if (lowv > pre[u]) isbridge[u][v] = isbridge[v][u] = true;
                bcc_cnt++; bcc[bcc_cnt].clear();
                printf("u:%d v:%d bcc_cnt:%d\n", u, v, dfs_clock);
                int edge_cnt = 0;
                for(;;) {
                    Edge x = S.top(); S.pop(); edge_cnt++;
                    if (bccno[x.u] != bcc_cnt)
                        bccno[x.u] = bcc_cnt, bcc[bcc_cnt].push_back(x.u), printf("bccno[%d]=%d\n", x.u, bcc_cnt);
                    if (bccno[x.v] != bcc_cnt)
                        bccno[x.v] = bcc_cnt, bcc[bcc_cnt].push_back(x.v), printf("bccno[%d]=%d\n", x.v, bcc_cnt);
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

void solve(int u, int fa, int minw) {
    printf("%d %d\n", u, minw);
    ans[u] = min(ans[u], minw);
    for (auto v:G[u]) {
        if (v == fa) continue;
        solve(v, u, min(minw, neww[v]));
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u = -u; v = -v;
        e[i] = {u, v};
        G[u].push_back(v); G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    find_bcc();

    bccno[1] = ++bcc_cnt;
    bcc[bcc_cnt].push_back(1);

    memset(neww, 0x3f, sizeof neww);//处理新图的点权，同一个点双内的点权用最小点权代替
    for (int i = 1; i <= n; i++) neww[bccno[i]] = min(neww[bccno[i]], w[i]);

    for (int i = 1; i <= bcc_cnt; i++) G[i].clear();
    for (int i = 1; i <= m; i++) {
        int u = bccno[e[i].u], v = bccno[e[i].v];
        if (u != v) {
            G[u].push_back(v); G[v].push_back(u);
        }
    }
    memset(ans, 0x3f, sizeof ans);
    int s = bccno[1];
    solve(s, 0, neww[s]);

    while (q--) {
        int t;
        cin >> t;
        cout << ans[t] << "\n";
    }
    return 0;
}
