//
// Created by vv123 on 2022/3/2.
//
#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
double score[110];
int main() {
    io_optimization();
    cout << fixed << setprecision(2);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> score[i];
            sum += score[i];
        }
        sort(score, score + n);
        cout << (sum - score[0] - score[n - 1]) / (n - 2) << "\n";
    }
    return 0;
}



