//
// Created by vv123 on 2022/5/22.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int, int> vis;
vector<int> v;
int n;
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        vis[t]++;
        if (vis[t] == 2) v.push_back(t);
        if (vis[t] == 4) v.push_back(t);
    }
    sort(v.begin(), v.end(), greater<>());
    if (v.size() < 2) puts("0");
    else cout << v[0] * v[1] << endl;
    return 0;
}
