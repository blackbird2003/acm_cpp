//
// Created by vv123 on 2022/5/21.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
char p[maxn], s[maxn];
int n, m;
int ne[maxn];

int main() {
    cin >> s + 1 >> p + 1;
    n = strlen(p + 1), m = strlen(s + 1);
    //next
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[j + 1] != p[i]) j = ne[j];
        if (p[j + 1] == p[i]) j++;
        ne[i] = j;
    }
    //kmp process
    int ans = 0;
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && p[j + 1] != s[i]) j = ne[j];
        if (p[j + 1] == s[i]) j++;
        if (j == n) {
            ans++;
            j = ne[j];
        }
    }
    cout << ans;
    return 0;
}

