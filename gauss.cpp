//
// Created by vv123 on 2022/4/7.
//
/*
6
1       -0.45   0       0       0      -0.45   -2
0       1       -0.72   0       0       0       -2
0       0       1       -0.54   -0.36   0       -2
0       0       0       1       0       0       10
-0.18   -0.36   -0.36   0       1       0       1
-0.09   0       0       0       0       0.19    -1
 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 110;
const double eps = 1e-6;

int n;
double a[maxn][maxn];

void print() {
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n + 1; c++)
            printf("%10.2lf", a[r][c]);
        puts("");
    }
    puts("");
}

int gauss() {
    int c, r;
    //print();
    for (c = 1, r = 1; c <= n; c++) {
        //找首数绝对值最大的行
        int t = r;
        for (int i = r + 1; i <= n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        //如果这一列没有台阶，则跳过
        if (fabs(a[t][c]) < eps) continue;
        //把首数最大的行换到第一个未固定行（第r行）
        for (int i = c; i <= n + 1; i++) swap(a[t][i], a[r][i]);
        //a[r][c]化为1
        for (int j = n + 1; j >= c; j--) a[r][j] /= a[r][c];
        //消去下方的首数（减a[i][c]倍）
        for (int i = r + 1; i <= n; i++) {
            for (int j = n + 1; j >= c; j--) {
                a[i][j] -= a[i][c] * a[r][j];
            }
        }
        r++;  //列后移
    }
    //判断解的情况
    if (r < n) {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > eps) // 增广列非0
                return 2;
        return 1;
    }
    //直接求解a[i][n+1] (从a[i][i+1]开始加过去)
    for (int i = n; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
            a[i][n + 1] -= a[i][j] * a[j][n + 1];
    return 0;

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n + 1; j++)
            cin >> a[i][j];
    int t = gauss();
    if (t == 0) {
        for (int i = 1; i <= 5; i++) printf("x%d=%.2lf\n", i, a[i][n + 1]);
        puts("x6=0");
        printf("x7=%.2lf\n", a[6][n + 1]);
    }
    else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");
    return 0;
}

