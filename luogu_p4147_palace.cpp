//
// Created by vv123 on 2022/3/2.
//
#include <bits/stdc++.h>
#define init_io() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 1e3 + 10;
char a[N][N];
int h[N][N], l[N][N], r[N][N];
int n, m;
void print(int c[N][N]) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
int main() {
    init_io();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            h[i][j] = a[i - 1][j] == 'F' ? h[i - 1][j] + 1 : 1;
            l[i][j] = r[i][j] = j;
        }
    }
    for (int j = 2; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[i][j - 1] == 'F')
                l[i][j] = l[i][j - 1];
        }
    }
    for (int j = m - 1; j >= 1; j--) {
        for (int i = 1; i <= n; i++) {
            if (a[i][j + 1] == 'F')
                r[i][j] = r[i][j + 1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1][j] == 'F' && l[i - 1][j] > l[i][j])
                l[i][j] = l[i - 1][j];
            if (a[i - 1][j] == 'F' && r[i - 1][j] < r[i][j])
                r[i][j] = r[i - 1][j];
            if (a[i][j] == 'F')
                ans = max(ans, h[i][j] * (r[i][j] - l[i][j] + 1));
        }
    }
    //print(l); print(r);print(h);
    cout << ans * 3 << "\n";
    return 0;
}
