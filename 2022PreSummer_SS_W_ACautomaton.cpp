//
// Created by vv123 on 2022/5/30.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 10, MAXP = 2e5 + 10, MAXS = 2e6 + 10, SIZE = 26;
//MAXP:max sum of len(p)

struct AC {
    int t[MAXP][SIZE];
    int f[MAXP];     //失配指针
    int pid[MAXP];   //单词结尾标志
    int last[MAXP];  //fail路上下一个单词结尾的编号。对于每个i,都会尽量匹配trie树，以不同i结尾统计到的单次一定是不同位置的。
    int cnt[MAXN];
    int sz;

    void init() {
        sz = 1;
        memset(t[0], 0, sizeof(t[0]));
        memset(cnt, 0, sizeof(cnt));
    }

    void insert(char* s, int id) {
        int u = 0, n = strlen(s);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (!t[u][c]) {
                memset(t[sz], 0, sizeof(t[sz]));
                pid[sz] = 0;
                t[u][c] = sz++;
            }
            u = t[u][c];
        }
        pid[u] = id;
    }

    void upd(int j) {
        if (j) {
            cnt[pid[j]]++;
            upd(last[j]);
        }
    }

    int find(char* s) {
        int n = strlen(s);
        int j = 0;
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            //while (j && !t[j][c]) j = f[j];//一种优化是，我们在getfail中将t[x][c]直接连向了t[f[x]（或多次）][c]。
            j = t[j][c];
            if (pid[j]) upd(j);
            else if (last[j]) upd(last[j]);
        }
    }

    void getfail() {
        queue<int> q;
        for (int c = 0; c < SIZE; c++) {
            int u = t[0][c];
            if (u) { f[u] = 0, q.push(u), last[u] = 0; }
        }
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int c = 0; c < SIZE; c++) {
                int u = t[x][c];
                if (!u) {
                    t[x][c] =  t[f[x]][c];
                    continue;
                }
                q.push(u);
                int v = f[x];
                while (v && !t[v][c]) v = f[v];
                f[u] = t[v][c];
                last[u] = pid[f[u]] ? f[u] : last[f[u]];
            }
        }
    }
} ac;

char s[MAXS], p[MAXP];
int n;
map<string, int> fst;
int belong[MAXN];

int main() {
    cin >> n;
    ac.init();
    for (int i = 1; i <= n; i++) {
        cin >> p;
        if (fst[p] == 0) { fst[p] = i; belong[i] = i;}
        else { belong[i] = fst[p]; continue; }
        ac.insert(p, i);
    }
    ac.getfail();
    cin >> s;
    ac.find(s);
    for (int i = 1; i <= n; i++)
        cout << ac.cnt[belong[i]] << "\n";
    return 0;
}



