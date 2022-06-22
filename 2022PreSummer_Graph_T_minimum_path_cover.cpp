//
// Created by vv123 on 2022/4/22.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m, match[N], book[N];
vector<int> g[N];

int find(int u) {
    for (auto v:g[u]) {
        if (!book[v]) { //book数组在对每一个男主开启dfs前都会清零，表示在本次尝试中，这名女主是否已经被别人（别人既可能是main里的u也可是递归产生的u），当前的u只能从被book剩下的当中选（这时这名女主没有book，但可能有了match，可以尝试让它之前match的男主另寻所爱，腾给当前的u）
            book[v] = 1;
            if (!match[v] || find(match[v])) {  //如果v单身，或者给v的原配找到了另一个女友，那v的现任就为u
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}



int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(book, 0, sizeof book);
        if (find(i)) cnt++;
    }
    cout << n - cnt << endl;
    return 0;
}
