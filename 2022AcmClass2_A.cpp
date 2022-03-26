//
// Created by vv123 on 2022/3/4.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 110;

struct ant {
    char name[21];
    int pos;
    char dir;
    int t;
}a[N], b[N];

bool cmp1(ant x, ant y) {
    return  x.t < y.t;
}
bool cmp2(ant x, ant y) {
    return x.pos < y.pos;
}

int main() {
    int T;
    cin >> T;
    for (int k = 1; k <= T; k++) {
        printf("Case #%d:\n", k);

        int n, l;
        cin >> n >> l;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].name >> a[i].pos >> a[i].dir;
            a[i].t = a[i].dir == 'L' ? a[i].pos : l - a[i].pos;
            b[i] = a[i];
        }
        sort(a + 1, a + 1 + n, cmp1);
        sort(b + 1, b + 1 + n, cmp2);
        int pl = 1, pr = n;
        for (int i = 1; i <= n; i++) {
            printf("%d %s\n", a[i].t, a[i].dir == 'L' ? b[pl++].name : b[pr--].name);
        }
    }
    return 0;
}
