//
// Created by vv123 on 2022/4/9.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 0x3f3f3f3f;
int n, m;

struct Edge {
    int from, to, cap, flow;
};

struct Dinic {
    int s, t;
    bool vis[N];
    int d[N];
    int cur[N];

    vector<Edge> edges;
    vector<int> G[N];
    void AddEdge(int from, int to, int cap) {
        edges.push_back({from, to, cap, 0});
        //edges.push_back({to, from, 0, 0); 如果是有向图.
        edges.push_back({to, from, cap, 0});
        G[from].push_back(edges.size() - 2);
        G[to].push_back(edges.size() - 1);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = 1;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            for (int i = 0; i < G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                int v = e.to;
                if (!vis[v] && e.cap > e.flow) {
                    vis[v] = 1;
                    d[v] = d[u] + 1;
                    Q.push(v);
                }
            }
        }
        return vis[t];
    }

    int DFS(int u, int a) {
        if (u == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[u]; i < G[u].size(); i++) {   //这里取引用，使得u的当前弧被i改变，再次访问到u时，将跳过u已经访问过的支路
            Edge& e = edges[G[u][i]], ee = edges[G[u][i] ^ 1];
            int v = e.to;
            if (d[v] == d[u] + 1 && (f = DFS(v, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                ee.flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int Maxflow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
};

int x[N], y[N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    int ans = INF;
    int s = 1;
    for (int t = 2; t <= n; t++) {
        Dinic dc;
        for (int i = 1; i <= m; i++)
            dc.AddEdge(x[i], y[i], 1);
        ans = min(ans, dc.Maxflow(s, t));
    }
    printf("%d\n", ans);
    return 0;
}

