//
// Created by vv123 on 2022/4/2.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n, k, x;
    long long ans = 0;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int num = min(k, a[i] / x);
        a[i] -= num * x;
        k -= num;
        ans += a[i];
    }
    sort(a + 1, a + 1 + n, cmp);
    if (k > 0) {
        for (int i = 1; i <= k && i <= n; i++)
            ans -= a[i];
    }
    cout << ans;
    return 0;
}




