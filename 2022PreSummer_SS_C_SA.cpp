//
// Created by vv123 on 2022/5/25.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int inf = 0x3f3f3f3f;


int a1[N], a2[N], a[N];
int sa[N], rk[N], height[N];

int c[N], t1[N], t2[N];
int plain[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void build_sa(int n, int m) {
    int *x = t1, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = a[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int p = 0;
        for (int i = n - k; i < n; i++) y[p++] = i;
        for (int i = 0; i < n; i++) if (sa[i] >= k) y[p++] = sa[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 0; i < m; i++) c[i] += c[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i];
        swap(x, y);
        p = 0; x[sa[0]] = 0;
        for (int i = 1; i < n; i++)
            x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
        if (p >= n) break;
        m = p;
    }
    for (int i = 0; i < n; i++) rk[sa[i]] = i;
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (a[i + k] == a[j + k]) k++;
        height[rk[i]] = k;
    }
}
int main() {
    int n,  m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a1[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a2[i];
    for (int i = 0; i < n; i++) a[i] = a1[i + 1];
    a[n] = 1001;
    for (int i = n + 1; i <= n + m; i++) a[i] = a2[i - n];
    a[n + m + 1] = 1001;

    build_sa(n + m + 2, 1002);//char range: 0~1001
    /*
    for (int i = 0; i < n + m + 2; i++) cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < n + m + 2; i++) cout << sa[i] << " ";
    cout << "\n";
    for (int i = 0; i < n + m + 2; i++) cout << rk[i] << " ";
    cout << "\n";
     */
    // 0...n-1 : n+1 ... n+m :
    int p1 = 0, p2 = n + 1;

    while (p1 <= n - 1 && p2 <= n + m) {
        if (rk[p1] < rk[p2]) cout << a[p1++] << " ";
        else cout << a[p2++] << " ";
    }
    while (p1 <= n - 1) cout << a[p1++] << " ";
    while (p2 <= n + m) cout << a[p2++] << " ";
    return 0;
}


