//
// Created by vv123 on 2022/2/23.
//
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, x, a[N];
bool vis[N];
void solve() {
    cin >> n >> x;
    //cout << n << "qwq" << x << endl;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    //for (int i = 1; i <= n; i++) printf("*%d ", a[i]);
    //puts("");
    int p = 1, q = 1, ans = 0;

    memset(vis,0, sizeof(vis));
    while (1) {
        while (vis[p] && p <= n) p++;
        if (p > n) break;

        while ((vis[q] || a[q] < a[p] * x) && q <= n) q++;
        if (a[q] != a[p] * x || q > n) ans++, vis[p] = 1;
        else vis[p] = vis[q] = 1;
        //printf("p:%d q:%d ans:%d\n", p, q, ans);
        //getchar();
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
