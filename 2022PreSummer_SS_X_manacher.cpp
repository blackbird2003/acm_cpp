//
// Created by vv123 on 2022/5/21.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5e6;
char ts[N], t[N], s[N];
int len[N];

int mana(char* t) {
    int cnt = 0, n = strlen(t + 1);
    s[++cnt] = '~'; s[++cnt] = '#';
    for (int i = 1; i <= n; i++) {
        s[++cnt] = t[i];
        s[++cnt] = '#';
    }
    s[++cnt] = '!';
    //cout << cnt << " " << s + 1  << endl;
    int mid = 0, maxr = 0, ans = 0;
    for (int i = 2; i <= cnt - 1; i++) {
        len[i] = i <= maxr ? min(len[mid * 2 - i], maxr - i + 1) : 1;
        while (s[i - len[i]] == s[i + len[i]]) len[i]++;
        if (i - 1 == len[i]) ans = max(ans, len[i] - 1);
        if (i + len[i] > maxr) maxr = i + len[i] - 1, mid = i;
    }
    //for (int i = 1; i <= cnt; i++) cout << i << " ";cout << endl;
    //for (int i = 1; i <= cnt; i++) cout << len[i] << " ";cout << endl;
    return ans;
    //alllen[i] = len[i] * 2 - 1
    //reallen[i] = (alllen[i] - 1) / 2 = len[i] - 1
}

int main() {
    cin >> t + 1;
    int n = strlen(t + 1);
    int p = 0;
    while (p + 1 <= n && t[p + 1] == t[n - p]) p++;
    if (p == n) {
        cout << t + 1 << endl;
        return 0;
    }
    int m = 0;
    for (int i = p + 1; i <= n - p; i++) ts[++m] = t[i];
    //cout << ts + 1 << endl;
    int l = mana(ts);
    reverse(ts + 1, ts + 1 + m);
    int r = mana(ts);
    //printf("%d %d %d\n", p, l, r);
    cout << p * 2 + max(l, r);
    return 0;
}
