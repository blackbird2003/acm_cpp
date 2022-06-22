//
// Created by vv123 on 2022/4/10.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n, m, in[N];
vector<int> G[N];

inline bool findCircle() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!in[i]) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for(auto v:G[u]) {
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
    return cnt != n;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w >= 1) continue;
        G[u].push_back(v);
        in[v]++;
    }
    findCircle() ? puts("NO") : puts("YES");
    return 0;
}

