//
// Created by vv123 on 2022/2/28.
//
#include <bits/stdc++.h>
#define init() ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int t[610], n, w;
int main() {
    init();
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        t[x]++;
        int cnt = 0;
        for (int j = 600; j >= 0; j--) {
            cnt += t[j];
            if (cnt >= max(1, i * w / 100)) {
                cout << j << " ";
                break;
            }
        }
    }
    return 0;
}

