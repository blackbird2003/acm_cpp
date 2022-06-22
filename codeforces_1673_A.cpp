//
// Created by vv123 on 2022/4/30.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], sum[N];
inline void solve() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - 'a' + 1;
        sum[i] = sum[i - 1] + a[i];
    }
    if (n % 2 == 0) {
        cout << "Alice " << sum[n] << "\n";
    } else {
        int t1 = sum[n - 1] - a[n], t2 = sum[n] - 2 * a[1];
        if (t1 < 0 && t2 < 0)
            cout << "Bob " << -min(t1, t2) << "\n";
        else
            cout << "Alice " << max(t1, t2) << "\n";
    }

}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
