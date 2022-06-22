//
// Created by vv123 on 2022/5/22.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 21;
const int inf = 1e18;
int a[N], s[N], n, pos, cnt[N];
map<int, int> gx;
int maxpre() {
    int res = -inf;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        if (s[i] > res) {
            res = s[i];
            pos = i;
        }
    }
    for (int i = 1; i <= pos; i++)
        gx[a[i]]++;
    return res;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int ans = 0;
    do {
        int t = maxpre();
        for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << "maxpre:" << t << ", pos:" << pos << endl;
        ans += t;
        cnt[pos]++;
    } while (next_permutation(a + 1, a + 1 + n));
    cout << ans << endl;
    //for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
    for (auto u:gx) {
        printf("%d:%d\n", u.first, u.second);
    }
    return 0;
}
