//
// Created by vv123 on 2022/3/27.
//
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 1010;
long long f[N];
inline void init() {
    f[0] = 1;
    for (int i = 1; i <= 1000; i++)
        f[i] = f[i - 1] * i % mod;
}
int main() {
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n & 1) puts("0");
        else printf("%lld\n", f[n / 2] * f[n / 2] % mod);
    }
    return 0;
}

