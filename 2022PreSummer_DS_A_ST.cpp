//
// Created by vv123 on 2022/4/30.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1, null = -1;
#define int long long
int n, m, d, q, cnt, a[N], k[N], key[N], f[N][20], h[N + 1];
int sum[64][N];
int find (int x) {
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) {
        k++;
        if(k == N) k = 0;
    }
    return k;
}

inline int solve(int x) {   //用第几把钥匙开
    while(x) {
        for (int i = 1; i <= cnt; i++)
            if (key[i] == x)
                return 1ll << i - 1;
        x /= d;
    }
    return 0ll;
}
inline void ST() {  //f[i][j] = OR of [i, i + 2^j - 1]
    for (int i = 1; i <= n; i++) f[i][0] = solve(a[i]);//, cout << bitset<5>(f[i][0]) << endl;
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = f[i][j - 1] | f[i + (1 << (j - 1))][j - 1];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i < N; i++) h[i] = null;
    cin >> n >> m >> d >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> k[i];
    }
    sort(k + 1, k + 1 + m);
    h[find(k[1])] = k[1]; key[++cnt] = k[1];
    for (int i = 2; i <= m; i++) {
        int x = k[i];
        bool exist = false;
        while (x) {
            if (h[find(x)] != null) {
                exist = true;
                break;
            }
            x /= d;
        }
        if (!exist) h[find(k[i])] = k[i], key[++cnt] = k[i];
    }
    /*
    //至多60个数，查询区间不同数的个数
    //维护每个数的前缀出现次数，对每个区间，遍历每个数的区间和是否非0
    for (int i = 1; i <= n; i++) {
        int t = solve(a[i]);
        for (int j = 1; j <= m; j++) {
            if (j == t) sum[j][i] = sum[j][i-1] + 1;
            else sum[j][i] = sum[j][i - 1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (sum[i][r] - sum[i][l - 1] > 0) ans++;
        }
        cout << ans << "\n";
    }*/
    //for (int i = 1; i <= cnt; i++) cout << key[i] << " ";
    /*
     for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }*/
    ST();
    while (q--) {
        int l, r, s;
        cin >> l >> r;
        s = log2(r - l + 1);
        cout << bitset<64>(f[l][s] | f[r - (1 << s)][s]).count() << "\n";
    }
    return 0;
}