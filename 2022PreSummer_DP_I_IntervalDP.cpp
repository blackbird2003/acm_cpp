//
// Created by vv123 on 2022/5/9.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int a[N], f[N][N], ans[N][N], n, q, l, r;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], f[i][i] = ans[i][i] = a[i];
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int l = i, r = i + len - 1;
            f[l][r] = f[l + 1][r] ^ f[l][r - 1];
        }
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int l = i, r = i + len - 1;
            ans[l][r] = max(f[l][r], max(ans[l + 1][r], ans[l][r - 1]));
        }
    }
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << ans[l][r] << endl;
    }
    return 0;
}
