//
// Created by vv123 on 2022/6/3.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;
int a[N], t[N], cnt[26];
void solve() {
    memset(cnt, 0, sizeof cnt);
    int n;
    cin >> n;
    string s;
    for (int i = 1; i <= n * 2 + 1; i++) {
        cin >> s;
        for (auto ch:s) cnt[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2) {
            cout << (char)('a' + i) << "\n";
            return;
        }
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

