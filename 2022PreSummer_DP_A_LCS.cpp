//
// Created by vv123 on 2022/5/17.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
long long n, m, x, y, z, dp[N][N];
char A[N], B[N];
void solve() {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(max(dp[i - 1][j] - y, dp[i][j - 1] - z), dp[i - 1][j - 1] - y - z);
            if (A[i] == B[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + x - y - z);
            dp[i][j] = max(dp[i][j], -y - z);
            if (A[i] == B[j]) dp[i][j] = max(dp[i][j], x - y - z);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m >> x >> y >> z >> A + 1 >> B + 1;
    solve();
    return 0;
}