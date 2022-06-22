//
// Created by vv123 on 2022/5/1.
//
#include <bits/stdc++.h>
using namespace std;
int n, m, a[10004];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        ans += a[u];
    }
    cout << ans << endl;
    return 0;
}
