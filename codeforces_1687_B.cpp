//
// Created by vv123 on 2022/3/11.
//
//
// Created by vv123 on 2022/3/11.
//
#include <bits/stdc++.h>
using namespace std;

char g[110][110];
inline void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    bool ans = true;
    for (int i = 2; i <= n; i++) {
        bool sp1 = false, equal = true;
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1' && g[i-1][j] == '1') sp1 = true;
            if (g[i][j] != g[i-1][j]) equal = false;
        }
        if (sp1 && !equal) {
            ans = false;
            break;
        }
    }
    ans ? puts("Yes") : puts("No");
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}


