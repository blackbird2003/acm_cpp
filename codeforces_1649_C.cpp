//
// Created by vv123 on 2022/3/7.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
vector<int> a[N][2];

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int c;
            cin >> c;
            a[c][0].push_back(i);
            a[c][1].push_back(j);
        }
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (a[i][0].empty())
            continue;
        sort(a[i][0].begin(), a[i][0].end(), greater<int>());
        sort(a[i][1].begin(), a[i][1].end(), greater<int>());
        for (int j = 0; j < a[i][0].size(); j++) {
            //printf("%d %d %d\n", a[i][0].size() - 1 - 2 * i, a[i][0][j], a[i][1][j]);
            ans += (a[i][0].size() - 1 - 2 * j) * (a[i][0][j] + a[i][1][j]);
        }
    }
    cout << ans;

    return 0;
}
