//
// Created by vv123 on 2022/5/7.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 50010;
int n, m, f[M], w[N], a[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + a[i]);
            ans = max(ans, f[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
