[TOC]



# A-代码查重 解题报告



## 题目大意

<img src="C:\Users\vv123\AppData\Roaming\Typora\typora-user-images\image-20220517103531747.png" alt="image-20220517103531747" style="zoom: 67%;" />

![image-20220517103547197](C:\Users\vv123\AppData\Roaming\Typora\typora-user-images\image-20220517103547197.png)

$n \le  5000$



## 解题思路

尝试用类似求LCS的方法求出**考虑了**A(1..i) B(1..j)的f(a,b)最大值dp(i,j)

当Ai != Bj时

dp(i,j)可以从dp(i-1, j)转移过来，还要减去y

dp(i,j)可以从dp(i, j-1)转移过来，还要减去z

如果Ai == Bj

dp(i,j)可以从dp(i-1, j-1)转移过来，还要加上x-y-z

但是这样做求出的是A和B的”**前缀子串**“而非”**任意子串**“的答案，中间可能出现很多”累赘“使得答案总是小于零。

因此，我们需要**在每一个位置尝试丢弃前面的子串**

即用-y-z（如果Ai!=Bj）和 x-y-z(如果Ai==Bj)来更新dp(i,j)。

这样就涵盖了任意子串的答案。对所有的dp(i,j)取max，即为所求的重合度。

## 代码实现

```cpp
//
// Created by vv123 on 2022/5/17.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
long long n, m, x, y, z, dp[N][N];
char A[N], B[N];
void solve() {
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j] - y, dp[i][j - 1] - z), dp[i - 1][j - 1] - y - z);
            if (A[i] == B[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + x - y - z);
            dp[i][j] = max(dp[i][j], -y - z);
            if (A[i] == B[j]) dp[i][j] = max(dp[i][j], x - y - z);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}

int main() {
    cin >> n >> m >> x >> y >> z >> A + 1 >> B + 1;
    solve();
    return 0;
}
```

# B-下棋 解题报告



## 题目大意

一个n*n棋盘，每个位置有一个分数，Alice和Bob轮流放置棋子并得到相应分数，每次放置的位置与上次的曼哈顿距离必须大于m（一个位置可以多次放）。求Alice先手在哪些位置下第一步棋必胜（下棋$2^{2022}$回合后得分高的人获胜）。

$n \le  2000$



## 解题思路

首先最大的点一定是先手必胜点，因为Alice可以一直下这个位置， 而Bob只能选到小于它的点。

推广一下，如果Alice选了一个位置以后，Bob**可以选到先手必胜的位置**，则Bob必胜，否则Alice必胜。因此先手必胜点就是满足**所有先手必胜点都在曼哈顿距离不超过m的范围内**的点。

我们首先将最大点置为先手必胜点。依次检查次大点、第三大点.......是否满足”已有先手必胜点都在它的占领域内“。

一开始的想法是，把已有的先必胜点存在vector里，每次遍历vector看有没有曼哈顿距离大于m的，这样时间复杂度是$O(n^3)$的。

考虑优化,对于当前的点(i,j),我们只需要**检查现有必胜点与(i,j)曼哈顿距离的最大值是否大于m**即可，为了$O(1)$求出这个最大值，可以借助曼哈顿距离变换公式：

$|x-i|+|y-j|=max(|(x+y) - (i+j)|, |(x-y)+(i-j)|)$

考虑绝对值的几何意义，容易知道可能取到max的点，它的(x+y)或(x-y)一定是目前最大或最小的。

因此我们只需要记录先手必胜点(x+y)和(x-y)的最大值和最小值，对四个结果取一个max，得到的一定是现有先手必胜点离(i, j)的曼哈顿距离的最大值。

这样，总的时间复杂度为$O(n^2)$。

(其实好像就和dp没啥关系了)

## 代码实现

