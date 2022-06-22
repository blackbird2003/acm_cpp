//
// Created by vv123 on 2022/4/24.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define getchar() (frS==frT&&(frT=(frS=frBB)+fread(frBB,1,1<<15,stdin),frS==frT)?EOF:*frS++)
char frBB[1<<15],*frS=frBB,*frT=frBB;
template<typename T>
inline void read(T &x){
    x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
}

const int N = 4e5 + 10;
const int mod = 998244353;

int n, m, a[N];
ll add[N], mul[N], sum[N];
#define mid (l+r>>1)
#define len (r-l+1)
#define llen (mid-l+1)
#define rlen (r-mid)
#define ls (i<<1)
#define rs (i<<1|1)
#define allin s <= l && r <= t  //[s,t]与[l,r]一定有交集，只需考虑三种情况
#define lsin s <= mid
#define rsin t >= mid + 1

inline void pushup(int i) {
    sum[i] = (sum[ls] + sum[rs]) % mod;
}
inline void pushdown(int l, int r, int i) {//mul/add/sum依次下传
    if (mul[i] != 1) {
        (mul[ls] *= mul[i]) %= mod; (mul[rs] *= mul[i]) %= mod;
        (add[ls] *= mul[i]) %= mod; (add[rs] *= mul[i]) %= mod;
        (sum[ls] *= mul[i]) %= mod; (sum[rs] *= mul[i]) %= mod;
        mul[i] = 1;
    }
    if (add[i]) {
        (sum[ls] += add[i] * llen) %= mod; (sum[rs] += add[i] * rlen) %= mod;
        (add[ls] += add[i]) %= mod; (add[rs] += add[i]) %= mod;
        add[i] = 0;
    }
}
void Build(int l, int r, int i) {
    mul[i] = 1;
    if (l == r) { sum[i] = a[l]; return; }
    Build(l, mid, ls); Build(mid + 1, r, rs);
    pushup(i);
}
void Add(int s, int t, int l, int r, int i, int k) {
    if (allin) {
        (sum[i] += k * len) %= mod;
        (add[i] += k) %= mod;
        return;
    }
    pushdown(l, r, i);
    if (lsin) Add(s, t, l, mid, ls, k);
    if (rsin) Add(s, t, mid + 1, r, rs, k);
    pushup(i);
}
void Mul(int s, int t, int l, int r, int i, int k) {
    if (allin) {
        (add[i] *= k) %= mod;
        (mul[i] *= k) %= mod;
        (sum[i] *= k) %= mod;
        return;
    }
    pushdown(l, r, i);
    if (lsin) Mul(s, t, l, mid, ls, k);
    if (rsin) Mul(s, t, mid + 1, r, rs, k);
    pushup(i);
}
ll Query(int s, int t, int l, int r, int i) {
    ll res = 0;
    if (allin) return sum[i];
    pushdown(l, r, i);
    if (lsin) (res += Query(s, t, l, mid, ls)) %= mod;
    if (rsin) (res += Query(s, t, mid + 1, r, rs)) %= mod;
    return res;
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    Build(1, n, 1);
    while(m--) {
        int op, s, t, k;
        read(op); read(s); read(t);
        if (op == 1) {
            read(k); Mul(s, t, 1, n, 1, k);
        } else if (op == 2) {
            read(k); Add(s, t, 1, n, 1, k);
        } else {
            printf("%lld\n", Query(s, t, 1, n, 1));
        }
    }
    return 0;
}
