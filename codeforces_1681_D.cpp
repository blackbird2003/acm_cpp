
//
// Created by vv123 on 2022/5/23.
//
#include <bits/stdc++.h>
#define int unsigned long long
#define pii pair<int,int>
using namespace std;
const int N = 5e5 + 10;
int n, x, m, a[N], b[N];
inline vector<int> fj(int x) {
    vector<int> res;
    while (x) {
        res.push_back(x % 10);
        x /= 10;
    }
    return res;
}
unordered_map<int,bool> vis;
inline void solve() {
    cin >> n >> x;
    //int ans = 0;
    vector<int> v = fj(x);
    bool all1 = true;
    for (auto u:v) if (u > 1) all1 = false;
    if (all1) {
        puts("-1");
        return;
    }
    queue<pii > q;
    q.push({x, 0});
    int maxsiz = 0;
    while (!q.empty()) {
        pii u = q.front(); q.pop(); vis[u.first] = true;
        v = fj(u.first);
        if (v.size() >= n) {
            cout << u.second << endl;
            return;
        }
        //if (v.size() < maxsiz) continue;
        if (v.size() > maxsiz) maxsiz = v.size();
        sort(v.begin(), v.end(), greater<>());
        unique(v.begin(), v.end());
        for (auto t:v) {
            if (t > 1 && !vis[u.first * t]) q.push({u.first * t, u.second + 1});
        }
    }
}

signed main() {
    int T;
    T = 1;
    while (T--) solve();
    return 0;
}





