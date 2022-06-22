//
// Created by vv123 on 2022/6/4.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, k;
vector<int> v[N];
signed main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        v[i % k].push_back(t);
    }
    for (int i = 0; i < k; i++) {
        sort(v[i].begin(), v[i].end());
        //for (auto u: v[i]) cout << u << " ";cout << "\n";
    }
    bool ok = true;
    for (int i = 0; i <= n - 2; i++) {
        int j = i + 1;
        //printf("%d %d %d %d\n", i, j, v[i % k][i / k], v[j % k][j / k]);
        if (v[i % k][i / k] > v[j % k][j / k]) {
            ok = false;
            break;
        }
    }
    if (ok) puts("Yes");
    else puts("No");
    return 0;
}