```cpp
//
// Created by vv123 on 2022/5/16.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
const int inf = 0x3f3f3f3f;
int a[N][N], n, m;
struct point {
    int x, y, w;
    bool operator < (const point& x) const {
        return w > x.w;
    }
} p[N * N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], p[(i - 1) * n + j] = {i, j, a[i][j]};
    sort(p + 1, p + 1 + n * n);
    int minp, maxp, minm, maxm;
    vector<pair<int, int> > ans;
    for (int i = 1; i <= n * n; i++) {
        int x = p[i].x, y = p[i].y, w = p[i].w, np = x + y, nm = x - y;
        int farest = max(max(abs(np - minp), abs(np - maxp)), max(abs(nm - minm), abs(nm - maxm)));
        //printf("(%d, %d):%d, np=%d, nm=%d\n", x, y, w, np, nm);
        //cout << "The farest is " << farest << ", ";
        if (i == 1) {
            //puts("YES");
            ans.push_back({x, y});
            minp = maxp = x + y;
            minm = maxm = x - y;
        } else if (farest <= m){
            //puts("YES");
            ans.push_back({x, y});
            minp = min(minp, x + y);
            maxp = max(maxp, x + y);
            minm = min(minm, x - y);
            maxm = max(maxm, x - y);
        } //else puts("NO");
        //printf("now maxp=%d, minp=%d, maxm=%d\n", maxp, minp, maxm);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto u : ans) cout << u.first << " " << u.second << "\n";
    return 0;
}

```

# D-交互问题 解题报告



## 题目大意

一个环被m个点均分，有3根指针指向这些点，起始位置s1、s2、s3，需要依次拨动某一个指针使其指向第a1，a2，...，an个点，不能连续两次拨动同一个指针（拨动距离为0也算拨动）。求拨动的最小总距离。

$n,m \le  3000$



## 解题思路

考虑朴素dp：

$dp[i][x][y][z]$表示处理完ai之后，且三根指针此时分别指向x、y、z的情况下，拨动所需最少距离。

很多无效情况：

- 一定有一个指针指向$a[i]$

- 从i=2开始，一定有一个指针指向$a[i-1]$。

- 可以忽略指针的次序。

可以简化成这样：

$dp[i][j]$（i≥2）表示处理完$a[i]$后，三个指针分别指向$a[i]$，$a[i-1]$,$j$ 的情况下，拨动所需的最小距离。

首先求出$dp[2][j]$      

暴力枚举s1,s2,s3的六种排列{p1,p2,p3}

$dp[2][j] = min(dis(a[1], p1)+dis(a[2],p2)+dis(j,p3))$

对于第$i$轮，考虑从$dp[i-1][j]$转移，指针的起始位置为$a[i-1],a[i-2],j$，则有：

- 指向$a[i-1]$的指针不能动

- 指向$a[i-2]$的指针可以指向$a[i]$，剩下$j$

  $dp[i][j]=min( dp[i][j], dp[i-1][j]+dis(a[i-2],a[i])  )$。

- 指向$j$的指针可以指向$a[i]$，剩下$a[i-2]$

  $dp[i][a[i-2]]=min(dp[i][a[i-2]], dp[i-1][j]+dis(j,a[i]) )$。

答案为$\min(dp[n][j]),(j∈[1,m])$。

时间复杂度$O(nm)$。

## 代码实现

```cpp
//
// Created by vv123 on 2022/5/20.
//
#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N =  3010;
const int inf = 0x3f3f3f3f;
int n, m, s1, s2, s3, a[N], dp[N][N];
int dis(int i, int j) {
    return min(abs(i - j), m - abs(i - j));
}
signed main() {
    cin >> n >> m >> s1 >> s2 >> s3;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int p[6][3] = {
            {s1, s2, s3},
            {s1, s3, s2},
            {s2, s1, s3},
            {s2, s3, s1},
            {s3, s1, s2},
            {s3, s2, s1}
    };
    memset(dp, 0x3f, sizeof dp);
    for (int j = 1; j <= m; j++) {
        for (int k = 0; k < 6; k++) {
            dp[2][j] = min(dp[2][j], dis(a[1], p[k][0]) + dis(a[2], p[k][1]) + dis(j, p[k][2]));
            //printf("k=%d, dp[2][%d]=%d\n", k, j, dp[2][j]);
        }
        //for (int j = 1; j <= m; j++) printf("dp[%d][%d]=%d\n", 2, j, dp[2][j]);
        //printf("dp[2][%d]=%d\n", j, dp[2][j]);
    }
    int ans = inf;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + dis(a[i - 2], a[i]));
            dp[i][a[i - 2]] = min(dp[i][a[i - 2]], dp[i - 1][j] + dis(j, a[i]));
        }
        //for (int j = 1; j <= m; j++) printf("dp[%d][%d]=%d\n", i, j, dp[i][j]);
    }
    for (int j = 1; j <= m; j++)
        ans = min(ans, dp[n][j]);
    cout << ans << endl;
    return 0;
}


```

