//
// Created by vv123 on 2022/5/9.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, s, t, a[N], sum[N];
int ans;
void solve(int T) {
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << "\n" << s << "\n";
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int l = 1; l <= s; l++) {
        int t = T - (s - l);
        int r = min(l + (t + 1) / 2 - 1, n);
        if (T <= 0 || r < s) continue;
        ans = max(ans, sum[r] - sum[l - 1]);
        printf("%d %d %d %d\n", l, r, sum[r] - sum[l - 1], ans);
    }
}

void bf(int T) {
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int l = 1; l <= n;  l++) {
        for (int r = 1; r <= n; r++) {
            if (sum[r] - sum[l - 1] == 426) {printf("%d %d\n", l, r);return;}
            //if (min(s - l, r - s) + 2 * (r - l + 1) - 1 > T) continue;
            //ans = max(ans, sum[r] - sum[l - 1]);
            //printf("-->%d %d %d %d\n", l, r, sum[r] - sum[l - 1], ans);
        }
    }
}

int main() {
    cin >> n >> s >> t; s++;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bf(t);
    solve(t);
    reverse(a + 1, a + 1 + n);
    s = n + 1 - s;
    solve(t);
    cout << ans << endl;
    return 0;
}

