//
// Created by vv123 on 2022/5/31.
//
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
map<string, int> score0, score1;
map<string, bool> vis, vis0, vis1;
void calc(string st) {
    if (vis[st]) return;
    score0[st] = 0;score1[st] = 0; vis[st] = 1;
    if (st[0] == st[1] && st[1] == st[2]) score0[st] += st[0] == 'O' ? 1 : -1, score1[st] += st[0] == 'O' ? 1 : -1;
    if (st[3] == st[4] && st[4] == st[5]) score0[st] += st[3] == 'O' ? 1 : -1, score1[st] += st[3] == 'O' ? 1 : -1;
    if (st[6] == st[7] && st[7] == st[8]) score0[st] += st[6] == 'O' ? 1 : -1, score1[st] += st[6] == 'O' ? 1 : -1;
    if (st[0] == st[3] && st[3] == st[6]) score0[st] += st[0] == 'O' ? 1 : -1, score1[st] += st[0] == 'O' ? 1 : -1;
    if (st[1] == st[4] && st[4] == st[7]) score0[st] += st[1] == 'O' ? 1 : -1, score1[st] += st[1] == 'O' ? 1 : -1;
    if (st[2] == st[5] && st[5] == st[8]) score0[st] += st[2] == 'O' ? 1 : -1, score1[st] += st[2] == 'O' ? 1 : -1;
    if (st[0] == st[4] && st[4] == st[8]) score0[st] += st[4] == 'O' ? 1 : -1, score1[st] += st[4] == 'O' ? 1 : -1;
    if (st[2] == st[4] && st[4] == st[6]) score0[st] += st[4] == 'O' ? 1 : -1, score1[st] += st[4] == 'O' ? 1 : -1;
}
int dfs(string st, int type) {
    if (type == 0) {
        if (vis0[st]) return score0[st];
        else score0[st] = -inf;
    }
    if (type == 1) {
        if (vis1[st]) return score1[st];
        else score1[st] = -inf;
    }
    char now = type == 0 ? 'X' : 'O';
    //printf("st:%s now:%c\n", st.c_str(), now);
    bool flag = false;//还有没有空余位置
    for (int i = 0; i < 9; i++) {
        if (st[i] == '.') {
            string nst = st;
            nst[i] = now;
            if (type == 0) score0[st] = max(score0[st], dfs(nst, 1 - type));
            else score1[st] = max(score1[st], dfs(nst, 1 - type));
            flag = true;
        }
    }
    if (!flag) {
        calc(st);
    }
    if (type == 0) {
        vis0[st] = 1;
        return score0[st];
    }
    else {
        vis1[st] = 1;
        return score1[st];
    }
}

void solve() {
    char str[10]; int type;
    cin >> type;
    string init;
    for (int i = 0; i < 3; i++) {
        cin >> str;
        init += str;
    }
    cout << dfs(init, type) << "\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}

