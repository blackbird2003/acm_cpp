//
// Created by vv123 on 2022/5/21.
//
#include <bits/stdc++.h>
#define clr(a) memset(a,0,sizeof(a))
using namespace std;
const int N = 1e4 + 10, M = 2e6 + 10;
int n, tr[N * 55][26], pos[N * 55], idx, q[N * 55], ne[N * 55];
char s[M];

void insert(int t) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
    }
    pos[t] = p;
}

void build() {
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (tr[0][i]) q.push(tr[0][i]);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < 26; i++) {
            int p = tr[u][i];
            if (!p) tr[u][i] = tr[ne[u]][i];
            else {
                ne[p] = tr[ne[u]][i];
                q.push(p);
            }
        }
    }
}
int ans[N];
void solve() {
    int res = 0;
    for (int i = 0, j = 0; s[i]; i++) {
        int u = s[i] - 'a';
        j = tr[j][u];
        int p = j;
        while (p) {
            ans[n] += cnt[p];
            cnt[p] = 0;
            p = ne[p];
        }
    }
    cout << res << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> s; insert(i); }
    build();
    cin >> s;
    solve();
    return 0;
}

