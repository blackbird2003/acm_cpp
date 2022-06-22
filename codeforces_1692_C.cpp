//
// Created by vv123 on 2022/6/14.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n, b[N];
char m[10][10];
void solve() {
    for (int i = 1; i <= 8; i++)
        cin >> m[i] + 1;
    for (int i = 2; i <= 7; i++)
        for (int j = 2; j <= 7; j++)
            if (m[i][j] == '#' && m[i-1][j-1] == '#' && m[i-1][j+1] == '#' && m[i+1][j-1] == '#' && m[i+1][j+1] == '#')
                cout << i << " " << j << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}



