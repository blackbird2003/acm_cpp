//
// Created by vv123 on 2022/3/5.
//
#include <stdio.h>
#include <string.h>
char s[200], p[200];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, ans = 0;
        scanf("%d", &n);
        getchar();
        gets(p);
        for (int i = 1; i <= n; i++) {
            gets(s);
            char *token = strtok(s, " ");// non-const data() needs c++17
            bool flag = false;
            while (token != NULL) {
                if (strcmp(token, p) == 0) {
                    flag = true;
                    break;
                }
                token = strtok(NULL, " ");
            }
            if (flag) ans++;
        }
        if (!ans) puts("Do not find\n");
        else printf("%d\n\n", ans);
    }
    return 0;
}

