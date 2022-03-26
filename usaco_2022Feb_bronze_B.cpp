<<<<<<< HEAD
//
// Created by vv123 on 2022/2/26.
//
#include <bits/stdc++.h>
using namespace std;
int n, a[100010], b[100010], pos[100010], d[100010];
int t[900010];
void add(int i, int x) {
    for(; i <= n; i += i & -i)
        t[i] += x;
}
int sum(int i) {
    int res = 0;
    for (; i; i -= i & -i)
        res += t[i];
    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        pos[t] = i;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = pos[a[i]];
    }

    int ans = 0; int mx = a[1];
    for (int i = 1; i <= n; i++) {
        if (a[i] < mx) ans++;
        mx = max(mx, a[i]);
    }
    cout << ans << "\n";
    return 0;
}
=======
//
// Created by vv123 on 2022/2/26.
//
#include <iostream>
using namespace std;
int n, a[100010], b[100010], pos[100010], d[100010];

int lis() {
    d[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>d[len])
            d[++len]=a[i];
        else
        {
            int j=lower_bound(d+1,d+len+1,a[i])-d;
            d[j]=a[i];
        }
    }
    return len;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        pos[t] = i;
    }
    for (int i = 1; i <= n; i++)
        a[i] = pos[a[i]];

    cout << n - lis() << "\n";
    return 0;
}
>>>>>>> eb78ae3d1fc2d4b02f3e542cfe861cef6d785780
