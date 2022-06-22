//
// Created by vv123 on 2022/5/19.
//
#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int minx = 10;
    for (auto ch : s) {
        int x = ch - '0';
        minx = min(minx, x);
    }
    if (s.length() == 2 && s[0] - '0' == minx && s[1] - '0' > minx)
        cout << s[1] << endl;
    else cout << minx << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
