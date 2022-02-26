//
// Created by vv123 on 2022/2/22.
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 9901;

int quick_pow(int a, int k) {
    int res = 1;
    for (; k; k >>= 1) {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

int sum(int p, int k) {
    if (k == 1)
        return 1;
    if (k % 2 == 0)
        return ((1 + quick_pow(p, k / 2)) * sum(p, k / 2)) % mod;
    return (sum(p, k - 1) + quick_pow(p, k - 1)) % mod;
}

int a, b;
void work() {
    int res = 1;
    //分解质因数
    for (int i = 2; i <= a / i; i++) {
        if (a % i == 0) {
            int power = 0;
            while (a % i == 0)
                a /= i, power++;
            res = res * sum(i, b * power + 1) % mod;
        }
    }
    if (a > 1) res = res * sum(a, b + 1) % mod;
    if (a == 0) res = 0;
    cout << res << endl;
}
signed main() {
    cin >> a >> b;
    work();
    return 0;
}
