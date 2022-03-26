//
// Created by vv123 on 2022/3/2.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 21;
int a[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(a, 0, sizeof a);
        int n;
        scanf("%d", &n);
        int x = 1, y = n;
        int dir = 0;
        for (int i = 1; i <= n * n; i++) {
            a[x][y] = i;
            int tx = x + dx[dir], ty = y + dy[dir];
            if (tx < 1 || tx > n || ty < 1 || ty > n || a[tx][ty]) {
                dir = (dir + 1) % 4;
                tx = x + dx[dir], ty = y + dy[dir];
            }
            x = tx, y = ty;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                printf("%4d",a[i][j]);
            puts("");
        }
    }
    return 0;
}

