//
// Created by vv123 on 2022/5/23.
//
//
// Created by vv123 on 2022/5/23.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m, a[N], b[N];
void solve() {
    int maxa = 0, maxb = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> m;
    long long sum = 0;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        sum += b[i];
    }
    //  0 1 2 3 4 5 6 7 8 9 10
    //0 1 2 3 4 5 1 2 3 4 5 1
    cout << a[1 + sum % n] << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}



