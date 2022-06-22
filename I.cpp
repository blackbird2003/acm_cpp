//
// Created by vv123 on 2022/5/4.
//
//考虑a1,a2,a3,a4,a5经过一次变换后成为b1,b2,b3,b4,b5
//我们一定可以把bx写成这样的形式
//bx=ay+d
//我们整这样一个向量(a1,a2...an, 1)
//变换可以转化为矩阵乘法的形式
//矩阵快速幂？
//其实每次“乘法”都是O(N)的
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
struct act {
    int a[N][2];
    act operator * (const act& x) {
        act res;//求now * x      (ay+d)
        for (int i = 1; i <= n; i++) {
            res.a[i][0] = a[x.a[i][0]][0];
            res.a[i][1] = a[i][0] * x.a[i][1] + a[];
        }
        return res;
    }
};
int q[N], n, k;
int ans[100][N]; //每一轮后的队列
int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        cin >> a[i].op;
        if (a[i].op == "S") cin >> a[i].x >> a[i].y;
        else cin >> a[i].x;
    }
    for (int t = 1; t <= 100; t++) {
        for (int i = 1; i <= k; i++) {
            if (a[i].op == "+") q[a[i].x] += 1;
            else if (a[i].op == "E") q[a[i].x] = 0;
            else swap(q[a[i].x], q[a[i].y]);
        }
        for (int i = 1; i <= n; i++) ans[k][i] = q[i], cout << ans[k][i] << " ";
        puts("");
    }
    return 0;
}
