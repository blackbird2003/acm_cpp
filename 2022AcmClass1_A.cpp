//
// Created by vv123 on 2022/3/2.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 2e5 + 10;
int a[3];
int main() {
    io_optimization();
    int T;
    cin >> T;
    while (T--) {
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        if (a[0] != a[1] && a[1] != a[2] && a[0] != a[2])
            cout << a[1] << "\n";
        else
            cout << a[2] << "\n";
    }
    return 0;
}