//
// Created by vv123 on 2022/6/14.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], b[N], da[N], db[N];
void solve() {
    for (int i = 1; i <= 4; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 2; i <= 4; i++) {
        if (a[i] > a[1]) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}


