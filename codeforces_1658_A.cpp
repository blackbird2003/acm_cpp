//
// Created by vv123 on 2022/3/27.
//
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    string s;
    vector<int> pos;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') pos.push_back(i);
    }
    int ans = 0;
    for (int i = 1; i < pos.size(); i++) {
        int t = pos[i] - pos[i - 1] - 1;
        if (t < 2) ans += 2 - t;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
