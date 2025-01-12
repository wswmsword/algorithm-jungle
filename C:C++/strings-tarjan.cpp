#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
#define maxn 1000000
vector<int >mp[maxn];
int ans[maxn];
int vis[maxn];
int dfn[maxn];
int low[maxn];
int n,m,tt,cnt,sig;
void init()
{
    memset(low,0,sizeof(low));
    memset(dfn,0,sizeof(dfn));
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)mp[i].clear();
}
void Tarjan(int u)
{
    vis[u]=1;
    low[u]=dfn[u]=cnt++;
    for(int i=0;i<mp[u].size();i++)
    {
        int v=mp[u][i];
      //   printf("%d..",v);
        if(vis[v]==0)Tarjan(v);
        if(vis[v]==1)low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u])
    {
        sig++;
    }
}
void Slove()
{
    tt=-1;cnt=1;sig=0;
    for(int i=1;i<=n;i++)
        if(vis[i]==0)
            Tarjan(i);
    printf("%d\n",sig);
}
int main()
{
    while(~scanf("%d",&n))
    {
        if(n==0)break;
        scanf("%d",&m);
        init();
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x].push_back(y);
        }
        Slove();
    }
}
/*
7 9
1 2
2 3
3 1
2 4
4 7
7 4
4 5
5 6
6 4
8 10
1 2
2 3
3 1
2 4
4 7
7 4
4 5
5 6
6 4
7 8
*/