//
// Created by vv123 on 2022/4/12.
//
//我们可以把每一个对角线当成它所连接的两个点之间有一条长度为0的路径
//自然，另一种对角线的路径设为1，用dijkstra求(1，1)到(n+1,m+1)的最短路即可
//并且，
//边数只有2N，复杂度可以看做O(NlogN)，N为n*m
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;

struct Edge { int v, w; };
vector<Edge> G[N];
inline void addEdge(int u, int v, int w) {
    G[u].push_back({v, w});
    G[v].push_back({u, w});
}
int n, m, s, d[N], vis[N];
//我们将二维中的点(i,j)标号为(m + 1) * (i - 1) + j
inline int mark(int i, int j) {
    return (m + 1) * (i - 1) + j;
}

inline void dijkstra(int s) {
    priority_queue<pair<int, int> > q;
    memset(d, 0x3f, sizeof d);
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
}
/*
HACK
3 4
\\/\
\/\/
//\\
*/
int main() {
    cin >> n >> m;
    char s[N];
    for (int i = 1; i <= n; i++) {
        cin >> s + 1;
        //cout << s + 1 << endl;
        for (int j = 1; j <= m; j++) {
            //cout << s[j] << endl;
            //printf("%d-%d:%d\n", mark(i, j), mark(i + 1, j + 1), s[j] != '\\');
            //printf("%d-%d:%d\n", mark(i + 1, j), mark(i, j + 1), s[j] != '/');
            addEdge(mark(i, j), mark(i + 1, j + 1), s[j] != '\\');
            addEdge(mark(i + 1, j), mark(i, j + 1), s[j] != '/');
        }
    }
    dijkstra(mark(1, 1));
    if (d[mark(n + 1, m + 1)] >= INF) puts("NO SOLUTION");
    else cout << d[mark(n + 1, m + 1)] << endl;
    return 0;
}
