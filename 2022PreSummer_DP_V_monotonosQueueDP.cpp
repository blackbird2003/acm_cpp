//
// Created by vv123 on 2022/5/20.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, T, tp[N], p[N], range[N], d[N], f[N];
int q[N];
bool check(int r) {
    //printf("r=%d\n", r);
    /*
    memset(f, 0x3f, sizeof f);
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = max(1, i - r); j <= i - 1; j++)
            f[i] = min(f[i], f[j] + (i - j) + d[i]);//, cout << j << endl;
        //printf("f[%d]=%d\n", i, f[i]);
    }
    return f[n] <= T;
     */
    memset(q, 0, sizeof q);
    int h = 1, t = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 1) f[i] = f[q[h]] - q[h] + i + d[i];
        while (h <= t && i - q[h] + 1 > r) h++;
        while (h <= t && f[q[t]] - q[t] > f[i] - i) t--;
        q[++t] = i;
        //printf("f[%d]=(%d-%d)+%d+%d=%d\n",i,f[q[h]],q[h],i,d[i],f[i]);
    }
    return f[n] <= T;
}

int main() {
    cin >> n >> T;
    for (int i = 1; i <= n - 1; i++)
        cin >> tp[i];
    for (int i = 2; i <= n - 1; i++)
        cin >> d[i];
    int cnt = 0, minp = inf;
    for (int i = n - 1; i >= 1; i--) {
        if (tp[i] < minp) {
            minp = tp[i];
            p[++cnt] = tp[i];
            range[cnt] = i;
        }
    }
    reverse(p + 1, p + 1 + cnt);
    reverse(range + 1, range + 1 + cnt);
    //for (int i = 1; i <= cnt; i++) cout << p[i] << " ";cout << endl;
    int l = 1, r = cnt;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(range[mid])) r = mid;
        else l = mid + 1;
    }
    cout << p[l] << endl;
    return 0;
}
