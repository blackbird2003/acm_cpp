//
// Created by vv123 on 2022/6/3.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int lb = n & -n;
    if (n != lb) cout << lb << "\n";
    else if (lb != 1) cout << (lb | 1) << "\n";
    else cout << 3 << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
