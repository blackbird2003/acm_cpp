//
// Created by vv123 on 2022/6/4.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[114][114];
signed main() {
    a[1][1] = 1;
    for (int i = 2; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
