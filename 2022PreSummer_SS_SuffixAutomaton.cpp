//
// Created by vv123 on 2022/6/10.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 10;
const int SIZE = 26;


struct Node {
    int len, fa;
    int t[SIZE];
};
struct SAM {
    char str[N];
    Node node[N];
    int idx = 1, last = 1;
    LL f[N];

    void extend(int c) {
        int p = last, np = last = ++idx;
        while (p && !node[p].t[c])
            node[p].t[c] = np, p = node[p].fa;
        if (!p) node[np].fa = 1;
        else {
            int q = node[p].t[c];
            if (node[q].len = node[p].len + 1) node[np].fa = q;
            else {
                int nq = ++idx;
                node[nq] = node[q]; node[nq].len = node[np].len + 1;
                node[q].fa = node[np].fa = nq;
                while (p && node[p].t[c] == q)
                    node[p].t[c] = nq, p = node[p].fa;
            }
        }
    }
    void solve() {
        for (int i = 0; str[i]; i++)
            extend(str[i] - 'a');
    }
} sam;


int main() {
    cin >> sam.str;
    sam.solve();
    return 0;
}

