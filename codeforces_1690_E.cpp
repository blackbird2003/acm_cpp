//
// Created by vv123 on 2022/6/7.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, k, a[N], b[N], ans[N];
char s[N];
void solve() {
    multiset<int> s;
    long long sum = 0, delta = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        s.insert(a[i] % k);
    }
    while (!s.empty()) {

        //cout << "\n";
        auto it1 = s.end();it1--;
        auto it2 = s.lower_bound(k - *it1);
        auto it3 = s.begin();
        //printf("it1:%d it2:%d it3:%d\n", *it1, *it2, *it3);
        if (it1 == it2 || it2 == s.end() || (*it1 + *it3) % k < (*it1 + *it2) % k) {
            delta += (*it1 + *it3) % k;
            //printf("%d %d\n", *it1, *it3);
            s.erase(it1); s.erase(it3);
        }
        else {
            delta += (*it1 + *it2) % k;
            //printf("%d %d\n", *it1, *it2);
            s.erase(it1); s.erase(it2);
        }
    }//0 2
    cout << (sum - delta) / k << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

