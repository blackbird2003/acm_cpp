//
// Created by vv123 on 2022/5/19.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int M[N][N], W[N][N], sum[N], n, mod;
void solve() {
    M[1][1] = W[1][1] = 1; sum[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            W[i][j] = sum[j - 1];
        }
        for (int j = 1; j <= i; j++) {
            M[i][j] = W[i][i - j + 1];
        }
        for (int j = 1; j <= i; j++) {
            sum[j] = (sum[j - 1] + M[i][j]) % mod;
        }
    }
    long long ans = 0;
    for (int j = 1; j <= n; j++)
        ans = (ans + W[n][j] + M[n][j]) % mod;
    cout << ans << endl;
}

int main() {
    cin >> n >> mod;
    solve();
    return 0;
}
