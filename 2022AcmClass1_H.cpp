//
// Created by vv123 on 2022/3/3.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 110;
char s[N][N];
int main() {
    io_optimization();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> s[i] + 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << s[n + 1 - j][i];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}

