<<<<<<< HEAD
//
// Created by vv123 on 2022/2/22.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5010;
int dp[N], t[N], f[N], q[N], s, n, l, r;
signed main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> f[i];
        t[i] += t[i - 1];
        f[i] += f[i - 1];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    //维护一段斜率单调增的折线
    //一个斜率单增的直线取最小截距，排除斜率小于它的折线段，每次从队首转移
    l = 1, r = 0;
    q[0] = 0, r++;
    for (int i = 1; i <= n; i++) {
        while (l < r && (s + t[i]) * (f[q[l+1]] - f[q[l]]) >= dp[q[l+1]] - dp[q[l]]) l++;
        dp[i] = dp[q[l]] + t[i] * f[i] + s * f[n] - (s + t[i]) * f[q[l]];
        while (l < r && (dp[i] - dp[q[r]]) * (f[q[r]] - f[q[r-1]]) <= (dp[q[r]] - dp[q[r-1]]) * (f[i] - f[q[r]])) r--;
        q[++r] = i;
    }
    cout << dp[n] << endl;
    return 0;
}

=======
//
// Created by vv123 on 2022/2/22.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5010;
int dp[N], t[N], f[N], q[N], s, n, l, r;
signed main() {
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> f[i];
        t[i] += t[i - 1];
        f[i] += f[i - 1];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    //维护一段斜率单调增的折线
    //一个斜率单增的直线取最小截距，排除斜率小于它的折线段，每次从队首转移
    l = 1, r = 0;
    q[0] = 0, r++;
    for (int i = 1; i <= n; i++) {
        while (l < r && (s + t[i]) * (f[q[l+1]] - f[q[l]]) >= dp[q[l+1]] - dp[q[l]]) l++;
        dp[i] = dp[q[l]] + t[i] * f[i] + s * f[n] - (s + t[i]) * f[q[l]];
        while (l < r && (dp[i] - dp[q[r]]) * (f[q[r]] - f[q[r-1]]) <= (dp[q[r]] - dp[q[r-1]]) * (f[i] - f[q[r]])) r--;
        q[++r] = i;
    }
    cout << dp[n] << endl;
    return 0;
}

>>>>>>> eb78ae3d1fc2d4b02f3e542cfe861cef6d785780
