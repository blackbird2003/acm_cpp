//
// Created by vv123 on 2022/3/2.
//
#include <iostream>
#include <stack>
using namespace std;
const int N = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int a[N], st[N], r[N], n, top, ans;
void solve()
{
    stack<pair<int, int> > st;
    st.push(make_pair(1, a[1]));
    for (int i = 2; i <= n; i++)
    {
        while (!st.empty() && st.top().first <= a[i])
        {
            r[st.top().second] = i;
            st.pop();
        }
        st.push(make_pair(i, a[i]));