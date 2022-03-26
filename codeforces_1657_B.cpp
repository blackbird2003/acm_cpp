//
// Created by vv123 on 2022/3/22.
//
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n, b, x, y;
    cin >> n >> b >> x >> y;
    int t = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        t + x <= b ? t += x : t -= y;
        ans += t;
    }
    cout << ans << "\n";
}

int main() {

    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

