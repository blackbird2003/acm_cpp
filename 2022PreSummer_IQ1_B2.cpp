//
// Created by vv123 on 2022/5/1.
//
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
    pos[0].push_back(1); pos[0].push_back(1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int t1 = abs(pos[i][0] - pos[i - 1][0]) + abs(pos[i][1] - pos[i - 1][1]);
        int t2 = abs(pos[i][0] - pos[i - 1][1]) + abs(pos[i][1] - pos[i - 1][0]);
        ans += min(t1, t2);
    }
    cout << ans << endl;
    return 0;
}

