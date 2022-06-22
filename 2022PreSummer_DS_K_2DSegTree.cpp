//
// Created by vv123 on 2022/5/5.
//
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 510;
const int INF = 0x3f3f3f3f;
int n, m, op;
//----------------2D_Segment_Tree------------------
#define mid (l + r >> 1)
#define ls u << 1, l, mid
#define rs u << 1 | 1, mid + 1, r
int xrt, xisleaf, mx[N << 2][N << 2], mn[N << 2][N << 2];
int x1, y1, x2, y2;
int resmx, resmn;
void AskInY(int u, int l, int r) {
    if (y1 <= l && y2 >= r) {
        resmx = max(resmx, mx[xrt][u]);
        resmn = min(resmn, mn[xrt][u]);
        return;
    }
    if (y1 <= mid) AskInY(ls);
    if (y2 >= mid + 1) AskInY(rs);
}
void AskInX(int u, int l, int r) {
    if (x1 <= l && x2 >= r) {
        xrt = u;
        AskInY(1, 1, n);
        return;
    }
    if (x1 <= mid) AskInX(ls);
    if (x2 >= mid + 1) AskInX(rs);
}
int x, y, k;
void PushUpY(int u) {
    mx[xrt][u] = max(mx[xrt][u << 1], mx[xrt][u << 1 | 1]);
    mn[xrt][u] = min(mn[xrt][u << 1], mn[xrt][u << 1 | 1]);
}
void PushUpX(int u) {
    mx[xrt][u] = max(mx[xrt << 1][u], mx[xrt << 1 | 1][u]);
    mn[xrt][u] = min(mn[xrt << 1][u], mn[xrt << 1 | 1][u]);
}
void UpdInY(int u, int l, int r) {
    if (l == r) {
        if (xisleaf) {//如果要更新的xrt是叶子，需单点修改xrt的y树
            mx[xrt][u] = mn[xrt][u] = k;
            return;
        }
        PushUpX(u);//如果要更新的xrt不是叶子，需合并xrt子树的答案
        return;
    }
    if (y <= mid) UpdInY(ls);
    else UpdInY(rs);
    PushUpY(u);
}
void UpdInX(int u, int l, int r) {
    if (l == r) {   //如果要更新的xrt是叶子，直接单点修改xrt的y树
        xrt = u; xisleaf = 1; UpdInY(1, 1, n);
        return;
    }
    if (x <= mid) UpdInX(ls);
    else UpdInX(rs);
    xrt = u; xisleaf = 0; UpdInY(1, 1, n);  //如果要更新的xrt不是叶子，就递归左右子树，合并子树答案
}
//-------------------------------------------------
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            x = i, y = j, cin >> k, UpdInX(1, 1, n);
    cin >> m;
    while (m--) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            UpdInX(1, 1, n);
        } else {
            resmx = -INF; resmn = INF;
            cin >> x1 >> y1 >> x2 >> y2;
            AskInX(1, 1, n);
            cout << resmx << " " << resmn << "\n";
        }
    }
    return 0;
}


