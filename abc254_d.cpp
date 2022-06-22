//
// Created by vv123 on 2022/6/4.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, k;
vector<int> v[N];
bool issquare[N];
signed main() {
    for (int i = 1; i <= 20; i++) issquare[i * i] = true;
    for (int n = 1; n <= 20; n++) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (issquare[i * j]) ans++;
        cout << ans << " ";
    }
    return 0;
}
