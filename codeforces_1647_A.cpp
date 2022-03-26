//
// Created by vv123 on 2022/3/11.
//
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    string ans = "";
    if (n % 3 == 0) {
        for (int i = 1; i <= n / 3; i++)
            ans += "21";
        cout << ans << "\n";
    } else if (n % 3 == 1) {
        ans += "1";
        for (int i = 1; i <= n / 3; i++)
            ans += "21";
        cout << ans << "\n";
    } else {
        for (int i = 1; i <= n / 3; i++)
            ans += "21";
        ans += "2";
        cout << ans << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
