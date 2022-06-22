//
// Created by vv123 on 2022/4/11.
//
//引理1：MST上每种权值的边数是一定的。可以这样考虑：根据Kruskal算法的流程，如果在求好的MST上，权值为x的边还能再多一个，那一定会在求的过程中算入这条边。
//引理2：不同的生成树中某一种权值的边连接完成后,形成的联通块状态是一样的。可以这样考虑：我们可以把n选m等效为连上n个后拆掉(n-m)个使图中无环，但这不会改变联通性。
//因此，“连接每种权值的边”是一个相对独立的过程，我们可以分别对每种权值的边计算方案数。
//引理3：矩阵树定理：基尔霍夫矩阵K=D-A的任意一个余子式的行列式等于生成树个数,D是度数矩阵,A是邻接矩阵
//因此，对每种w，我们断开MST上所有权值w的边，把剩下的连通块当作点，然后连上所有权值w的边，利用Matrix Tree算法求出生成树个数，答案即为所有w对应的结果相乘。注意到w的值域很小，行列式最多算十次，是可以接受的。
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 110;
const int M = 1010;
const int mod = 10000;

int n, m, f[N], id[N], cnt, used[M], a[N][N], used_w[11];
long long ans = 1;

void init() { for (int i = 1; i <= n; i++) f[i] = i; }
int find(int x) { return x == f[x] ? f[x] : f[x] = find(f[x]); }
int merge(int x, int y) { return find(x) == find(y) ? 0 : f[find(x)] = find(y);}

struct Edge {
    int u, v, w;
    bool operator < (const Edge& x) const {
        return w < x.w;
    }
} e[M];

bool kruskal() {
    init(); int cnt = 0;
    sort(e + 1, e + 1 + m);
    for (int i = 1; i <= m; i++) {
        if (merge(e[i].u, e[i].v)) {
            cnt++;
            used[i] = 1;
            used_w[e[i].w] = 1;
        }
        if (cnt == n - 1) break;
    }
    return cnt == n - 1;
}

inline int det(int n) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] %= mod;
    int res = 1;
    for (int i = 1; i <= n; i++) {
        int p = i;
        for (int j = i + 1; j <= n; j++)
            if (abs(a[j][i])) p = j;
        for (int j = 1; j <= n; j++) swap(a[p][j],a[i][j]);
        if (p != i) res *= -1;
        for (int j = i + 1; j <= n; j++)
            while (a[j][i]) {
                int t = a[j][i] / a[i][i];
                for (int k = 1; k <= n; k++)
                    a[j][k] = (a[j][k] - t * a[i][k]) % mod;
                if (!a[j][i]) break;
                res *= -1;
                for (int k = 1;k <= n; k++) swap(a[i][k],a[j][k]);
            }
        res = (res * a[i][i]) % mod;
    }
    return (res % mod + mod) % mod;
}

void print() {
    for (int i = 1; i <= n; i++)
        cout << find(i) << " "; puts("");
}

inline void work(int w) {
    init(); cnt = 0;
    for (int i = 1; i <= m; i++)
        if (used[i] && e[i].w != w)
            merge(e[i].u, e[i].v);
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            id[i] = ++cnt;
    for (int i = 1; i <= n; i++)
        id[i] = id[find(i)];
    for (int i = 1; i <= m; i++) {
        if (e[i].w == w && id[e[i].u] != id[e[i].v]) {
            int u = id[e[i].u], v = id[e[i].v];
            a[u][u]++; a[v][v]++;
            a[u][v]--; a[v][u]--;
        }
    }/*
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= cnt; j++)
            printf("%5d ", a[i][j]);
        puts("");
    }*/
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    if (!kruskal()) { puts("0"); return 0; }

    for (int i = 1; i <= 10; i++) {
        if (!used_w[i]) continue;
        memset(a, 0, sizeof a);
        work(i);
        ans = ans * det(cnt - 1) % mod;
    }
    cout << ans << endl;
    return 0;
}


