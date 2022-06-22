//
// Created by vv123 on 2022/5/4.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
struct Ans {
    int x, y, z;
} ans[N];
int vis[N];
void solve() {
    ans[0] = {0, 0, 0};
    vis[0] = 1;
    for (int i = 1; i <= 10000; i++) {
        if (i >= 8 && vis[i - 8]) {
            ans[i] = ans[i - 8];
            ans[i].x += 1;
            vis[i] = 1;
        } else if (i >= 9 && vis[i - 9]) {
            ans[i] = ans[i - 9];
            ans[i].y += 1;
            vis[i] = 1;
        } else if (i >= 10 && vis[i - 10]) {
            ans[i] = ans[i - 10];
            ans[i].z += 1;
            vis[i] = 1;
        }
    }
}

int main() {
    solve();
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (!vis[n]) puts("-1");
        else printf("%d %d %d\n", ans[n].x, ans[n].y, ans[n].z);
    }
    return 0;
}
