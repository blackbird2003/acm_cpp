//
// Created by vv123 on 2022/3/3.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 300 + 10;
int a[N];
int main() {
    io_optimization();
    int T;
    cin >> T;
    while (T--) {
        int n;
        set<int> s;
        cin >> n >> a[1];
        for (int i = 2; i <= n; i++) {
            cin >> a[i];
            int t = abs(a[i] - a[i - 1]);
            if (t >= 1 && t <= n - 1)
                s.insert(t);
        }
        if (s.size() == n - 1) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}

