//
// Created by vv123 on 2022/3/5.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n, cnt[2];
    while (cin >> n && n) {
        cnt[0] = cnt[1] = 0;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') cnt[0]++;
            else if (s[i] == 'Y') cnt[1]++;
            else {
                if (s[i] == 'B') {
                    cnt[0] == 7 ? puts("Red") : puts("Yellow");
                } else {
                    cnt[1] == 7 ? puts("Yellow") : puts("Red");
                }
            }
        }
    }
    return 0;
}

