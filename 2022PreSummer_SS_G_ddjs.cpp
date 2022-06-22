//
// Created by vv123 on 2022/5/28.
//
#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int seed, S;
const int mod = 4294967296;
const int p1 = 213346089, p2 = 166042049;
const int q1 = 870413, q2 = 598777;
bool ok;
char air;
int ans = 100000000;
void dfs(int a1, int a2, int step, int maxstep, int sum) {
    if (step == maxstep) {
        if (sum >= S) ok = true;
        return;
    }
    if ((maxstep - step) * 6 + sum < S) return;
    int a11 = (a1 * p1 + q1) % mod, a12 = (a1 * p2 + q2) % mod, sum1 = sum + (a1 % 7), a21 = (a2 * p1 + q1) % mod, a22 = (a2 * p2 + q2) % mod, sum2 = sum + (a2 % 7);
    dfs(a11, a12, step + 1, maxstep, sum1);
    if (step > 0 && !ok) dfs(a21, a22, step + 1, maxstep, sum2);
}
signed main() {
    cin >> seed >> S;
    for (int i = 1; ; i++) {
        dfs(seed, 0, 0, i, 0);
        if (ok) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}