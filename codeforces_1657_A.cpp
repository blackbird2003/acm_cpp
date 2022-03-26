//
// Created by vv123 on 2022/3/22.
//
#include <iostream>
using namespace std;
bool issquare[10010];
int main() {
    for (int i = 1; i <= 100 ; i++) issquare[i * i] = true;
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        if (!x && !y) puts("0");
        else if (issquare[x * x + y * y]) puts("1");
        else puts("2");
    }
    return 0;
}
