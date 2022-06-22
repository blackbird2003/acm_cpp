//
// Created by vv123 on 2022/6/12.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long LL;
LL n, m, q, a[N], sum[N];
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n, greater<>());
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << sum[x] - sum[x - y] << "\n";
    }
}
//5 5 3 2 1 [x-y+1,x]

int main() {
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
