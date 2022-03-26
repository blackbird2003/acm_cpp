//
// Created by vv123 on 2022/3/1.
//
#include <bits/stdc++.h>
#define init() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
const int mod = 10007;
const int N = 1e5 + 10;
int n, m, a[N], b[N];
int cnt[N][2], sind[N][2];
int main() {
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        cnt[b[i]][i % 2] ++;
        sind[b[i]][i % 2] = (sind[b[i]][i % 2] + i) % mod;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += i * a[i] * (cnt[b[i]][i % 2] - 1) % mod;
        ans += (sind[b[i]][i % 2] - i) * a[i] % mod;
        ans %= mod;
    }
    cout << ans << "\n";
    return 0;
}