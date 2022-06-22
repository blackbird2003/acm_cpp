//
// Created by vv123 on 2022/5/4.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    int ans = n * m - 1;
    n -= n & -n, m -= m & -m;
    if (!n || !m) {
        cout << ans << endl;
    } else cout << ans + (1 << (min(n, m) - 1)) << endl;
}
signed main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
