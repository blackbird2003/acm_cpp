<<<<<<< HEAD
//
// Created by vv123 on 2022/2/23.
//
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};
point p[10];
void solve() {
    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + 3, [](const point &a,const point &b) {
        return a.y > b.y;
    });
    if (p[0].y == p[1].y) printf("%d\n", abs(p[0].x - p[1].x));
    else puts("0");
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
=======
//
// Created by vv123 on 2022/2/23.
//
#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};
point p[10];
void solve() {
    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p, p + 3, [](const point &a,const point &b) {
        return a.y > b.y;
    });
    if (p[0].y == p[1].y) printf("%d\n", abs(p[0].x - p[1].x));
    else puts("0");
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
>>>>>>> eb78ae3d1fc2d4b02f3e542cfe861cef6d785780