# H-矿物储量不足 解题报告



## 题目大意

给定一个树，每个节点有+1和-1两种权值，对每一个点，求出包含该点的连通块最大权值和。

$n \le  2 \times 10^5$



## 解题思路

如果连通块只包含当前的点和子树中的部分点，则为简单的树上"最大子段和"，可以在dfs回溯的过程中贪心统计出来:

f1(u) += f1(v),（v是u的子节点且f1(v) >= 0）。

我们求出上述子问题的答案f1(x)后，考虑从每个节点来自祖先的贡献。

设最终答案为f2(x)

初始化f2=f1。从根节点向下dfs。

如果f1(u) < 0,说明f1(u)没有被包含在f2(fa)中,那么可以用f1(u) + f2(fa)更新f2(u)

如果f1(u) >= 0,说明f1(u)已经被包含在f2(fa)中，那么只需用f2(fa)更新f2(u)

时间复杂度为O(n)

## 代码实现

```cpp
//
// Created by vv123 on 2022/5/17.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int f1[N], f2[N], n;
vector<int> g[N];
void dfs1(int u, int fa) {
    //printf("u=%d\n", u);
    for (auto v : g[u]) {
        if (v != fa) dfs1(v, u);
    }
    for (auto v : g[u]) {
        if (v == fa) continue;
        if (f1[v] >= 0) f1[u] += f1[v];
        //printf("f1[%d] += f1[%d] become %d\n", u, v, f1[u]);
    }
}

void dfs2(int u, int fa) {
    if (!fa) f2[u] = f1[u];
    else {
        if (f1[u] < 0) f2[u] = max(f1[u], f2[fa] + f1[u]);
        else f2[u] = max(f1[u], f2[fa]);
    }
    for (auto v : g[u]) {
        if (v != fa) dfs2(v, u);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        f1[i] = t ? 1 : -1;
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        cout << f2[i] << " ";
    return 0;
}
```

# I-故意找茬是吧 解题报告



## 题目大意

<img src="C:\Users\vv123\AppData\Roaming\Typora\typora-user-images\image-20220509201622442.png" alt="image-20220509201622442" style="zoom: 50%;" />

给定一个序列，q次询问区间[l,r]，求$\max\limits_{l\le i \le j \le r}f(a_{i\dots j})$。

$n\le 5000,q\le 10^5$。



## 解题思路

我们发现给出的第二个式子是递归的，尝试找规律

$f(a_1,a_2)=a_1 \oplus a_2=f(a_1) \oplus f(a_2)$

$f(a_1,a_2,a_3)=(a_1 \oplus a_2) \oplus (a_2\oplus a_3) = f(a_1,a_2) \oplus f(a_2, a_3)$  

$f(a_1,a_2,a_3,a_4)=(a_1 \oplus a_2) \oplus (a_2\oplus a_3) \oplus (a_3 \oplus a_4)=(a_1 \oplus a_3) \oplus(a_2 \oplus a_4)=f(a_1,a_2,a_3) \oplus f(a_2, a_3, a_4)$

$f(a_1,a_2,a_3,a_4,a_5)=\dots=f(a_1,a_2,a_3,a_4) \oplus f(a_2, a_3, a_4,a_5)$

$\dots\dots$

