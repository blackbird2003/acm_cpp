//
// Created by vv123 on 2022/4/10.
//
//我们如果Au-Av<=w,我们连一条从u到v权值为w的边。
//我们从最简单的情况开始考虑，两个点显然有解
//加入第三个点时，如果和前两个点之间没有成环，
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
struct Edge {
    int u, v, w;
};
struct BellmanFord {
    int n, m;
    vector<Edge> edges;
    vector<int> G[N];
    void AddEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
        G[u].push_back(edges.size() - 1);
    }

    int d[N], p[N], cnt[N], inq[N];
    bool negativeCycle() {
        queue<int> Q;
        for (int i = 1; i <= n; i++) Q.push(i);
        d[0] = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                int v = e.v, w = e.w;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    p[v] = G[u][i];
                    if (!inq[v]) {
                        Q.push(v);
                        inq[v] = 1;
                        if (++cnt[v] > n) return true;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    BellmanFord bf;
    cin >> bf.n >> bf.m;
    for (int i = 1; i <= bf.m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        bf.AddEdge(u, v, w);
    }
    bf.negativeCycle() ? puts("NO") : puts("YES");
    return 0;
}
