//
// Created by vv123 on 2022/3/6.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e4 + 10;
int n, m, a[N], t[N], last[N], ans[N];
struct Query {
    int l, r, id;
    bool operator < (const Query &x) const {
        return r < x.r;
    }
} q[N];

void add(int i, int x) {
    for (; i <= n; i += i & -i)
        t[i] += x;
}

int sum(int i) {
    int res = 0;
    for(; i; i -= i & -i)
        res += t[i];
    return res;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m);
    int p = 1;
    for (int i = 1; i <= n; i++) {
        if (last[a[i]]) add(last[a[i]], -1);
        last[a[i]] = i;
        add(i, 1);
        while(q[p].r == i) {
            ans[q[p].id] = sum(q[p].r) - sum(q[p].l - 1);
            p++;
        }
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << "\n";
    return 0;
}

