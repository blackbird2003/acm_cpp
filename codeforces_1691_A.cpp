//
// Created by vv123 on 2022/5/31.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

void solve() {
    int n, t, cnt[2] = {0, 0};
    cin >> n;
    while (n--) {
        cin >> t;
        cnt[t % 2]++;
    }
    cout << min(cnt[0], cnt[1]) << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}