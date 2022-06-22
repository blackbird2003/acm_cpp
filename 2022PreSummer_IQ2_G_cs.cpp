//
// Created by vv123 on 2022/5/22.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 21;
const int mod = 998244353;
int n, a[N], b[N], sum[N];
int lowbit(int x) { return x & -x; }
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[1 << i - 1] = a[i];
    }
    int S = (1 << n) - 1;
    for (int i = 0; i <= S; i++) {
        sum[i] = (sum[i - lowbit(i)] + b[lowbit(i)]) % mod;
    }
    return 0;
}

