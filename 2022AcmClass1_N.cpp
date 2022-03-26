//
// Created by vv123 on 2022/3/4.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 2e6 + 10;
int a[N];
int main() {
    io_optimization();
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i], a[i] = -a[i];
        sort(a, a + n);
        for (int i = 0; i < k; i++)
            cout << -a[i] << " ";
        cout << "\n";
    }
    return 0;
}

