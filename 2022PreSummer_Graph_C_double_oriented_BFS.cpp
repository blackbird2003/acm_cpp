//
// Created by vv123 on 2022/4/10.
//
#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 510;
const int INF = 0x3f3f3f3f;
int n, m;
int G[N][N];
pair<int, int> d[2] = {{1, 1}, {-1, -1}};
inline const pair<int, int> operator+(const pair<int, int>& p1, const pair<int, int>& p2)
{
    pair<int, int> res;
    res.first = p1.first + p2.first;
    res.second = p1.second + p2.second;
    return res;
}

int vis[N][N];
vector<pair<int, int> >  BFS(pair<int, int> s) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int> > q;
    vector<pair<int, int> > res;
    q.push(s);
    vis[s.x][s.y] = 1;
    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        //printf("->(%d,%d)\n", u.x, u.y);
        res.push_back(u);
        vis[u.x][u.y] = 1;
        pair<int, int> v = u + d[G[u.x][u.y]];
        if (!vis[v.x][v.y] && v.x <= n && v.y <= m) q.push(v);
    }
    return res;
}
int main() {
    scanf("%d%d", &n, &m);
    char str[N];
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++)
            G[i][j] = str[j] == '\\' ? 0 : 1;
    }
    vector<pair<int, int>> s = BFS({1, 1}), t = BFS({n, m});
    int ans = INF;
    //cout << s.size() << " " << t.size() << endl;
    for (int i = s.size() - 1; i >= max(0, (int)s.size() - 1000); i--) {
        for (int j = t.size() - 1; j >= max(0, (int)t.size() - 1000); j--) {
            //printf("%d:(%d,%d)->%d:(%d,%d)\n", i, s[i].x, s[i].y, j, t[j].x, t[j].y);
            int t1 = abs(s[i].x - t[i].x) / 2, t2 = abs(s[i].y - t[i].y) / 2;
            if (t1 * t2 == 0 && t1 + t2 <= 1) continue;
            ans = min(ans, max(t1, t2));
        }
    }
    if (ans != INF) printf("%d\n", ans);
    else puts("NO SOLUTION");
    return 0;
}


