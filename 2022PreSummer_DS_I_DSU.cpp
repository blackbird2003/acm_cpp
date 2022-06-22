//
// Created by vv123 on 2022/4/24.
//
#include <bits/stdc++.h>
#define swap(x,y) x^=y^=x^=y
using namespace std;
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
int f[N], s[N];

inline void init(int n) { for (int i = 1; i <= n; i++) f[i] = i, s[i] = 1; }
int find(int x) { return x == f[x] ? f[x] : f[x] = find(f[x]); }
inline void merge(int fx, int fy) {
    if (fx == fy) return;
    if (s[fx] > s[fy]) swap(fx, fy);
    f[fx] = fy; s[fy] += s[fx];
}

#define getchar() (frS==frT&&(frT=(frS=frBB)+fread(frBB,1,1<<15,stdin),frS==frT)?EOF:*frS++)
char frBB[1<<15],*frS=frBB,*frT=frBB;
template<typename T>
inline void read(T &x){
    x=0;char c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
}


int main() {
    int n, m, ans = 0;
    read(n); read(m); init(n);
    while (m--) {
        int op, x, y;
        read(op); read(x); read(y);
        int fx = find(x), fy = find(y);
        op & 1 ? merge(fx, fy) : (void)(ans = (ans << 1) + (fx == fy));
        if (ans >= mod) ans -= mod;
    }
    printf("%d\n", ans);
    return 0;
}
