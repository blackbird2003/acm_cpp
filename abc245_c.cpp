//
// Created by vv123 on 2022/3/26.
//

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int inf = 2e9 + 10;
int n, k, a[N], b[N];
signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<pair<int, int> > range;
    bool able[2];
    range.push_back({-1, inf});
    for (int i = 1; i <= n; i++) {
        able[0] = able[1] = false;
        for (auto r : range) {
            //printf("%d [%d, %d]\n", i, r.first, r.second);
            if (a[i] >= r.first && a[i] <= r.second)
                able[0] = true;
            if (b[i] >= r.first && b[i] <= r.second)
                able[1] = true;
        }
        if (!able[0] && !able[1]) {
            puts("No");
            return 0;
        }
        range.clear();
        if (able[0]) range.push_back({a[i] - k, a[i] + k});
        if (able[1]) range.push_back({b[i] - k, b[i] + k});
    }
    puts("Yes");
    return 0;
}