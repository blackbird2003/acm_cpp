//
// Created by vv123 on 2022/6/3.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f;
int a[N], t[N];
int work(int x) {
    if (x % 2 != 0) return 0;
    int res = 0;
    while (x % 2 == 0) {
        x /= 2;
        res++;
    }
    return res;
}
void solve() {
    int n, mint = inf, cnteven = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            cnteven++;
            t[i] = work(a[i]);
            mint = min(mint, t[i]);
        }
        //cout << t[i] << " ";
    }
    if (cnteven < n) mint = 1;
    if (cnteven == 0) puts("0");
    else cout << mint + cnteven - 1 << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

