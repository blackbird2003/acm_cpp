//
// Created by vv123 on 2022/3/6.
//
#include <bits/stdc++.h>
using namespace std;
int n, a[110];
void solve() {
    cin >> n;
    int l = 0, r = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            r = i;
            if (l == 0) l = i;
        }
    }
    //cout << l << "," << r << endl;
    if (!l && !r) puts("0");
    else cout << r - l + 2 << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
