#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int a[N], vis[N], cnt;
vector<int> pos[N];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n * 2; i++) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    int ans = 0, u = 1;
    for (int i = 1; i <= n; i++) {
        //cout << "u=" << u << ", last=" << last << endl;
        int mind = INF, v;
        for (auto t:pos[i]) {
            //cout << t << endl;
            if (!vis[t] && abs(u - t) < mind) mind = abs(u - t), v = t;
        }
        vis[v] = 1; u = v; ans += mind;
        //cout << "->"  << v << endl;
    }
    //cout << ans << endl;
    u = 1;
    for (int i = 1; i <= n; i++) {
        //cout << "u=" << u << ", last=" << last << endl;
        int mind = INF, v;
        for (auto t:pos[i]) {
            //cout << t << endl;
            if (!vis[t] && abs(u - t) < mind) mind = abs(u - t), v = t;
        }
        vis[v] = 1; u = v; ans += mind;
        //cout << "->"  << v << endl;
    }
    cout << ans << endl;
    return 0;
}
