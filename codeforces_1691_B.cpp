//
// Created by vv123 on 2022/5/31.
//

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void solve() {
    int n, t;
    cin >> n;
    vector<int> v, ans;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = 2e9; v.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i + 1]) v.push_back(i);
    }
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i - 1] + 1) {
            cout << "-1\n";
            return;
        } else {
            ans.push_back(v[i]);
            for (int j = v[i - 1] + 1; j < v[i]; j++) ans.push_back(j);
        }
    }
    for (auto u: ans) cout << u << " ";
    cout << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

