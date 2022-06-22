//
// Created by vv123 on 2022/5/31.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void solve() {
    int n, k, ans = 0;
    string s;
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }
    if (a[n] != 1) {
        for (int i = n - 1; i >= 1; i--) {
            if (n - i > k) break;
            if (a[i] == 1) {
                k -= (n - i);
                swap(a[i], a[n]);
                break;
            }
        }
    }
    if (a[1] != 1) {
        for (int i = 1; i <= n - 1; i++) {
            if (i - 1 > k) break;
            if (a[i] == 1) {
                k -= (i - 1);
                swap(a[1], a[i]);
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == 1) ans += a[i] * 10;
        else if (i < n) ans += a[i] * 11;
        else ans += a[i];
    }
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


