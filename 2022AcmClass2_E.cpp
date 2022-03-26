//
// Created by vv123 on 2022/3/5.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
char s[N], t1[N], t2[N];
int solve(char t[]) {
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && s[i] != t[i])
            cnt0++;
        if (s[i] == '1' && s[i] != t[i])
            cnt1++;
    }
    //cout << max(cnt0, cnt1) << endl;
    return max(cnt0, cnt1);
}
int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        t1[i] = i % 2 ? '1' : '0';
        t2[i] = i % 2 ? '0' : '1';
    }
    cout << min(solve(t1), solve(t2));
    return 0;
}
