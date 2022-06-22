//
// Created by vv123 on 2022/4/2.
//
#include <bits/stdc++.h>
using namespace std;
map<int, int> mpx, mpy;
int main() {
    for (int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y;
        mpx[x]++; mpy[y]++;
    }
    for (auto x:mpx) {
        if (x.second != 2) cout << x.first << " ";
    }
    for (auto y:mpy) {
        if (y.second != 2) cout << y.first << " ";
    }

    return 0;
}

