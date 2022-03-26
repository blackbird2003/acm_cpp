//
// Created by vv123 on 2022/3/6.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 2e3 + 10;
int n, m, a[N], ans[N][N];

void tab() {
    for (int l = 1; l <= n; l++) {
        unordered_set<int> s;
        for (int r = l; r <= n; r++) {
            s.insert(a[r]);
            ans[l][r] = s.size();
        }
    }
}
int main() {
    io_optimization();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    tab();
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << ans[l][r] << "\n";
    }
    return 0;
}
