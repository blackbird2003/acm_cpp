//
// Created by vv123 on 2022/5/4.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct line {
    int l, r, type, w;
    bool operator < (const line& x) const {
        return r < x.r;
    }
} a[N];
struct dp {
    int val;
    int pos0, pos1;//记录弱、强线段的右端点
} f[N];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].type >> a[i].w;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        //printf("a[%d]={%d,%d,%d,%d}\n", i, a[i].l, a[i].r, a[i].type, a[i].w);
        f[i] = f[i - 1];
        for (int j = 0; j < i; j++) {
            if (a[i].type == 0 && f[j].pos1 < a[i].l) {
                if (f[j].val + a[i].w > f[i].val) {
                    //printf("%d->%d\n", j, i);
                    f[i].val = f[j].val + a[i].w;
                    f[i].pos0 = a[i].r;
                    f[i].pos1 = f[j].pos1;
                    //printf("f[%d]={%d,%d,%d}\n", i, f[i].val, f[i].pos0, f[i].pos1);
                }
            }
            else if (a[i].type == 1 && max(f[j].pos0, f[j].pos1) < a[i].l) {
                if (f[j].val + a[i].w > f[i].val) {
                    //printf("%d-->%d\n", j, i);
                    f[i].val = f[j].val + a[i].w;
                    f[i].pos1 = a[i].r;
                    f[i].pos0 = f[j].pos0;
                    //printf("f[%d]={%d,%d,%d}\n", i, f[i].val, f[i].pos0, f[i].pos1);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("f[%d]={%d,%d,%d}\n", i, f[i].val, f[i].pos0, f[i].pos1);
    cout << f[n].val << endl;
    return 0;
}

