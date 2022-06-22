//
// Created by vv123 on 2022/4/21.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
vector<int> G[N], dcc[N];
int n, m, dfs_clock, dfn[N], low[N], dcc_cnt, iscut[N], dccno[N], root;
stack<int> s;

vector<int> nG[N];
int nw[N];
struct Edge {
    int u, v;
} e[N];

int siz[N], ok[N];

void tarjan(int u) {
    siz[u] = 1;
    dfn[u] = low[u] = ++dfs_clock;
    s.push(u);
    /*
    if (u == root && G[u].empty()) {
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }
     */
    int cnt = 0;//分支数量
    for (auto v : G[u]) {
        if (!dfn[v]) {
            tarjan(v);
            siz[u] += siz[v];
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v]) {
                //printf("%d-%d\n", u, v);
                if (siz[v] % 2 == 1) ok[u] = 0;
                cnt++;
                if (u != root || cnt > 1) iscut[u] = 1;
                dcc_cnt++;
                int x;
                do {
                    x = s.top(); s.pop();
                    dccno[x] = dcc_cnt;
                    dcc[dcc_cnt].push_back(x);
                } while (x != v);
                dccno[u] = dcc_cnt;
                dcc[dcc_cnt].push_back(u);
            }
        } else low[u] = min(low[u], dfn[v]);
    }
    //if ((n - siz[u]) % 2 == 1) ok[u] = 0;
    //printf("%d dfn=%d low=%d\n", u, dfn[u], low[u]);
}


/*
7 6 7
-1 -2 -1 -3 -2 -4 -2 -5 -3 -6 -3 -7
7 6 5 4 3 2 1
1 2 3 4 5 6 7
1 7 6
1 2 3 4 5 6 7
1 2 1 3 2 4 2 5 3 6 3 7
 */

void print_dcc_content() {
    for (int i = 1; i <= dcc_cnt; i++) {
        cout << i << ":";
        for (auto u:dcc[i])
            cout << u << " ";
        printf("nw=%d\n", nw[i]);
    }
}

void print_dccno() {
    for (int i = 1; i <= n; i++)
        cout << dccno[i] << " ";
    cout << endl;
}

void print_size() {
    for (int i = 1; i <= n; i++)
        cout << siz[i] << " ";
    cout << endl;
}

struct node {
    int w, id;
}a[N];

bool cmp(node x, node y) {
    if (x.w != y.w) return x.w < y.w;
    if (iscut[x.id] != iscut[y.id]) return iscut[x.id] < iscut[y.id];
    return x.id < y.id;
}

void init() {
    dfs_clock = dcc_cnt = 0;
    for (int i = 1; i <= n; i++) {
        ok[i] = 1;
        G[i].clear();
        dcc[i].clear();
        dfn[i] = iscut[i] = dccno[i] = 0;
    }
    while (!s.empty()) s.pop();
}


int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int T;
    //cin >> T;
    scanf("%d", &T);
    while (T--) {
        //cin >> n >> m;
        scanf("%d%d", &n, &m);
        init();
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i].w);
            ans += a[i].w;
            a[i].id = i;
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].push_back(v); G[v].push_back(u);
        }

        if (n % 2 == 0) {
            printf("%lld\n", ans);
            continue;
        }

        root = 1;
        tarjan(1);
        //print_size();


        sort(a + 1, a + 1 + n, cmp);
        for (int i = 1; i <= n; i++) {
            if (!iscut[a[i].id] || (iscut[a[i].id] && ok[a[i].id])) {
                printf("%lld\n", ans - 2 * a[i].w);
                //cout << ans - 2 * a[i].w << endl;
                break;
            }
        }
    }
    return 0;
}