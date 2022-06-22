//
// Created by vv123 on 2022/3/26.
//
#include <iostream>
using namespace std;
int exist[2001];
int main() {
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        exist[t] = 1;
    }
    for (int i = 0; i <= 2000; i++)
        if (!exist[i]) {
            cout << i << endl;
            break;
        }
    return 0;
}
