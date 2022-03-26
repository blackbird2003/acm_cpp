//
// Created by vv123 on 2022/3/22.
//
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n; string s;
    stack<char> r;
    cin >> n >> s;
    int ans = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (i == pos) continue;
        if (s[pos] == '(') {
            ans++;
            pos = i + 1;
            //printf("%d\n", pos);
        }
        else if (s[i] == ')') {
            ans++;
            pos = i + 1;
        }
    }
    cout << ans << " " << n - pos << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}