即$f(i,j) = f(i+1,j) \oplus f(i,j-1)$，可以用区间DP，$O(n^2)$求出所有的$f(i,j)$

如何求任意区间的子区间最大值？

只需从小区间推大区间，自然想到下面的区间DP：

对于区间[l,r]，要么选[l,r]，要么不选(答案就可以由两个小区间合并)

$$ ans(i,j)=\max(f(i,j),ans(i+1,j),ans(i,j-1))$$

预处理时间复杂度$O(n^2)$,每次$O(1)$查询。

## 代码实现

```c++
//
// Created by vv123 on 2022/5/9.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, w, a[N], b[N], f[N], t[N];
void upd(int i, int x) {
    for (; i <= n; i += i & -i)
        t[i] = max(t[i], x);
}
int ask(int i) {
    int res = 0;
    for(; i; i -= i & -i)
        res = max(res, t[i]);
    return res;
}
int val[N];
void LSH() {
    for (int i = 1; i <= n; i++)
        val[i] = b[i];
    sort(val + 1, val + 1 + n);
    int m = unique(val + 1, val + 1 + n) - 1 - val;
    for (int i = 1; i <= n; i++)
        b[i] = lower_bound(val + 1, val + 1 + m, b[i]) - val;
}
int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - i;
    }
    LSH();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = ask(b[i]) + 1;
        upd(b[i], f[i]);
        ans = max(ans, f[i]);
    }
    cout << (long long)w * (n - ans) << endl;
    return 0;
}
```

# L-强迫症患者 解题报告



## 题目大意

一个长度为n的序列，修改一个数花费w元，问把序列变成严格单增的最小花费。

$n\le 1\times 10^5$。



## 解题思路

我们要求出最小的修改数，可以转化为求最大的“未修改数”。

考察在最终序列中未经过修改的部分，它们一定是一个**上升子序列**，而且满足相邻两个数的**大小之大于等于它们的下标之差**（否则满足不了严格单增）。

设$f_j$为以位置$j$结尾的满足上述要求的子序列最长长度，那么

$f_j=\max\limits_{i<j,a_j-a_i\ge j-i}\left \{  f_i\right \}+1$

为了方便优化，我们可以将条件$a_j-a_i\ge j - i$移项，得到$a_j-j>a_i-i$。

我们构造一个新数组$b_i = a_i - i$,则问题转化为熟悉的LIS问题：

$f_j=\max\limits_{i<j,b_i\le b_j}\left \{  f_i\right \}+1$

这个式子可以使用树状数组优化：当我们得到以$b_i$为结尾的答案$f_i$,就把树状数组的$b_i$位置用$f_i$更新最大值。维护一下前缀最大值，则对每个$j$可以$O(\log n)$得到答案，总的时间复杂度为$O(n\log n)$

## 代码实现

```c++
//
// Created by vv123 on 2022/5/9.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, w, a[N], b[N], f[N], t[N];
void upd(int i, int x) {
    for (; i <= n; i += i & -i)
        t[i] = max(t[i], x);
}
int ask(int i) {
    int res = 0;
    for(; i; i -= i & -i)
        res = max(res, t[i]);
    return res;
}
int val[N];
void LSH() {
    for (int i = 1; i <= n; i++)
        val[i] = b[i];
    sort(val + 1, val + 1 + n);
    int m = unique(val + 1, val + 1 + n) - 1 - val;
    for (int i = 1; i <= n; i++)
        b[i] = lower_bound(val + 1, val + 1 + m, b[i]) - val;
}
int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - i;
    }
    LSH();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = ask(b[i]) + 1;
        upd(b[i], f[i]);
        ans = max(ans, f[i]);
    }
    cout << (long long)w * (n - ans) << endl;
    return 0;
}
```

# M-啥b二次元3 解题报告



## 题目大意

求满足“每个数相邻的数要么都比它大，要么都比他小”的1~n的排列个数。

$n \le  4500， 2 \le m \le 10^9$



## 解题思路

