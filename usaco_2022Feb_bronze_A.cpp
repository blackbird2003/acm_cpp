//
// Created by vv123 on 2022/2/26.
//
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n, sum, a[N];

bool check(int m) {
    int num = n - m;
    if (sum % num != 0)
        return false;
    int x = sum / num, tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += a[i];
        if (tot == x) tot = 0;
        if (tot > x) return false;
    }
    return true;
}

vector<int> divide(int x) {
    vector<int> res;
    int t = x;
    res.push_back(1);
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int p = 0;
            while (x % i == 0) {
                x /= i;
                p++;
            }
            res.push_back(i);
        }
    }
    if (x > 1) res.push_back(x);
    res.push_back(t);
    return res;
}

void solve() {
    memset(a, 0, sizeof(a));
    cin >> n;
    sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    /*if (sum == 0) {
        cout << "0\n";
        return;
    }
    vector<int> fac = divide(sum);
    for (auto i : fac) {
        if (sum / i > n) continue;
        if (check(n - sum / i)) {
            cout << n - sum / i << "\n";
            return;
        }
    }*/
    for (int i = 0; i < n; i++) {
        if (check(i)) {
            cout << i << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
