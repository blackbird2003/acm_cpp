//
// Created by vv123 on 2022/5/20.
//
#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N =  3010;
const int inf = 0x3f3f3f3f;
int n, m, s1, s2, s3, a[N], dp[N][N];
int dis(int i, int j) {
    return min(abs(i - j), m - abs(i - j));
}
signed main() {
    cin >> n >> m >> s1 >> s2 >> s3;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int p[6][3] = {
            {s1, s2, s3},
            {s1, s3, s2},
            {s2, s1, s3},
            {s2, s3, s1},
            {s3, s1, s2},
            {s3, s2, s1}
    };
    memset(dp, 0x3f, sizeof dp);
    for (int j = 1; j <= m; j++) {
        for (int k = 0; k < 6; k++) {
            dp[2][j] = min(dp[2][j], dis(a[1], p[k][0]) + dis(a[2], p[k][1]) + dis(j, p[k][2]));
            //printf("k=%d, dp[2][%d]=%d\n", k, j, dp[2][j]);
        }
        //for (int j = 1; j <= m; j++) printf("dp[%d][%d]=%d\n", 2, j, dp[2][j]);
        //printf("dp[2][%d]=%d\n", j, dp[2][j]);
    }
    int ans = inf;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + dis(a[i - 2], a[i]));
            dp[i][a[i - 2]] = min(dp[i][a[i - 2]], dp[i - 1][j] + dis(j, a[i]));
        }
        //for (int j = 1; j <= m; j++) printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
    }
    for (int j = 1; j <= m; j++)
        ans = min(ans, dp[n][j]);
    cout << ans << endl;
    return 0;
}

