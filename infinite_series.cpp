//
// Created by vv123 on 2022/2/28.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    double sum = 0;
    for (int i = 1; i <= 1000000; i++) {
        int f = i % 2 ? -1 : 1;
        sum += 1.0 * f / pow(1.0 * i, 1.0 / i);
        cout << sum << "\n";
    }
    return 0;
}
