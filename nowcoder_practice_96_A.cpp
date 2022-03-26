<<<<<<< HEAD
//
// Created by vv123 on 2022/2/25.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N], n, k;

struct node {
    int mn, mx;
} t[N << 2];

void pushup(int rt) {
    t[rt].mn = min(t[rt << 1].mn, t[rt << 1 | 1].mn);
    t[rt].mx = max(t[rt << 1].mx, t[rt << 1 | 1].mx);
}

void build(int l, int r, int rt) {
    if (l == r) {
        t[rt] = {a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

node query(int a, int b, int l = 1, int r = n, int rt = 1) {
    if (a <= l && r <= b) return {t[rt].mn, t[rt].mx};
    if (l > b || r < a) return {0x3f3f3f3f, 0};
    int mid = l + r >> 1;
    node ls = query(a, b, l, mid, rt << 1);
    node rs = query(a, b, mid + 1, r, rt << 1 | 1);
    return {min(ls.mn, rs.mn), max(ls.mx, rs.mx)};
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    ll ans = 0;
    int r1 = 1, r2 = 1;
    for (int l = 1; l <= n; l++) {
        node q = query(l, r1);
        while (r1 <= n && q.mx - q.mn < k)
            r1++, q = query(l, r1);
        q = query(l, r2);
        while (r2 <= n && q.mx - q.mn <= k)
            r2++, q = query(l, r2);
        if (r1 <= n) ans += r2 - r1;
        else break;
    }
    cout << ans << "\n";
    return 0;
}














=======
//
// Created by vv123 on 2022/2/25.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int a[N], n, k;

struct node {
    int mn, mx;
} t[N << 2];

void pushup(int rt) {
    t[rt].mn = min(t[rt << 1].mn, t[rt << 1 | 1].mn);
    t[rt].mx = max(t[rt << 1].mx, t[rt << 1 | 1].mx);
}

void build(int l, int r, int rt) {
    if (l == r) {
        t[rt] = {a[l], a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

node query(int a, int b, int l = 1, int r = n, int rt = 1) {
    if (a <= l && r <= b) return {t[rt].mn, t[rt].mx};
    if (l > b || r < a) return {0x3f3f3f3f, 0};
    int mid = l + r >> 1;
    node ls = query(a, b, l, mid, rt << 1);
    node rs = query(a, b, mid + 1, r, rt << 1 | 1);
    return {min(ls.mn, rs.mn), max(ls.mx, rs.mx)};
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    ll ans = 0;
    int r1 = 1, r2 = 1;
    for (int l = 1; l <= n; l++) {
        node q = query(l, r1);
        while (r1 <= n && q.mx - q.mn < k)
            r1++, q = query(l, r1);
        q = query(l, r2);
        while (r2 <= n && q.mx - q.mn <= k)
            r2++, q = query(l, r2);
        if (r1 <= n) ans += r2 - r1;
        else break;
    }
    cout << ans << "\n";
    return 0;
}














>>>>>>> eb78ae3d1fc2d4b02f3e542cfe861cef6d785780
