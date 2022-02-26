//
// Created by vv123 on 2022/2/23.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N], n;
void solve() {
    cin >> n;
    int ans = 0;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] == 1) ans++;
    }
    vector<int> b;
    for (auto i : mp)  b.push_back(i.second - 1);
    sort(b.begin(), b.end(), greater<int>());
    for (int i = 0; i < b.size(); i++) printf("%d ", ans);
    for (int i = 0; i < b.size(); i++) {
        //printf("#%d:%d\n", i, b[i]);
        for (int j = 0; j < b[i]; j++) {
            ans++;
            printf("%d ", ans);
        }
    }
    puts("");
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
