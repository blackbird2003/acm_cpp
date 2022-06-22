//
// Created by vv123 on 2022/5/23.
//
#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 5e5 + 10;
int n, m, b[N];
pii a[N];
void solve() {
    //int maxa = 0, maxb = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
    }
    vector<int> ans;
    for (int k = 1; k <= n - 1; k++) {
        for (int i = 1; i <= n - k; i++) {
            if (a[i].first > a[i + 1].first || (a[i].first == a[i + 1].first && a[i].second > a[i + 1].second)) {
                ans.push_back(i);
                swap(a[i], a[i + 1]);
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i].second > a[i + 1].second) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        puts("-1");
    } else {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " " << ans[i] + 1 << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}




