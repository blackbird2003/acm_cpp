//
// Created by vv123 on 2022/4/16.
//
//邻接矩阵实现的朱刘算法
//实现参考：《算法竞赛入门经典——训练指南》
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
const int INF = 0x3f3f3f3f;

struct MinimumDirectedSpanningTree {
    int n, m, s, ans, w[N][N], vis[N], del[N], pre[N], miw[N], cid[N], cycle_cnt;
    MinimumDirectedSpanningTree() {
        memset(w, 0x3f, sizeof w);
        for (int i = 1; i <= n; i++) w[i][i] = 0;
        memset(vis, 0, sizeof vis);
        memset(del, 0, sizeof del);
        memset(pre, 0, sizeof pre);
        memset(miw, 0, sizeof miw);
        memset(cid, 0, sizeof cid);
        ans = 0;
        cycle_cnt = 0;
    }

    int check_vis(int s) {  //检查s能否到达所有结点
        vis[s] = 1;
        int res = 1;
        for (int i = 1; i <= n; i++)
            if(!vis[i] && w[s][i] < INF) res += check_vis(i);
        return res;
    }

    void upd(int u) {   //更新最短入弧miw
        miw[u] = INF;
        for (int i = 1; i <= n; i++)
            if (!del[i] && w[i][u] < miw[u])
                miw[u] = w[i][u], pre[u] = i;   //ans = sum of all miw[x]
    }

    bool find_cycle(int u) {   //判环
        cycle_cnt++;
        int v = u;
        while (cid[v] != cycle_cnt)
            cid[v] = cycle_cnt, v = pre[v]; //沿着pre走一圈
        return v == u;
    }

    void shrink(int u) {    //缩环——我们要删掉环中u以外的所有点v，并用w[i][v]更新w[i][u],用w[v][i]更新w[u][i]
        int v = u;
        do {
            if (v != u) del[v] = 1;
            ans += miw[v];
            for (int i = 1; i <= n; i++) {  //处理环外的点i
                if (cid[i] != cid[u] && !del[i]) {
                    if (w[i][v] < INF) w[i][u] = min(w[i][u], w[i][v] - miw[v]);//v的入边-=miw[v],相当于从环中删掉了这条边
                    if (pre[i] == v) pre[i] = u;
                    w[u][i] = min(w[u][i], w[v][i]);//v的出边直接相连，因为这样并不会改变被计算的边权
                }
            }
            v = pre[v]; //沿着pre走一圈
        } while(v != u);
        upd(u);
    }

    void solve() {
        memset(vis, 0, sizeof vis);
        if (check_vis(s) != n) {
            puts("-1");
            return;
        }

        for (int i = 1; i <= n; i++) upd(i);    //求最短弧集
        pre[s] = s; miw[s] = 0; //注意处理s
        while (1) {
            bool flag = false;  //判断最短弧集中是否存在环
            for (int i = 1; i <= n; i++) {
                if (i != s && !del[i] && find_cycle(i)) {
                    flag = true;
                    shrink(i);  //有环就缩环，更新最短弧集
                    break;
                }
            }
            if (!flag) break;    //当前最短弧集已构成生成树
        }
        for(int i = 1; i <= n; i++)
            if(!del[i]) ans += miw[i];  //ans = sum of all miw[x]
        cout << ans << endl;
    }
};





int main() {
    MinimumDirectedSpanningTree T;
    cin >> T.n >> T.m >> T.s;
    for (int i = 1; i <= T.m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        T.w[u][v] = min(T.w[u][v], w);
    }
    T.solve();
    return 0;
}


