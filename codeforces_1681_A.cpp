//
// Created by vv123 on 2022/5/23.
//
#include <bits/stdc++.h>
using namespace std;
int n, m, a[55], b[55];
void solve() {
    int maxa = 0, maxb = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        maxb = max(maxb, b[i]);
    }
    if (maxa == maxb) {
        printf("Alice\nBob\n");
    } else {
        if (maxa > maxb) printf("Alice\nAlice\n");
        else printf("Bob\nBob\n");
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

