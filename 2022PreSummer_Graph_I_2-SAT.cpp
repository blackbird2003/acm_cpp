//
// Created by vv123 on 2022/4/10.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

class TwoSAT {
    int n, m;
    vector<int> G[N << 1];
    int S[N << 1], c;
    bool mark[N << 1];
public:
    TwoSAT(int N, int M) : n(N), m(M) {}
    bool dfs(int u) {
        if (mark[u^1]) return false;
        if (mark[u]) return true;
        mark[u] = 1;
        S[c++] = u;
        for (auto v:G[u])
            if (!dfs(v)) return false;
        return true;
    }

    void AddORClause(int u, int x, int v, int y) {
        u = u << 1 | x, v = v << 1 | y;
        G[u^1].push_back(v); G[v^1].push_back(u);
    }

    bool solve() {
        for (int i = 0; i < n * 2; i += 2) {
            if (!mark[i] && !mark[i + 1]) {
                c = 0;
                if (!dfs(i)) {
                    while (c > 0) mark[S[--c]] = 0;
                    if (!dfs(i + 1)) return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    TwoSAT *ts = new TwoSAT(n, m);
    for (int i = 1; i <= m; i++) {
        int u, x, v, y;
        cin >> u >> x >> v >> y;
        ts->AddORClause(u - 1, x, v - 1, y);   //下标从0开始
    }
    ts->solve() ? puts("YES") : puts("NO");
    return 0;
}

