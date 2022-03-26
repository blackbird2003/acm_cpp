//
// Created by vv123 on 2022/3/2.
//
#include <bits/stdc++.h>
using namespace std;
int cnt1[10], cnt2[10];
char a[110], b[110];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        scanf("%s%s", a, b);
        for (int i = 0; a[i] != '\0'; i++)
            cnt1[a[i] - '0'] ++;
        for (int i = 0; b[i] != '\0'; i++)
            cnt2[b[i] - '0'] ++;
        bool flag = true;
        for (int i = 1; i < 10; i++) {
            if (cnt1[i] != cnt2[i]) {
                flag = false;
                break;
            }
        }
        flag ? puts("Yes") : puts("No");
    }
    return 0;
}

