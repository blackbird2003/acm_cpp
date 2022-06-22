//
// Created by vv123 on 2022/4/30.
//
//bababcb
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], sum[27], vis[27], lst[27];

inline void solve() {
    memset(lst, 0, sizeof lst);
    memset(vis, 0, sizeof vis);
    int num = 0;
    string s;
    cin >> s;
    int n = s.length();
    for (auto c:s) {
        int t = c - 'a' + 1;
        if (!vis[t]) num++, vis[t] = 1;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - 'a' + 1;
        if (lst[a[i]] && i - lst[a[i]] - 1 < num - 1) {
            puts("NO");
            return;
        }
        lst[a[i]] = i;
    }
    puts("YES");
    return;
}
int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
