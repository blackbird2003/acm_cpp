//
// Created by vv123 on 2022/6/7.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k, a[N], b[N], ans[N];
char s[N];
void solve() {
    cin >> n >> k >> s + 1;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i] == 'B' ? 1 : 0;
    }
    int sum = 0;
    for (int i = 1; i <= k - 1; i++) sum += a[i];
    int ans = k;
    for (int i = k; i <= n; i++) {
        sum = sum - a[i - k] + a[i];
        ans = min(ans, k - sum);
    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

