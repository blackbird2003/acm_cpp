#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef unsigned long long ULL;

const int N = 1010, M = 1010;

int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int dcc_cnt;
vector<int> dcc[N];
bool cut[N];
int root;

void add(int a,int b)
{
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

void tarjan(int u)
{
    low[u] = dfn[u] = ++timestamp;
    stk[++top] = u;
    // 1 u是孤立点-自称一个dcc
    if(u==root && h[u]==-1)//u是根节点且没有邻边
    {
        puts("into 1");
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }
    // 2 u不孤立
    int cnt = 0;
    for(int i = h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u],low[j]);
            // 看j是不是能连到比u还高的地方
            if(dfn[u]<=low[j])//j最高比u高度低 说明j是u一个新的分支(如果把u删掉 多一个j连通块)
            {
                printf("%d->%d\n", u, j);
                cnt++;
                // 判断u是否割点 如果不是根节点-只要有一个分支他就是割点 || 如果是根节点 需要有两个分支才是割点
                //    root            /
                //    / \          非root(自带上面一个边,所以只要一个下分支)
                //                   /
                if(u!=root||cnt>1)cut[u] = true;
                ++dcc_cnt;
                int y;
                do{
                    y = stk[top--];
                    dcc[dcc_cnt].push_back(y);
                }while(y!=j);//注意弹出栈不是弹到u为止 而是弹到j为止(u仍保留在stk中)
                // 🔺 开新分支 == u一定和新分支j组成一个dcc 也和旧连通块组成dcc
                // 那么当前最高点u还要被用在更高的包含u的旧连通块
                // 所以如果这个时候出栈了 回溯到比u高的点的时候 u就加不进旧连通块里
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u] = min(low[u],dfn[j]);
    }
}

int main()
{
    int T = 1;
    while(cin >> m,m)
    {
        for(int i=1;i<=dcc_cnt;i++)dcc[i].clear();
        idx = n = timestamp = top = dcc_cnt = 0;
        memset(h,-1,sizeof h);
        memset(dfn,0,sizeof dfn);
        memset(cut,0,sizeof cut);
        while(m--)
        {
            int a,b;
            cin >> a >> b;
            n = max(n,b),n = max(n,a);//第二个n=漏了
            add(a,b),add(b,a);
        }

        for (root = 1; root <= n; root ++ )
            if (!dfn[root])
                tarjan(root);

        int res = 0;
        ULL num = 1;
        cout << dcc_cnt << endl;
        for(int i = 1;i<=dcc_cnt;i++)
        {
            int cnt = 0;
            for(int j= 0;j<dcc[i].size();j++)//j< 写成了i<
            {
                cout << dcc[i][j] << " ";
                if(cut[dcc[i][j]])
                    cnt++;
            }
            cout << endl;
            // 无割点
            if(cnt == 0)//cnt写成了cut
            {
                if(dcc[i].size()>1)res+=2,num*=dcc[i].size()*(dcc[i].size()-1)/2;
                else res++;
            }
            else if(cnt==1)res++,num*=dcc[i].size()-1;
        }
        printf("Case %d: %d %llu\n", T ++, res, num);
    }
    return 0;
}