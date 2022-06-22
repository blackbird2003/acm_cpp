//
// Created by vv123 on 2022/5/22.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int inf = 1e18;
int n, a[N];
int sum[N], sum1[N], sum2[N]; //前缀前n大和 后缀前n小和
signed main() {
    cin >> n;
    for (int i = 1; i <= n * 3; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    //求[n,2n]每个位置的前缀前n大和
    priority_queue<int, vector<int>, greater<int> > q;//小根堆
    for (int i = 1; i <= n; i++) q.push(a[i]);
    sum1[n] = sum[n];
    for (int i = n + 1; i <= n * 2; i++) {
        int t = q.top();
        if (t < a[i]) {
            sum1[i] = sum1[i - 1] - t + a[i];
            q.pop(); q.push(a[i]);
        } else {
            sum1[i] = sum1[i - 1];
        }
    }
    //for (int i = n; i <= n * 2; i++) cout << sum1[i] << " ";
    //cout << endl;

    //求[2n+1->n+1]每个位置的后缀前n小和
    priority_queue<int> q2;//大根堆
    for (int i = n * 3; i >= 2 * n + 1; i--) q2.push(a[i]);
    sum2[n * 2 + 1] = sum[n * 3] - sum[n * 2];
    for (int i = n * 2; i >= n + 1; i--) {
        int t = q2.top();
        if (t > a[i]) {
            //cout << t << endl;
            sum2[i] = sum2[i + 1] - t + a[i];
            q2.pop(); q2.push(a[i]);
        } else {
            sum2[i] = sum2[i + 1];
        }
    }
    //for (int i = n * 2 + 1; i >= n + 1; i--) cout << sum2[i] << " ";
    //cout << endl;

    int ans = -inf;
    for (int i = n; i <= n * 2; i++)
        ans = max(ans, sum1[i] - sum2[i + 1]);
    cout << ans << endl;

    return 0;
}

