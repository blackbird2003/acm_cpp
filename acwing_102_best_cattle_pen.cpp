//
// Created by vv123 on 2022/2/22.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int s[N], q[N];
double slope(int i, int j) {
    return (double) (1.0 * s[i] - s[j]) / (i - j);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    int l = 1, r = 0;
    double ans = 0;
    for (int i = m; i <= n; i++) {
        //维护上凸包，选择队首
        while (l < r && slope(i - m, q[r]) <= slope(q[r], q[r - 1])) r--;
        q[++r] = i - m;
        while (l < r && slope(i, q[l]) <= slope(i, q[l+1])) l++;
        ans = max(ans, slope(i, q[l]));
    }
    cout << (int) (ans * 1000);
    return 0;
}