显然满足条件的排列可以分为M型和W型两种(由**前两个数的大小关系**决定）。

设$1,2,\dots ,i$的、开头数字为$j$的M型排列数为$M[i][j]$,W型排列数为$W[i][j]$

初始化$M[1][1]=W[1][1]=1$

显然有如下转移：

$W[i][j] = \sum_{1 \le k<j}M[i-1][k]$

为什么是正确的？因为我们可以将$M[i-1][k]$对应的每个排列里，**所有大于等于$j$的数字加$1$**，它们的数量和性质均不变，把它们拼在$j$的后面就构成了所有的$W[i][j]$

> 例如：
>
> n=2的M排列仅有$1,2$一种，即仅有$M[2][1]=1>0$
>
> 则$W[3][3]=M[2][1]$，对应$3,1,2$
>
> $W[3][2]=M[2][1]$，对应$2,1,3$。这里将$1,2$中的$2$改成了$3$。
>
> 所以n=3的W排列有2种。

容易知道，$[1,n]$的M排列数量与W排列数量一定相等，因为每一个"M"都可以由"W"**上下翻转**得到。其中第一个数$j$被翻转成了$i - j + 1$。故求出$W[i][j]$后可以根据$M[i][j] = W[i][i-j+1]$求出所有$M[i][j]$

答案为$\sum_{1\le j \le n}W[n][j] + M[n][j]$

时间复杂度为$O(n^3)$

显然可以用一个数组记录$M[i-1]$的前缀和,转移方程简化为$W[i][j] = sum[j-1]$.

这样就优化到了$O(n^2)$

## 代码实现

```cpp
//
// Created by vv123 on 2022/5/19.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int M[N][N], W[N][N], sum[N], n, mod;
void solve() {
    M[1][1] = W[1][1] = 1; sum[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            W[i][j] = sum[j - 1];
        }
        for (int j = 1; j <= i; j++) {
            M[i][j] = W[i][i - j + 1];
        }
        for (int j = 1; j <= i; j++) {
            sum[j] = (sum[j - 1] + M[i][j]) % mod;
        }
    }
    long long ans = 0;
    for (int j = 1; j <= n; j++)
        ans = (ans + W[n][j] + M[n][j]) % mod;
    cout << ans << endl;
}

int main() {
    cin >> n >> mod;
    solve();
    return 0;
}

```

# O-宝可梦 解题报告



## 题目大意

有n个物品，每个物品重要度为c价格为v数量为m，求一个重要度之和不超过W、总价格尽可能大的子集。

$n\le 100,\sum m_i \le 1 \times 10^5 ,W \le 4 \times 10^4$。



## 解题思路

首先有一种朴素的解法：将每个物品拆成m个物品，转化为01背包。但这样物品总数过大，尝试优化。

引理：任意数n都可以由{1，2，4,  8....}中的一些数拼出来。

显然，选出n的二进制中的1即可

我们发现，表示[1,m]中所有的数不需要m个数，只需要O(log m)个数即可。

我们要怎么选这些数，使得它们的表示范围**恰好为[1,m]**?

我们假设已经选了${1,2,4,...,2^{k-1}}$，则根据等比数列求和，它们所能表示的最大数为$2^k-1$

考察$m - (2^k-1)$，

如果为0可以直接停止选择，

如果大于等于$2^k$可以选$2^k$并进入下一步选择，

如果$m - (2^k-1) \in[1,2^k-1]$,则最后一个数就选$m - (2^k-1)$,然后退出选择。

这样，我们选择的数可以恰好表示$[1,m]$中的任意数。

时间复杂度为$O(W\sum_{i=1}^{n}\log m_i)$

## 代码实现

```cpp
//
// Created by vv123 on 2022/5/9.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, w, v[N], c[N], m[N];//价格、重要度、数量
int _v[N], _c[N], cnt, f[N];

void init(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; ; j <<= 1) {
            if (!m[i]) break;
            else if (m[i] >= j) {
                m[i] -= j;
                cnt++;
                _v[cnt] = v[i] * j;
                _c[cnt] = c[i] * j;
            } else {
                cnt++;
                _v[cnt] = v[i] * m[i];
                _c[cnt] = c[i] * m[i];
                break;
            }
        }
    }
}

int main() {
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> c[i] >> m[i];
    init();
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
        for (int j = w; j >= _c[i]; j--)
            f[j] = max(f[j], f[j - _c[i]] + _v[i]), ans = max(ans, f[j]);
    cout << ans << endl;
    return 0;
}
```

# V-痛，太痛了 解题报告



## 题目大意

有n-1种车票，第r种价格为Pi、最多可以连着坐r站，每个站花费1时间。

只能选择一种票，可以使用任意次。

一开始在1号站，在第i站下车需要等待Di时间才能上车。(2<=i<=n)

问最少花费多少钱，可以在T时间内到达第n站。

$n\le 5\times 10^4$。



## 解题思路

显然，对第i张票，如果存在j>i且Pj<=Pi，则这张票是没用的。

我们从后往前遍历所有票，记录当前的最小值，如果遍历到了一个价格大于等于最小值的票则忽略它。最后把数组翻转一下。

这样，得到了一系列价格和站数都单调递增的票。

显然下标越大越容易满足”T时间内到达第n站“，因此可以二分下标，判定对应票的范围是否满足要求。求出第一个满足要求的下标，输出对应的价格。



现在的问题是，有n个车站，一开始在1号车站，坐一站需要消耗1时间，最多连着坐r站。在第i站下车需要等待Di时间才能再上车。问到达n站的最短时间（是否不超过T)。

