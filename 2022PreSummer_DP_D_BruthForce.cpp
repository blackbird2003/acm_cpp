//
// Created by vv123 on 2022/5/20.
//
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, s1, s2, s3, a[114514];

int k[114514], ans = inf;

int dis(int i, int j) {
    return min(abs(i - j), m - abs(i - j));
}

int calc() {
    int p[4] = {0, s1, s2, s3};
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += dis(p[k[i]], a[i]);
        p[k[i]] = a[i];
    }
    return res;
}

void dfs(int u, int pos) {
    k[pos] = u;
    if (pos == n) {
        for (int i = 1; i <= n; i++) cout << k[i] << " ";
        int res = calc();
        ans = min(ans, res);
        printf("res=%d, ans=%d\n", res, ans);
        return;
    }
    for (int i = 1; i <= 3; i++) {
        if (i != u) dfs(i, pos + 1);
    }
}


int main() {
    cin >> n >> m >> s1 >> s2 >> s3;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dfs(1, 1);
    dfs(2, 1);
    dfs(3, 1);
    cout << ans << endl;
    return 0;
}




