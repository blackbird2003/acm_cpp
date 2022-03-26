#include <bits/stdc++.h>
#define io_optimization() ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
const int N = 1e5 + 10;
int n, q, a[N], t[N << 2];

void build(int l, int r, int rt) {
    if (l == r) {
        t[rt] = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    t[rt] = max(t[rt << 1], t[rt << 1 | 1]);
}

// to find st
int query(int a, int b, int l = 1, int r = n, int rt = 1) {
    if (a <= l && r <= b)
        return t[rt];
    if (a > r || b < l) 
        return 0;
    int mid = l + r >> 1;
    return max(query(a, b, l, mid, rt << 1), query(a, b, mid + 1, r, rt << 1 | 1));
}

int main() {
    io_optimization();
    cin >> n >> q;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    build(1, n, 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }
    return 0;
}