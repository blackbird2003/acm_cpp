#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int g[5001][5001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        g[i][x] = g[x][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (g[i][j] && g[j][k] && g[k][i]) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }
    puts("NO");
    return 0;
}