我们设f[i]为**在第i站下车且休整完毕**的最短时间

根据限制条件，f[i]只能由前r个站转移而来，容易得到

$f[i] = \min\limits_{i-r \le j \le i - 1}\left \{ f[j] +(i - j) + D_i  \right \}$

也就是

$f[i] = \min \limits_{i-r \le j \le i - 1} \left \{ f[j]  - j  \right \} + D_i + i$

前一部分是个长度为$r$的滑动窗口，因此可以$O(n)$求出$f[n]$，判断$f[n]$是否不超过T即可。



综上，可以用二分+单调队列$O(n\log n)$通过此题。

## 代码实现

```c++
//
// Created by vv123 on 2022/5/20.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, T, tp[N], p[N], range[N], d[N], f[N];
int q[N];
bool check(int r) {
    //printf("r=%d\n", r);
    /*
    memset(f, 0x3f, sizeof f);
    f[1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = max(1, i - r); j <= i - 1; j++)
            f[i] = min(f[i], f[j] + (i - j) + d[i]);//, cout << j << endl;
        //printf("f[%d]=%d\n", i, f[i]);
    }
    return f[n] <= T;
     */
    memset(q, 0, sizeof q);
    int h = 1, t = 0;
    for (int i = 1; i <= n; i++) {
        if (i > 1) f[i] = f[q[h]] - q[h] + i + d[i];
        while (h <= t && i - q[h] + 1 > r) h++;
        while (h <= t && f[q[t]] - q[t] > f[i] - i) t--;
        q[++t] = i;
        //printf("f[%d]=(%d-%d)+%d+%d=%d\n",i,f[q[h]],q[h],i,d[i],f[i]);
    }
    return f[n] <= T;
}

int main() {
    cin >> n >> T;
    for (int i = 1; i <= n - 1; i++)
        cin >> tp[i];
    for (int i = 2; i <= n - 1; i++)
        cin >> d[i];
    int cnt = 0, minp = inf;
    for (int i = n - 1; i >= 1; i--) {
        if (tp[i] < minp) {
            minp = tp[i];
            p[++cnt] = tp[i];
            range[cnt] = i;
        }
    }
    reverse(p + 1, p + 1 + cnt);
    reverse(range + 1, range + 1 + cnt);
    //for (int i = 1; i <= cnt; i++) cout << p[i] << " ";cout << endl;
    int l = 1, r = cnt;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(range[mid])) r = mid;
        else l = mid + 1;
    }
    cout << p[l] << endl;
    return 0;
}

```

