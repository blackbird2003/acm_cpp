//
// Created by vv123 on 2022/6/15.
//
#include <bits/stdc++.h>
using namespace std;
int mx, l, r, a;

void calc(int x, vector<int> pos) {
    //for (auto u:pos) cout << u << " "; puts("");
    int n = pos.size();
    //ans = maxcnt * 2 - (posr-posl+1)
    // = max((r - l + 1) * 2 - (posr-posl+1))
    //->max(2 * r - posr) - (2 * l - posl)
    set<pair<int,int>> s;
    for (int i = n - 1; i >= 0; i--) {
        s.insert({2 * i - pos[i], pos[i]});
        pair<int,int> rmax = *s.rbegin();
        //cout << rmax.first <<  " " << rmax.second << "\n";
        if (rmax.first - (2 * i - pos[i]) > mx) {
            mx = rmax.first - (2 * i - pos[i]);
            a = x;
            l = pos[i];
            r = rmax.second;
        }
    }
}

void solve() {
    mx = -2e9, l = r = a = 0;
    int n;
    cin >> n;
    map<int, vector<int> > pos;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        pos[t].push_back(i);
    }
    for (auto u:pos) {
        calc(u.first, u.second);
        //printf("alr:%d %d %d\n", a, l, r);
    }
    printf("%d %d %d\n", a, l, r);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
