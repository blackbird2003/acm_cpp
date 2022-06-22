//
// Created by vv123 on 2022/5/25.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 10086;
int minv[N];
int n, m, mins = 2e9;

void dfs(int k, int R, int H, int V, int S) {
    //目前在从下往上数第k层，从上往下数第m-k-1层
    //现在准备搭从下往上数第k+1层，从上往下数第m-k层
    if (k == m) {
        if (V == n) mins = min(mins, S);
        return;
    }
    //if (V > n) return;
    //if (S > mins) return;
    if (S - R * R + 2 * (m - k) * (m - k) + (m - k) > mins) return;
    for (int r = min(R - 1, (int)sqrt(n - V - minv[m - k - 1]) + 1); r >= m - k; r--) {
        for (int h = min(H - 1, (int)((double)(n - V - minv[m - k - 1]) / r / r)); h >= m - k; h--) {
        //for (int h = m - k; h < H && V + r * r * h + minv[m - k - 1] <= n; h++) {
            if (V + r * r * h > n) continue;
            if (S + 2 * r * h> mins) continue;
            if (S + 2.0 * (n - V) / r > mins) continue;
            dfs(k + 1, r, h, V + r * r * h, S + 2 * r * h);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        minv[i] = minv[i - 1] + i * i;
    for (int R1 = (int)sqrt(n - minv[m - 1]) + 1; R1 >= m; R1--) {
        for (int H1 = 1; R1 * R1 * H1 + minv[m - 1] <= n; H1++) {
            dfs(1, R1, H1, R1 * R1 * H1, R1 * R1 + 2 * R1 * H1);
        }
    }
    if (mins == 2e9) mins = 0;
    cout << mins << endl;
    return 0;
}
