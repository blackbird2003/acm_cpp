//
// Created by vv123 on 2022/5/9.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, w, v[N], c[N], m[N];//价格、重要度、数量
int _v[N], _c[N], cnt, f[N];

void init(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; ; j <<= 1) {
            if (!m[i]) break;
            else if (m[i] >= j) {
                m[i] -= j;
                cnt++;
                _v[cnt] = v[i] * j;
                _c[cnt] = c[i] * j;
            } else {
                cnt++;
                _v[cnt] = v[i] * m[i];
                _c[cnt] = c[i] * m[i];
                break;
            }
        }
    }
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> c[i] >> m[i];
    init();
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
        for (int j = w; j >= _c[i]; j--)
            f[j] = max(f[j], f[j - _c[i]] + _v[i]), ans = max(ans, f[j]);
    cout << ans << endl;
    return 0;
}

