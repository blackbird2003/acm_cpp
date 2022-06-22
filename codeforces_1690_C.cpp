//
// Created by vv123 on 2022/6/7.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], b[N], ans[N];
void solve() {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = n; i >= 1; i--) {
        ans[i] = b[i] - max(a[i], b[i - 1]);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    puts("");
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

