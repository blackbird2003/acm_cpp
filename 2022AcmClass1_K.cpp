//
// Created by vv123 on 2022/3/3.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 2e5 + 10;
char n[310];
int main() {
    io_optimization();
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == "0") {
            cout << "Yes Yes\n";
            continue;
        }
        int sum = 0, odd_sum = 0, even_sum = 0;
        for (int i = 0; i < strlen(n); i++) {
            sum += n[i] - '0';
            if ((i + 1) % 2 == 1) odd_sum += n[i] - '0';
            else even_sum += n[i] - '0';
        }
        if (sum % 3 == 0) cout << "Yes ";
        else cout << "No ";
        if ((odd_sum - even_sum) % 11 == 0) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
