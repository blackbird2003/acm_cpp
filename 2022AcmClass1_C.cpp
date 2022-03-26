//
// Created by vv123 on 2022/3/2.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 2e5 + 10;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    io_optimization();
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << " " << lcm(a, b) << "\n";
    }
    return 0;
}

