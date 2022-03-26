//
// Created by vv123 on 2022/3/6.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N];
void solve() {
    long long sum = 0;
    int mx = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum += a[i], mx = max(mx, a[i]);
    if (mx == 0) puts("0");
    else if (mx > sum - mx + 1) cout << 1 + mx - (sum - mx + 1) << "\n";
    else puts("1");
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
