//
// Created by vv123 on 2022/4/28.
//
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    rope<int> r;
    int n, m;
    cin >> n >> m;
    while (n--) {
        int x;
        cin >> x;
        r.push_back(x);
    }
    int op, pos, k;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> k >> pos;
            r.insert(pos - 1, k);
        } else {
            cin >> pos;
            cout << r.at(pos - 1) << "\n";
        }
        //for (auto x:r) printf("%d->", x);
        //puts("");
    }
    return 0;
}









































