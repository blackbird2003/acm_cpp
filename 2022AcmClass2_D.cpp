//
// Created by vv123 on 2022/3/5.
//
#include <bits/stdc++.h>
using namespace std;
int n, m;
long long dp[20][20], s[20];
int main() {
    cin >> n >> m;
    dp[0][1] = 1;
    s[0] = 1;
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i <= n; i++) {
            dp[k][i] = s[k - 1] - dp[k - 1][i];
            s[k] += dp[k][i];
        }
    }
    cout << dp[m][1];
    return 0;
}

