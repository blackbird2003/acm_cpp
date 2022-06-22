//
// Created by vv123 on 2022/6/12.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long LL;
int n, m, a[N];
char s[N], t[N], air;
int suma[N], sumb[N], sumc[N];

void solve() {
    cin >> n >> s + 1 >> t + 1;
    vector<int> posa, posb, posc;
    for (int i = 1; i <= n; i++) {
        suma[i] = suma[i - 1] + (s[i] == 'a');
        sumb[i] = sumb[i - 1] + (s[i] == 'b');
        sumc[i] = sumc[i - 1] + (s[i] == 'c');
        if (s[i] == 'a') posa.push_back(i);
        if (s[i] == 'b') posb.push_back(i);
        if (s[i] == 'c') posc.push_back(i);
    }

    for (int i = 1; i <= n; i++) {//c、b可以往前提
        if (t[i] == 'a' && s[i] != 'a') { puts("NO"); return; }
        if (t[i] == 'c' && s[i] == 'a') { puts("NO"); return; }
        if (t[i] == 'c' && s[i] == 'b') {
            bool flag = false;
            for (int j = i + 1; j <= n; j++) {
                if (s[j] == 'a') { puts("NO"); return; }
                if (s[j] == 'c') { flag = true; swap(s[i], s[j]); break; }
            }
            if (!flag) { puts("NO"); return; }
        }
        if (t[i] == 'b' && s[i] == 'c') { puts("NO"); return; }
        if (t[i] == 'b' && s[i] == 'a') {
            bool flag = false;
            for (int j = i + 1; j <= n; j++) {
                if (s[j] == 'c') { puts("NO"); return; }
                if (s[j] == 'b') { flag = true; swap(s[i], s[j]); break; }
            }
            if (!flag) { puts("NO"); return; }
        }
    }
    puts("YES");
    //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbb
    //bbbbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
