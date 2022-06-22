//
// Created by vv123 on 2022/3/26.
//
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], b[N], c[N], d[N], n, m;
vector<pair<int, int> > obj, box;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> c[i];
    for (int i = 1; i <= m; i++) cin >> d[i];
    for (int i = 1; i <= n; i++) obj.push_back({a[i], b[i]});
    for (int i = 1; i <= m; i++) box.push_back({c[i], d[i]});
    sort(obj.begin(), obj.end());
    sort(box.begin(), box.end());
    int p = 0;
    for (int i = 0; i < n; i++) {
        while(p < m && (box[p].first < obj[i].first || box[p].second < obj[i].second))
            p++;
        //printf("%d %d\n", i, p);
        if (p >= m) {
            puts("No");
            return 0;
        }
        else p++;
        //printf("%d{%d,%d} settled\n", p-1, box[p-1].first, box[p-1].second);
    }
    puts("Yes");
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    vector<pair<int, int> > obj(n), box(m);
    for (int i = 0; i < n; i++) cin >> obj[i].first;
    for (int i = 0; i < n; i++) cin >> obj[i].second;
    for (int i = 0; i < m; i++) cin >> box[i].first;
    for (int i = 0; i < m; i++) cin >> box[i].second;
    sort(obj.rbegin(), obj.rend());
    sort(box.rbegin(), box.rend());
    int p = 0;
    for (int i = 0; i < n; i++) {
        auto[w, h] = obj[i];
        while(p < m && box[p].first >= w)
            s.insert(box[p++].second);
        auto it = s.lower_bound(h);
        if (it == s.end()) {
            puts("No");
            return 0;
        }
        s.erase(it);
    }
    puts("Yes");
    return 0;
}








