//
// Created by vv123 on 2022/4/2.
//
#include <bits/stdc++.h>
#define f(i,j) i*i*i+i*i*j+i*j*j+j*j*j
using namespace std;
typedef long long LL;
int main() {
    LL n, ans = 1e18, j = 1e6;
    cin >> n;
    for (long long i = 1; i <= 1e6; i++) {
        while (f(i, j) >= n && j >= 0) {
            ans = min(ans, f(i, j));
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}





