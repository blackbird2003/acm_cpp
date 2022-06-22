//
// Created by vv123 on 2022/6/6.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 10;

struct PAM {
    int n, idx, last;
    int s[N], t[N][26], fail[N], cnt[N], len[N];
    LL ans;
    PAM() {
        n = last = 0; idx = 1;
        s[0] = -1; len[0] = 0; len[1] = -1; fail[0] = 1;
    }
    int newnode(int x) {
        len[++idx] = x;
        return idx;
    }
    int getfail(int x) {
        while (s[n - len[x] - 1] != s[n]) x = fail[x];
        return x;
    }
    void add(int x) {
        s[++n] = x;
        int p = getfail(last);
        if (!t[p][x]) {
            int q = newnode(len[p] + 2);
            fail[q] = t[getfail(fail[p])][x];
            t[p][x] = q;
        }
        ++cnt[last = t[p][x]];
    }
    LL solve() {
        LL res = 0;
        for (int i = idx; i >= 0; i--) {
            cnt[fail[i]] += cnt[i];
            res = max(res, 1ll * cnt[i] * len[i]);
        }
        return res;
    }
} pam;
char str[N];

int main() {
    cin >> str;
    for (int i = 0; str[i]; i++) {
        pam.add(str[i] - 'a');
    }
    cout << pam.solve() << endl;
    return 0;
}

