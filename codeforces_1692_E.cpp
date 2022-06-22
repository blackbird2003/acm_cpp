//
// Created by vv123 on 2022/6/14.
//
#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 2e5 + 10;
int n, k, a[N], s[N];
vector<pii> pa;

int getmn(int len) {
    int res = n;
    for (int i = len; i <= n; i++)
        res = min(res, s[i] - s[i - len]);
    return res;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      s[i] = s[i - 1] + a[i];
    }
    if (s[n] < k) { puts("-1"); return; }
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r + 1 >> 1;//printf("%d\n", mid);
        if (getmn(mid) <= k) l = mid; else r = mid - 1;
        //printf("%d %d\n", mid, getmn(mid));
    }
    cout << n - l << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}



