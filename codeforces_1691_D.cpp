//
// Created by vv123 on 2022/5/31.
//

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int n, a[N], s[N], l[N], r[N];
int f[N][21][2];

void ST() {
    for (int i = 0; i <= n; i++)
        f[i][0][0] = f[i][0][1] = s[i];
    //f[i][j] = max([i, i + 2^j - 1])
    for (int j = 1; j <= log2(n) + 1; j++)
        for (int i = 0; i + (1 << j) - 1 <= n; i++) {
            f[i][j][0] = min(f[i][j - 1][0], f[i + (1 << (j - 1))][j - 1][0]);
            f[i][j][1] = max(f[i][j - 1][1], f[i + (1 << (j - 1))][j - 1][1]);
        }
}
int query_min(int l, int r) {
    int s = log2(r - l + 1);
    return min(f[l][s][0], f[r - (1 << s) + 1][s][0]);
}
int query_max(int l, int r) {
    int s = log2(r - l + 1);
    return max(f[l][s][1], f[r - (1 << s) + 1][s][1]);
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        l[i] = r[i] = i;
    }
    a[0] = a[n+1] = inf;
    stack<int> st;//单调递减栈
    for (int i = 1; i <= n + 1; i++) {
        while (!st.empty() && a[st.top()] < a[i]) {
            r[st.top()] = i - 1;
            st.pop();
        }
        st.push(i);
    }
    ST();
    for (int i = n; i >= 0; i--) {
        while (!st.empty() && a[st.top()] < a[i]) {
            l[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    //-1 1 -1 2
    //-1 0 -1 1
    bool fail = false;
    for (int i = 1; i <= n; i++) {
        //printf("%d %d\n", l[i], r[i]);
        //printf("%d %d %d\n", a[i], s[i] - query_min(l[i] - 1, i - 1), query_max(i, r[i]) - s[i - 1]);
        if (a[i] < s[i] - query_min(l[i] - 1, i - 1)) fail = true;//[[l[i],i],i]
        if (a[i] < query_max(i, r[i]) - s[i - 1]) fail = true;//[i,[i,r[i]]
        if (fail) break;
    }
    if (fail) puts("NO");
    else puts("YES");
}

void solve2() {
    cin >> n;
    int tmp, mx = -inf, now = 0;
    bool fail = false;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        mx = max(mx, tmp);
        now += tmp;
        if (now > mx) {
            fail = true;
        }
        if (now < 0) {
            mx = 0;
            now = 0;
        }
    }
    if (fail) puts("NO"); else puts("YES");
}

signed main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}





