//
// Created by vv123 on 2022/6/7.
//

#include <bits/stdc++.h>
using namespace std;

bool trytry(int h1, int n) {
    for (int h2 = h1 - 1; h2 >= 2; h2--) {
        int h3 = n - h1 - h2;
        if (h1 > h2 && h2 > h3 && h3 > 0) {
            printf("%d %d %d\n", h2, h1, h3);
            return true;
        }
    }
    return false;
}


void solve() {
    int n;
    cin >> n;
    for (int x = n / 3; ; x++) {
        if (trytry(x, n)) break;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}