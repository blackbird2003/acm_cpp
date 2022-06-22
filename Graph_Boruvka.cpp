//
// Created by vv123 on 2022/4/19.
//
//点对之间

#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
const int M = 2e5 + 5;

int n, m, f[N], best[M], used[M];
struct Edge {
    int u, v, w;
}e[M];
//是否要用边x替换y
bool better(int x, int y) {
    if (y == 0) return true;
    if (e[x].w != e[y].w) return e[x].w < e[y].w;
    return x < y;
}
void init() { for (int i = 1; i <= n; i++) f[i] = i; }
int find(int x) { return x == f[x] ? f[x] : f[x] = find(f[x]); }
int merge(int x, int y) { return find(x) == find(y) ? 0 : f[find(x)] = find(y);}

int Boruvka() {
    init();
    int cnt = 0, res = 0;
    while (1) {
        bool flag = false;
        memset(best, 0, sizeof best);
        for (int i = 1; i <= m; i++) {
            if (used[i]) continue;
            int fu = find(e[i].u), fv = find(e[i].v);
            if (fu == fv) continue;
            if (better(i, best[fu])) best[fu] = i;
            if (better(i, best[fv])) best[fv] = i;
        }
        for (int i = 1; i <= n; i++) {
            if (best[i] && !used[best[i]]) {//每个连通块只有一个点拥有best[i]
                flag = true;
                cnt++;
                res += e[best[i]].w;
                used[best[i]] = 1;
                merge(e[best[i]].u, e[best[i]].v);
            }
        }
        if (!flag) break;
    }
    if (cnt == n - 1) return res;
    else return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    int ans = Boruvka();
    if (ans == -1) puts("orz");
    else cout << ans << endl;
    return 0;
}


