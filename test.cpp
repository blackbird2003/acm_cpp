#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;

struct PAM{
    int next[N][26];
    int fail[N];
    int cnt[N];
    int num[N];
    int len[N];
    int S[N];
    int last;
    int n;
    int p;

    int newnode(int l)
    {
        for(int i=0;i<26;++i) next[p][i]=0;
        cnt[p]=0;
        num[p]=0;
        len[p]=l;
        return p++;
    }

    void Init()
    {
        p=0;
        newnode(0);
        newnode(-1);
        last=0;
        n=0;
        S[n]=-1;
        fail[0]=1;
    }

    int get_fail(int x)
    {
        while(S[n-len[x]-1]!=S[n]) x=fail[x] ;
        return x ;
    }

    void add(int c)
    {
        S[++n]=c;
        int cur=get_fail(last) ;
        if(!next[cur][c])
        {
            int now=newnode(len[cur]+2) ;
            fail[now]=next[get_fail(fail[cur])][c] ;
            next[cur][c]=now ;
            num[now]=num[fail[now]]+1;
        }
        last=next[cur][c];
        cnt[last]++;
    }

    int count() {
        int res=p*1ll;
        for(int i=p-1;i>=0;--i) cnt[fail[i]]+=cnt[i];
        return (res-2);//本质不同的回文串数量
    }
} pam;
char str[N];
signed main() {
    freopen("data.txt", "r", stdin);
    for (int i =1 ; i <= 10; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
    }

}