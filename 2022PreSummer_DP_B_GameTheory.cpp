//
// Created by vv123 on 2022/5/16.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int inf = 0x3f3f3f3f;
int a[N][N], n, m;
struct point {
    int x, y, w;
    bool operator < (const point& x) const {
        return w > x.w;
    }
} p[N * N];


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], p[(i - 1) * n + j] = {i, j, a[i][j]};
    sort(p + 1, p + 1 + n * n);
    int minp, maxp, minm, maxm;
    vector<pair<int, int> > ans;
    for (int i = 1; i <= n * n; i++) {
        int x = p[i].x, y = p[i].y, w = p[i].w, np = x + y, nm = x - y;
        int farest = max(max(abs(np - minp), abs(np - maxp)), max(abs(nm - minm), abs(nm - maxm)));
        //printf("(%d, %d):%d, np=%d, nm=%d\n", x, y, w, np, nm);
        //cout << "The farest is " << farest << ", ";
        if (i == 1) {
            //puts("YES");
            ans.push_back({x, y});
            minp = maxp = x + y;
            minm = maxm = x - y;
        } else if (farest <= m){
            //puts("YES");
            ans.push_back({x, y});
            minp = min(minp, x + y);
            maxp = max(maxp, x + y);
            minm = min(minm, x - y);
            maxm = max(maxm, x - y);
        } //else puts("NO");
        //printf("now maxp=%d, minp=%d, maxm=%d\n", maxp, minp, maxm);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto u : ans) cout << u.first << " " << u.second << "\n";
    return 0;
}
