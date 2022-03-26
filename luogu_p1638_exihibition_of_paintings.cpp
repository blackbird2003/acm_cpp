//
// Created by vv123 on 2022/2/28.
//
#include <bits/stdc++.h>
#define init() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int N = 1e6 + 10, M = 2e3 + 10;

int a[N], cnt[M];
set<int> st;

int main() {
    init();
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int mn = n + 1;
    pair<int, int> ans;
    for (int l = 1, r = 0; l <= n; l++) {
        while (st.size() < m && r < n) {
            r++;
            cnt[a[r]]++;
            st.insert(a[r]);
        }
        if (st.size() == m && r - l + 1 < mn) {
            mn = r - l + 1;
            ans = {l, r};
        }
        if (--cnt[a[l]] == 0) st.erase(a[l]);
    }
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
