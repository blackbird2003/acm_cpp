//
// Created by vv123 on 2022/5/19.
//
#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n, m;
pii check() {

}
void solve() {
    cin >> n >> m;
    pii lst = {0, 0};
    for (int i = 1; i <= n; i++) {
        pii res = check();
        if (res.first == -1) {
            puts("-1");
            return;
        }
        if (lst.first == 0) {
            if (res.first == 0) continue;
            else lst = res;
        } else {

        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
