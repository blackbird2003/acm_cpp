//
// Created by vv123 on 2022/4/30.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int w[N], f[N];
bool check(int x) {
    vector<int> v1, v2;
    while (x) v1.push_back(x % 10), x /= 10;
    v2 = v1;
    reverse(v2.begin(), v2.end());
    for (int i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            return false;
    return true;
}
int main() {
    int cnt = 0, T;
    for (int i = 1; i <= 40000; i++) {
        if (check(i)) w[++cnt] = i;
    }
    f[0] = 1;
    for (int i = 1; i <= cnt; i++)
        for (int j = w[i]; j <= 40000; j++)
            (f[j] += f[j - w[i]]) %= mod;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}
