//
// Created by vv123 on 2022/5/2.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    if (y % x) puts("0 0");
    else cout << "1 " << y / x << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
