//
// Created by vv123 on 2022/3/3.
//
#include <bits/stdc++.h>
using namespace std;
int f[6];
int main() {
    int T;
   scanf("%d", &T);
    while (T--) {
        int q, n, pos;
        scanf("%d%d%d", &f[0], &f[1], &q);
        f[0] %= 3; f[1] %= 3;
        for (int i = 2; i <= 5; i++) {
            f[i] = f[i - 1] + f[i - 2];
            if (f[i] % 3 == 0) {
                pos = i;
                break;
            }
        }
        while (q--) {
            cin >> n;
            if (f[0] == 0 && f[1] == 0)
                puts("Yes");
            else {
                n % 4 == pos % 4 ? puts("Yes") : puts("No");
            }
        }
        puts("");
    }
    return 0;
}

