//
// Created by vv123 on 2022/6/14.
//
#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int N = 1e4 + 10;
int n, b[N];
vector<pii> pa;

void solve() {
    string str;
    int x;
    cin >> str >> x;
    int h = (str[0] - '0') * 10 + str[1] - '0', h0 = h;
    int m = (str[3] - '0') * 10 + str[4] - '0', m0 = m;
    int ans = 0;
    while (1) {
        //printf("%d %d\n", h, m);
        pii t = {h, m};
        for (auto p : pa) if (t == p) ans++;

        m += x;
        if (m >= 60) h += m / 60, m %= 60;
        h %= 24;
        if (h == h0 && m == m0) break;
    }
    cout << ans << "\n";
}

int main() {
    pa.push_back({00, 00});
    pa.push_back({01, 10});
    pa.push_back({02, 20});
    pa.push_back({03, 30});
    pa.push_back({04, 40});
    pa.push_back({05, 50});
    pa.push_back({10, 01});
    pa.push_back({11, 11});
    pa.push_back({12, 21});
    pa.push_back({13, 31});
    pa.push_back({14, 41});
    pa.push_back({15, 51});
    pa.push_back({20, 02});
    pa.push_back({21, 12});
    pa.push_back({22, 22});
    pa.push_back({23, 32});
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}



