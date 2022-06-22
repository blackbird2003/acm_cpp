//
// Created by vv123 on 2022/4/26.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int n, k, w[N], v[N], delta[N], used[N];
void print(int arr[]) {
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    puts("");
}
multiset<int> s;
int main() {
    long long ans = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]), s.insert(w[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]), ans += v[i];
    //sort(w + 1, w + 1 + n);
    sort(v + 1, v + 1 + n, greater<>());
    memset(delta, 0x3f, sizeof delta);
    for (int i = 1; i <= n; i++) {
        auto it = s.lower_bound(v[i]);
        if (it != s.end()) {
            delta[i] = *it - v[i];
            s.erase(it);
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        while(w[p] >= v[i] && p >= 1) p--;
        if (p < n && !used[p+1]) p++;
        if (p == 1 && w[p] < v[i]) break;
        if (w[p] < v[i]) continue;
        used[p] = 1;
        delta[i] = w[p] - v[i];printf("choose %d for %d\n", w[p], v[i]);
        p--;
    }
     */
    sort(delta + 1, delta + 1 + n);
    //print(delta);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        ans += delta[i];
        if (delta[i] == INF) cnt++;
    }
    if (cnt > k) puts("NIE");
    else {
        for (int i = max(1, n - k + 1); i <= n; i++)
            ans -= delta[i];
        printf("%lld\n", ans);
    }
    return 0;
}