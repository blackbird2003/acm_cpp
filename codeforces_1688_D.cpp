//
// Created by vv123 on 2022/6/3.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;
int a[N], t[N], cnt[26];
void solve() {
    int n, k, sum = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int ans = 0;
    if (k > n + 3) ans = (k - 3) * n + sum;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

