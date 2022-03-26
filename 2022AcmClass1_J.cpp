//
// Created by vv123 on 2022/3/3.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 2e5 + 10;

int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int b[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int x) {
    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
        return true;
    return false;
}

int main() {
    io_optimization();
    for (int i = 1; i <= 12; i++)
        a[i] += a[i - 1], b[i] += b[i - 1];
    int T;
    cin >> T;
    while (T--) {
        int y, m, d;
        cin >> y >> m >> d;
        if (check(y)) cout << b[m - 1] + d << "\n";
        else cout << a[m - 1] + d << "\n";
    }
    return 0;
}
