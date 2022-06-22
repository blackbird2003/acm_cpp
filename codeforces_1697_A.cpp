//
// Created by vv123 on 2022/6/12.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long LL;
int n, m, a[N];
void solve() {
    LL sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    LL ans = max(0ll, sum - m);
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
