//
// Created by vv123 on 2022/6/14.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, b[N];
void solve() {
    memset(b, 0, sizeof b);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        b[t]++;
    }
    while (1) {
        int mx = 0, mxid = 0;
        for (int i = 1; i <= 10000; i++) {
            if (b[i] > mx) {
                mx = b[i];
                mxid = i;
            }
        }
        if (mx <= 1) break;
        b[mxid]--;
        mx = 0, mxid = 0;
        for (int i = 1; i <= 10000; i++) {
            if (b[i] > mx) {
                mx = b[i];
                mxid = i;
            }
        }
        b[mxid]--;
    }
    int ans = 0;
    for (int i = 1; i <= 10000; i++)
        if (b[i]) ans++;
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}


