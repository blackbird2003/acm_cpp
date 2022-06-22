//
// Created by vv123 on 2022/4/25.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int a[N], val[N], n, m, t, L[N], R[N], pos[N], ans[N];
struct query {
    int l, r, block, id;
    bool operator < (const query& x) const {
        if (block != x.block) return block < x.block;//左端点所在区间
        else return r < x.r;
    }
} q[N];
inline void LiSanHua() {
    for (int i = 1; i <= n; i++)
        val[i] = a[i];
    sort(val + 1, val + 1 + n);
    m = unique(val + 1, val + 1 + n) - 1 - val;
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(val + 1, val + 1 + m, a[i]) - val;
}
inline void init_block() {
    t = sqrt(n);
    for (int i = 1; i <= t; i++) {
        L[i] = (i - 1) * t + 1;
        R[i] = i * t;
    }
    if (R[t] < n)
        t++, L[t] = R[t - 1] + 1, R[t] = n;
    for (int i = 1; i <= n; i++)
        for (int j = L[i]; j <= R[i]; j++)
            pos[j] = i;
}
int __cnt[N];
int bruteforce(int l, int r) {
    int max_cnt = 0, max_id = N;
    for (int i = l; i <= r; i++) ++__cnt[a[i]];
    for (int i = l; i <= r; i++) {
        if (__cnt[a[i]] > max_cnt || (__cnt[a[i]] == max_cnt && a[i] < max_id))
            max_id = a[i], max_cnt = __cnt[a[i]];
    }
    for (int i = l; i <= r; i++) --__cnt[a[i]];
    return max_id;
}
int ccnt[N], cnt[N], max_cnt = 0, max_id = N;//ccnt记录某个计数出现了几次
void add(int c) {
    ccnt[cnt[c]]--;
    cnt[c]++;
    ccnt[cnt[c]]++;
    if (cnt[c] > max_cnt || (cnt[c] == max_cnt && c < max_id)) {
        max_id = c;
        max_cnt = cnt[c];
    }
}
void del(int c) {
    ccnt[cnt[c]]--;
    if (cnt[c] == max_cnt && ccnt[cnt[c]] == 0) max_cnt--;//max_cnt一定是连续的。max_id在拓展左端点前保存即可。
    cnt[c]--;
    ccnt[cnt[c]]++;
}
void print(int arr[]) {
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    puts("");
}
inline void MoDui() {
    /*
     莫队区间[pl,pr]，询问区间[l,r]
     如果访问到了新块b，则莫队区间初始化为[R[b]+1, R[b]]
     [l,r]在同一块内，则暴力扫描
     [l,r]在不同块内，将[pl,pr]拓展为[l,r]，然后将pl回滚到R[b]+1
     */
    int pl = 1, pr = 0, last_block = 0;
    for (int i = 1; i <= n; i++) {
        int l = q[i].l, r = q[i].r, id = q[i].id;//printf("%d %d %d %d\n", l, r, q[i].block, q[i].id);
        if (pos[l] == pos[r]) {
            ans[id] = bruteforce(l, r);
            continue;
        }
        if (pos[l] != last_block) {
            while (pr > R[pos[l]]) del(a[pr--]);
            while (pl < R[pos[l]] + 1) del(a[pl++]);
            max_cnt = 0, max_id = N;
            last_block = pos[l];
        }
        //右端点有序，左端点每次从回滚点向左拓展
        //精髓在于，我们查询答案时，只会add而不会del
        while (pr < r) add(a[++pr]);
        int __pl = pl, tmp = max_id;//因为我们还会回到这个状态，因此只需暂存max_id即可
        while (__pl > l) add(a[--__pl]);
        ans[id] = max_id;
        while (__pl < pl) del(a[__pl++]);//滚回R[b]+1
        max_id = tmp;//滚回tmp
    }
};
signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    LiSanHua();//print(a); print(val);//原谅我这不厚道的命名
    init_block();
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%lld%lld", &l, &r);
        q[i] = {l, r, pos[l], i};
    }
    sort(q + 1, q + 1 + n);
    MoDui();
    for (int i = 1; i <= n; i++)
        printf("%lld\n", val[ans[i]]);
    return 0;
}
