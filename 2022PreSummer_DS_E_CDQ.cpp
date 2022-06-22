//
// Created by vv123 on 2022/4/30.
//
//逆序对的产生条件为:timej > timei, posj > posi, valj < vali
//或者:timej > timei, posj < posi, valj > vali
//CDQ前序列按时间有序，进行归并时，右区间的timej一定大于左区间，无需考虑。只需按pos的某种顺序合并，在"入队"时统计有多少符合对应条件的vali即可
//方便起见，做两次CDQ
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, pos[N];
long long t[N], ans[N];
void add(int i, int x) {
    for (; i <= n; i += i & -i)
        t[i] += x;
}
long long sum(int i) {
    long long res = 0;
    for (; i; i -= i & -i)
        res += t[i];
    return res;
}
struct node {
    int time, pos, val;
    bool operator < (const node& x) const {
        return time < x.time;
    }
} a[N], b[N];

void CDQ1(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1, i = l, j = mid + 1, k = l - 1;
    CDQ1(l, mid); CDQ1(mid + 1, r);
    while (i <= mid && j <= r) {
        if (a[i].pos < a[j].pos) {
            add(a[i].val, 1);
            b[++k] = a[i++];
        } else {//考虑j前面比它大的数的贡献
            ans[a[j].time] += sum(n) - sum(a[j].val);
            b[++k] = a[j++];
        }
    }
    while (i <= mid) {
        add(a[i].val, 1);//没用，但是方便恢复qwq。如果memset(t, 0, sizeof t)，至少第二层就有O(N)个区间,N^2肯定会T的。。
        b[++k] = a[i++];
    }
    while (j <= r) {
        ans[a[j].time] += sum(n) - sum(a[j].val);
        b[++k] = a[j++];
    }
    for (int p = l; p <= mid; p++) add(a[p].val, -1);
    for (int p = l; p <= r; p++) a[p] = b[p];
}

void CDQ2(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1, i = l, j = mid + 1, k = l - 1;
    CDQ2(l, mid); CDQ2(mid + 1, r);
    while (i <= mid && j <= r) {
        if (a[i].pos > a[j].pos) {
            add(a[i].val, 1);
            b[++k] = a[i++];
        } else {//考虑j后面比它小的数的贡献(按pos从大到小入队，即为已有的val)
            ans[a[j].time] += sum(a[j].val - 1);
            b[++k] = a[j++];
        }
    }
    while (i <= mid) {
        add(a[i].val, 1);
        b[++k] = a[i++];
    }
    while (j <= r) {
        ans[a[j].time] += sum(a[j].val - 1);
        b[++k] = a[j++];
    }
    for (int p = l; p <= mid; p++) add(a[p].val, -1);
    for (int p = l; p <= r; p++) a[p] = b[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = {i, pos[x], x};
    }
    CDQ1(1, n);
    sort(a + 1, a + 1 + n);
    CDQ2(1, n);
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << "\n";
    }
    return 0;
}



