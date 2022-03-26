//
// Created by vv123 on 2022/3/5.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--)  {
        int a, b;
        scanf("%d:%d", &a, &b);
        a = a % 12 * 30; b = b * 6;

        if (30 * b % 360 == 0) {
            a += 30 * b / 360;
            printf("%d\n", min(abs(a - b), 360 - abs(a - b)));
        } else {
            a = 2 * a + 2 * 30 * b / 360;
            b *= 2;
            printf("%d/2\n", min(abs(a - b), 720 - abs(a - b)));
        }
    }

    return 0;
}
