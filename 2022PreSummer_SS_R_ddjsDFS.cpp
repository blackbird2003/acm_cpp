//
// Created by vv123 on 2022/5/27.
//
/*
11111
01101
00111
00*01
00000
res = 3
minstep = 3
 f=g+h
考虑h
每一次操作至多使一个非*点归位
因此最少还要res-1步
*/
#include <bits/stdc++.h>
using namespace std;
char s[5][5], now[5][5];
char t[5][5] = {
        {'1','1','1','1','1'},
        {'0','1','1','1','1'},
        {'0','0','*','1','1'},
        {'0','0','0','0','1'},
        {'0','0','0','0','0'},
};

inline int check() {
    int res = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (now[i][j] != t[i][j])
                res++;
    return res;
}
void print() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << now[i][j];
        cout << "\n";
    }
    cout << "\n";
}
int d[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
bool ok;
void dfs(int step, int maxstep) {
    //cout << step << " " << maxstep << "\n";
    //print();
    //cout << "check = " << check() << "\n";
    if (step == maxstep) {
        if (check() == 0) ok = true;
        return;
    }
    if (step + check() - 1 > maxstep) {
        //cout << "cut" << "\n";
        return;
    }
    int x, y;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (now[i][j] == '*') {x = i; y = j; goto loop;}
    loop:;
    for (int i = 0; i < 8; i++) {
        int tx = x + d[i][0], ty = y + d[i][1];
        if (tx < 0 || tx > 4 || ty < 0 || ty > 4) continue;
        swap(now[x][y], now[tx][ty]);
        dfs(step + 1, maxstep);
        if (ok) return;
        swap(now[x][y], now[tx][ty]);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        //cout << "T=" << T << endl;
        char str[6];
        for (int i = 0; i < 5; i++) {
            cin >> str;
            for (int j = 0; j < 5; j++) s[i][j] = str[j];
        }
        bool flag = false;
        for (int i = 0; i <= 15; i++) {
            memcpy(now, s, sizeof s);
            ok = false;
            dfs(0, i);
            if (ok) {
                cout << i << "\n";
                flag = true;
                break;
            }
        }
        if (!flag) puts("-1");
    }
    //cout << -1 << endl;
    return 0;
}
