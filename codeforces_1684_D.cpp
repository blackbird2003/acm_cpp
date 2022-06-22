//
// Created by vv123 on 2022/5/20.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N], n, k;
void solve() {
    cin >> n >> k;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
        b[i] = a[i] + i - n;
    }
    sort(b + 1, b + 1 + n, greater<>());
    for (int i = 1; i <= k; i++) {
        ans -= b[i];
    }
    ans -= (long long) k * (k - 1) / 2;
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
