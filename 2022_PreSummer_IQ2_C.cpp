//
// Created by vv123 on 2022/5/22.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
char s[N];
int n, m, q, a[N][N], sum[N][N];

int main() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s + 1;
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j] - '0';
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = max(sum[i][j - 1], sum[i - 1][j]);
            if (a[i][j] && !a[i][j-1] && !a[i-1][j]) sum[i][j]++;
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    while (q--) {
        int sx, sy, tx, ty;
        cin >> sx >> sy >> tx >> ty;
        cout << sum[tx][ty] - sum[sx-1][ty] - sum[tx][sy-1] + sum[sx-1][sy-1] << endl;
    }

    return 0;
}
