//
// Created by vv123 on 2022/3/6.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    sort(h.begin(), h.end());
    while(m--) {
        int height;
        cin >> height;
        cout << n - (lower_bound(h.begin(), h.end(), height) - h.begin()) << "\n";
    }
    return 0;
}
