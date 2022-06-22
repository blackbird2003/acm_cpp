//
// Created by vv123 on 2022/4/6.
//
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
vector<int> g[N];
stack<int> s;
int n, m, vis[N], ins[N], colorNum, colorSize[N], color[N];
int dfn[N], low[N], dfnn;

inline void paint(int x) {
    cout << "paint" << x << " in color" << colorNum << "\n";
    s.pop(); ins[x] = 0;
    color[x] = colorNum;
    colorSize[colorNum]++;
}

void tarjan(int u) {
    cout << "->" << u << " dfn=" << dfnn+1 << endl;
    dfn[u] = low[u] = ++dfnn;
    s.push(u); ins[u] = vis[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!dfn[v]) {  //前向边
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (ins[v])    //后向边（排除横叉边）
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        colorNum++;
        while(s.top() != u) {
            int x = s.top();
            paint(x);
        }
        paint(u);
        cout << "--------------block " << colorNum << ",size=" << colorSize[colorNum] << "-------------------\n";
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u != v) g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) tarjan(i);
    }
    int ans = 0;
    for (int i = 1; i <= colorNum; i++) {
        if (colorSize[i] > 1) ans++;
    }
    cout << ans << endl;
    return 0;
}

