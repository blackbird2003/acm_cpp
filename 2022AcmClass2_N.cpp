//
// Created by vv123 on 2022/3/6.
//
/*打表大法好
#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int a[10][10];
bool check() {
    for (int i = 1; i <= n; i++) {
        int sum = 1;
        for (int j = 1; j <= m; j++)
            sum *= a[i][j];
        if (sum != k) return false;
    }
    for (int j = 1; j <= m; j++) {
        int sum = 1;
        for (int i = 1; i <= n; i++)
            sum *= a[i][j];
        if (sum != k) return false;
    }
    return true;
}
void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%d ", a[i][j]);
        puts("");
    }
    puts("");
}

int q[210];
void dfs(int x, int t) {
    q[x] = t;
    //for (int i = 1; i <= n * m; i++) printf("%d ", q[i]);
    //puts("");
    if (x == n * m) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                a[i][j] = q[(i - 1) * m + j];
        //print();
        if (check()) ans++;
        return;
    }
    dfs(x + 1, 1);
    dfs(x + 1, -1);
}
int main() {
    k = 1;
    for (n = 1; n <= 5; n++) {
        for (m = 1; m <= 5; m++) {
            ans = 0;
            dfs(1, 1);
            dfs(1, -1);
            printf("%7d", ans);
        }
        puts("");
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    if (n % 2 != m % 2 && k == -1) cout << 0 << endl;
    else cout << (long long)pow(1 << m - 1, n - 1) << endl;
    return 0;
}