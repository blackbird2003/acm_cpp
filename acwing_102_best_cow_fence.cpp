//
// Created by vv123 on 2022/3/28.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, a[N], s[N];
double f[N], rmax[N], lmin[N];

bool check(double avg) {
    for (int i = 0; i <= n + 1; i++)
        f[i] = s[i] - avg * i;
    lmin[0] = 0;
    rmax[n + 1] = -1e9;
    for (int i = 1; i <= n; i++)
        lmin[i] = min(lmin[i - 1], f[i]);
    for (int i = n; i >= 1; i--)
        rmax[i] = max(rmax[i + 1], f[i]);
    for (int r = m; r <= n; r++) {
        if (rmax[r] >= lmin[r - m]) {
            //printf("%lf (%d,%d):(%lf,%lf) yes\n", avg, r, r - m + 1, rmax[r], lmin[r + 1 - m]);
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    double l = 1, r = 2000, mid;
    while (r - l > 1e-5) {
        mid = (l + r) / 2;
        //printf("%lf %lf %lf\n", l, r, mid);
        if (check(mid)) l = mid;
        else r = mid;
    }
    //cout << mid << " " << mid * 1000 << endl;
    cout << (int) (r * 1000);
}

