//
// Created by vv123 on 2022/5/17.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int f1[N], f2[N], n;
vector<int> g[N];
void dfs1(int u, int fa) {
    //printf("u=%d\n", u);
    for (auto v : g[u]) {
        if (v != fa) dfs1(v, u);
    }
    for (auto v : g[u]) {
        if (v == fa) continue;
        if (f1[v] >= 0) f1[u] += f1[v];
        //printf("f1[%d] += f1[%d] become %d\n", u, v, f1[u]);
    }
}

void dfs2(int u, int fa) {
    if (!fa) f2[u] = f1[u];
    else {
        if (f1[u] < 0) f2[u] = max(f1[u], f2[fa] + f1[u]);
        else f2[u] = max(f1[u], f2[fa]);
    }
    for (auto v : g[u]) {
        if (v != fa) dfs2(v, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        f1[i] = t ? 1 : -1;
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        cout << f2[i] << " ";
    return 0;
}
