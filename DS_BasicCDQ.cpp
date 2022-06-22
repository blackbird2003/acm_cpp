//
// Created by vv123 on 2022/4/29.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
int n, m;
long long t[N], ans[N];
void add(int i, int x) {
    for (; i <= n; i += i & -i)
        t[i] += x;
}
long long sum(int i) {
    long long res = 0;
    for (; i; i -= i & -i)
        res += t[i];
    return 0;
}
struct node {
    int op, pos, val;
    bool operator < (const node& x) {
        if (pos != x.pos) return pos < x.pos;
        else return op < x.op;
    }
} a[N], b[N];
//操作可以总结为两种：1.把一个位置的数+k 2.查询一个位置的前缀和
//类比归并排序的合并过程
//我们最终把所有操作按位置先后进行了排序
//归并的过程有如下特征：
//1.左右子区间都是关于位置单调的
//2.左子区间的时间都比右子区间靠前
//因此，我们按位置顺序合并左右子区间，遇到查询前缀和的时候可以保证改修改的已经修改完了
////注意：我们考察的是左子区间对右子区间查询操作的“贡献”
//并不是直接由左子区间算出“答案”
//对右子区间的某个询问，在右子区间内部也有某些修改对其产生了贡献
//而这个贡献在之前已经递归计算过了
void CDQ(int l, int r) {    //处理操作[l,r]
    if (l == r) return;
    int mid = l + r >> 1;
    CDQ(l, mid); CDQ(mid + 1, r);
    int p1 = l, p2 = mid + 1;
    long long sum = 0;
    for (int i = l; i <= r; i++) {
        if ((p1 <= mid && a[p1] < a[p2]) || p2 > r) {
            if (a[p1].op == 1) sum += a[p1].val;
            b[i] = a[p1++];
        } else {
            if (a[p2].op == 2) ans[a[p2].val] -= sum;
            if (a[p2].op == 3) ans[a[p2].val] += sum;
            b[i] = a[p2++];
        }
    }
    for (int i = l; i <= r; i++) a[i] = b[i];
}

int main() {
    cin >> n >> m;
    int op, x, y;
    int cnt = n, tot = 0;//总操作数和询问次序
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[i] = {1, i, x};
    }
    for (int i = 1; i <= m; i++) {
        cin >> op >> x >> y;
        if (op == 1) {
            a[++cnt] = {1, x, y};
        } else {
            tot++;
            a[++cnt] = {2, x - 1, tot};
            a[++cnt] = {3, y, tot};
        }
    }
    CDQ(1, cnt);
    for (int i = 1; i <= tot; i++)
        cout << ans[i] << endl;
    return 0;
}
/*
1 1 1 1
2 1 2 5
3 1 3 4
4 1 4 2
5 1 5 3
6 1 1 3
7 2 1 1
8 3 5 1
9 1 3 -1
10 1 4 2
11 2 0 2
12 3 4 2
 */
