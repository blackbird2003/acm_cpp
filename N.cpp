//
// Created by vv123 on 2022/5/4.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int mod = 998244353;
int a[N];
int xs[N][N];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)  cin >> a[i];
    long long ans = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            (ans *= (a[i] + a[j])) %= mod;
    cout << ans << "\n";
    return 0;
}
