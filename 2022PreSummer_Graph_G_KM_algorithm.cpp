//
// Created by vv123 on 2022/4/22.
//
#include <bits/stdc++.h>
#define clr(arr) memset(arr,0,sizeof arr)
#define inf(arr) memset(arr, 0x3f, sizeof arr)
#define int long long
using namespace std;

const int N = 410;
const int INF = 2e18 + 10;
int n, m, a[N], b[N], d[N], ans, sum[N], val[N];
int lx[N], ly[N], vis[N], slack[N], match[N], pre[N];

struct node {
    int c, w;
    bool operator < (const node& x) const {
        return c < x.c;
    }
    bool operator < (const int x) const {
        return c < x;
    }
} e[N];

int w(int x, int y) {
    int pos = lower_bound(e + 1, e + 1 + n, a[x] + b[y]) - e - 1;//printf("%d<->%d: %d\n", x, y, sum[pos]);
    return sum[pos];
}

void find(int s) {
    //可行顶标:l,s.t.对任意弧(x,y)都有l(x)+l(y)>=w(x,y)
    //相等子图:只保留满足l(x)+l(y)=w(x,y)的边的子图
    //定理:如果相等子图有完美匹配,则该匹配是原图的最大权匹配
    //证明:假设我们找到了相等子图的一个完美匹配，此时的可行顶标为l
    //任取原图的一个最大权匹配，一定有有边权和<=顶标和
    //而这个相等子图的完美匹配，满足边权和==顶标和>=最大权匹配的边权和
    //因而它只能是最大权匹配
    //问题的关键在于找到合适的l。
    //设S，T表示左/右在交错树中的点，各自补集为S',T'
    //考虑每次对S和T的lx -= k, ly += k,则S-T'间的l(x)+l(y)减小k，可能加入相等子图。
    //显然，选k=min(lx+ly-w)。我们可以对T中的点维护slack(v)=min(lx+ly-w, u in S),并取最小的slack(v)为k
    clr(vis), clr(pre), inf(slack);
    int y = 0, miny = 0, k;
    match[y] = s;
    for (;;) {
        k = INF; vis[y] = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                if (slack[i] > lx[match[y]] + ly[i] - w(match[y], i))
                    slack[i] = lx[match[y]] + ly[i] - w(match[y], i), pre[i] = y;
                if (slack[i] < k)
                    k = slack[i], miny = i;
            }
        }
        for (int i = 0; i <= n; i++) {
            if (vis[i]) lx[match[i]] -= k, ly[i] += k;
            else slack[i] -= k;
        }
        y = miny;
        if (!match[y]) break;
    }
    while(y) { match[y] = match[pre[y]]; y = pre[y]; }
}

void KM() {
    clr(match); clr(lx); clr(ly);
    for (int i = 1; i <= n; i++)
        find(i);
}


signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> e[i].c;
    for (int i = 1; i <= n; i++) cin >> e[i].w;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    sort(e + 1, e + 1 + n);
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + e[i].w;//printf("sum%d=%d\n", i, sum[i]);

    KM();

    for (int i = 1; i <= n; i++)
        ans += w(match[i], i);
    cout << ans << endl;
    return 0;
}


