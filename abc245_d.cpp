//
// Created by vv123 on 2022/3/26.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 310;
int a[N], b[N], c[N], n, m;
signed main() {
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n + m; i++)
        cin >> c[i];
    for (int i = m; i >= 0; i--) {
        int sum = c[n + i];
        for (int j = n + i - m; j < n; j++)
            sum -= a[j] * b[n + i - j];
        b[i] = sum / a[n];
    }
    for (int i = 0; i <= m; i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}

