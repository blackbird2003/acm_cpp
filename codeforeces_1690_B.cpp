//
// Created by vv123 on 2022/6/7.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], b[N], da[N], db[N];
void solve() {
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        mx = max(mx, a[i] - b[i]);
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        a[i] = max(0, a[i] - mx);
        if (a[i] != b[i]) {
            flag = false;
            break;
        }
    }
    flag ? puts("Yes") : puts("No");
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

