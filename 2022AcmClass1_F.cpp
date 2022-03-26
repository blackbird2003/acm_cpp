//
// Created by vv123 on 2022/3/2.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 1e3 + 10;
bool st[N];
int main() {
    io_optimization();
    int T;
    cin >> T;
    while (T--) {
        memset(st, 0, sizeof(st));
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= k; i++)
            for (int j = i; j <= n; j += i)
                st[j] ^= 1;
        for (int i = 1; i <= n; i++)
            if (st[i])
                cout << i << " ";
        cout << "\n";
    }
    return 0;
}

