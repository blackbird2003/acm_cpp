//
// Created by vv123 on 2022/5/20.
//
#include <bits/stdc++.h>
using namespace std;
int n, m, s1, s2, s3, a[114514];
int main() {
    srand(time(0));
    n = rand() % 6 + 1, m = rand() % 6 + 1;
    s1 = rand() % m + 1, s2 = rand() % m + 1, s3 = rand() % m + 1;
    printf("%d %d\n%d %d %d\n", n, m, s1, s2, s3);
    for (int i = 1; i <= n; i++)
        cout << rand() % m + 1 << " ";
}