# X-惊魂工创1 解题报告



## 题目大意

给定一个有边权的树，每次操作可以让某个边权+1，求最少经过几次操作，能使根节点到所有叶节点的路径权值和相同。

$n \le  5 \times 10^5$



## 解题思路

~~对刚刚结课的工创1真是又爱又恨啊~~

边权只能增加，所以求出操作前的最大权值和M，将其他叶节点的路径权值和修改为M即可。

显然，我们要优先修改靠近根节点的边，因为这样一次操作能覆盖更多叶节点，使修改次数最小,这个操作可以通过广度优先遍历来实现。枚举到的每一条边修改量为**M-“目前包含这条边的最长路径长度”**，因为再大就有叶节点就超过M了。



首先DFS一遍，预处理每个节点**到最远叶节点的距离**f1[u],顺便求出M。

设u的儿子为v，则$$f1[u] = \max(f1[v] + w(u, v))$$



然后BFS一遍，按层尝试修改边权。

设f2[u]为u**到根节点的距离**，如果$$f1[u]+f2[u]$$小于$M$,则$(fa(u),u)$这条边的权值要增加$M-f1[u]-f2[u]$,只需将修改量统计到答案，并将$f2[u]$更新为$M-f1[u]$。

然后枚举子节点v，用$f2[u] + w(u,v)$更新$f2[v]$，将v扔进队列BFS即可。

时间复杂度为$O(n)$

## 代码实现

```cpp
//
// Created by vv123 on 2022/5/17.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const int inf = 1e18;

int n, s, f1[N], f2[N], f[N], M, ans;
struct Edge { int v, w; };
vector<Edge> g[N];

void dfs(int u, int fa) {
    for (auto e : g[u]) {
        int v = e.v, w = e.w;
        if (v == fa) continue;
        dfs(v, u);
        f1[u] = max(f1[u], f1[v] + w);
        M = max(M, f1[u]);
    }
}
bool vis[N];
inline void bfs() {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = 1;
        if (u != s) {//printf("%d %d %d\n", u, f1[u], f2[u]);
            ans += M - f1[u] - f2[u];
            f2[u] = M - f1[u];
        }
        for (auto e : g[u]) {
            int v = e.v, w = e.w;
            if (vis[v]) continue;
            f2[v] = f2[u] + w;
            q.push(v);
        }
    }
}

signed main() {
    cin >> n >> s;
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(s, 0);//for (int i = 1; i <= n; i++) cout << f1[i] << " ";cout << M << endl;
    bfs();//for (int i = 1; i <= n; i++) cout << f2[i] << " ";
    cout << ans << endl;
    return 0;
}
```

# Z-砍编剧 解题报告



## 题目大意

有n个物品，重量为wi价值为ci，背包的承重为m，求背包能装下的最大价值。

$n\le 500,m \le  50000$。



## 解题思路

设$f[i][j]$表示考虑前i个物品，总重量为j的最大价值，显然有

$f[i][j]=\max(f[i-1][j], f[i-1][j-w_i]+c_i)$

时间复杂度为$O(n^2)$，空间复杂度为$O(n^2)$



注意到$i$总是由$i-1$ 转移而来，可以省掉第一维状态，则有

$f[j]=\max(f[j], f[j - w_i]+c_i)$

为了确保第二个式子和第一个式子的转移等价，需要注意到，对第$i$轮更新的每一个$j$，$f[j-w_i]$都来自第$i-1$轮，而不能在第$i$轮被更新过。因此，要将$j$从$m$开始降序枚举，这样每个状态的都是从第$i$轮未访问的状态更新过来的。

时间复杂度为$O(n^2)$，空间复杂度为$O(n)$

## 代码实现

```cpp
//
// Created by vv123 on 2022/5/7.
//
#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 50010;
int n, m, f[M], w[N], a[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> w[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j--) {
            f[j] = max(f[j], f[j - w[i]] + a[i]);
            ans = max(ans, f[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
```
