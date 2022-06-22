//
// Created by vv123 on 2022/5/9.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, w, a[N], b[N], f[N], t[N];
void upd(int i, int x) {
    for (; i <= n; i += i & -i)
        t[i] = max(t[i], x);
}
int ask(int i) {
    int res = 0;
    for(; i; i -= i & -i)
        res = max(res, t[i]);
    return res;
}
int val[N];
void LSH() {
    for (int i = 1; i <= n; i++)
        val[i] = b[i];
    sort(val + 1, val + 1 + n);
    int m = unique(val + 1, val + 1 + n) - 1 - val;
    for (int i = 1; i <= n; i++)
        b[i] = lower_bound(val + 1, val + 1 + m, b[i]) - val;
}
int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - i;
    }
    LSH();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = ask(b[i]) + 1;
        upd(b[i], f[i]);
        ans = max(ans, f[i]);
    }
    cout << (long long)w * (n - ans) << endl;
    return 0;
}