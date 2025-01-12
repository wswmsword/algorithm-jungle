#include<stdio.h>
int book[57];
int z[57][57];
int main()
{
   int n,m;
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
         if(i!=j)
            z[i][j]=99999999;
   int r,t,y;
   for(int i=1;i<=m;i++)
      scanf("%d %d %d",&r,&t,&y),z[r][t]=y;
   int Sz[57];
   for(int i=1;i<=n;i++)
      Sz[i]=z[1][i];
   book[1]=1;
   int f[57];
   for(int i=0;i<57;i++)
      f[i]=0;
   for(int i=1;i<n;i++)
   {
      int min=99999999;
      int u;
      for(int j=1;j<=n;j++)
         if(!book[j]&&Sz[j]<min)
            min=Sz[u=j];
      book[u]=1;
      for(int v=1;v<=n;v++)
         if(z[u][v]<99999999)
            if(Sz[v]>Sz[u]+z[u][v])
            {
               Sz[v]=Sz[u]+z[u][v];
               f[v]=u;
            }
   }
   for(int i=1;i<=n;i++)
   {
      printf(" %d\n",Sz[i]);
      int t=i;
      while(f[t]!=0)
      {
         printf(" %d ",f[t]);
         t=f[t];
      }
      printf("\n==\n");
   }
   return 0;
}/*
#include<stdio.h>
int book[57];
int main()
{
   int m,n;
   scanf("%d %d",&n,&m);
   int u[57],v[57],w[57];
   int first[57];
   int nExt[577];
   for(int i=1;i<=n;i++)
      first[i]=-1;
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %d",&u[i],&v[i],&w[i]);   //始点  末点  距离
      nExt[i]=first[u[i]];   //邻接表
      first[u[i]]=i;   //邻接表
   }
   int Sz[57];   //一到各点的最近距离
   for(int i=1;i<=n;i++)
      Sz[i]=99999999;
   Sz[1]=0;
   int t=first[1];
   while(t!=-1)   //初始化
   {
      Sz[v[t]]=w[t];
      t=nExt[t];
   }
   book[1]=0;   //从1出发
   for(int i=1;i<n;i++)   //从1到n找离1最近的一条路
   {
      int min=99999999;   //最小值
      int y;
      for(int j=1;j<=n;j++)
      {
         if(min>Sz[j]&&book[j]==0)
         {
            min=Sz[j];
            y=j;
         }
      }
      book[y]=1;
      int t=first[y];
      while(t!=-1)
      {
         if(Sz[v[t]]>Sz[u[t]]+w[t])
            Sz[v[t]]=Sz[u[t]]+w[t];
         t=nExt[t];
      }
   }
   for(int i=1;i<=n;i++)
      printf(" %d ",Sz[i]);
   return 0;
}*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 99999999
using namespace std;
const int MAXN=257;
int Sz[MAXN];
int u[MAXN],v[MAXN],w[MAXN];
int first[MAXN],nExt[MAXN];
int n,m;
int src;
typedef pair<int,int> Z;   //最短距离和编号
void init()
{
   scanf("%d %d",&n,&m);
   memset(first,-1,sizeof(first));
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %d",&u[i],&v[i],&w[i]);
      nExt[i]=first[u[i]];
      first[u[i]]=i;
      u[i+m]=v[i],v[i+m]=u[i],w[i+m]=w[i];   //无向边，因此加一条反向边
      nExt[i+m]=first[u[i+m]];
      first[u[i+m]]=i+m;
   }
   cin>>src;   //始点
   for(int i=1;i<=n;i++)
      Sz[i]=(i==src?0:inf);   //不要把Sz[i]初始化成始点到各点的直接距离，否则会有点没入队
}
void dijkstra()
{
   priority_queue<Z,vector<Z>,greater<Z> >que;   //声明一个小整数先出队的优先队列
   que.push(Z(0,src));   //始点推入队列
   while(!que.empty())
   {
      Z tmp=que.top();
      que.pop();
      int x=tmp.second;   //末点的编号
      if(tmp.first!=Sz[x]) 
         continue;   //避免重复，如果出队的这个元素，他带的Sz，和当前的Sz不相同，证明这个结点是被处理过的已确定了最短路
      for(int e=first[x];e!=-1;e=nExt[e])   //数组式邻接表的遍历
      {
         if(Sz[v[e]]>Sz[x]+w[e])
         {
            Sz[v[e]]=Sz[x]+w[e];
            que.push(Z(Sz[v[e]],v[e]));
         }
      }
   }
}
int main()
{
   init();
   dijkstra();
   for(int i=1;i<=n;i++)
      printf("%d ",Sz[i]);   //输出Sz数组各个值
   putchar('\n');
   return 0;
}

/*#include"cstdio"  
#include"queue"  
#include"algorithm"  
#define INF 1<<28  
#define MAX 300  
using namespace std;  
int v,e,s;  
int graph[MAX][MAX];//图的存储采用邻接矩阵  
int dist[MAX];//dist表示当前距源点最短距离，最终为最短距离  
bool visit[MAX];//标记为已找出最短路径的点  
typedef pair<int,int> P;//用于优先队列中距离与顶点的对应，其中first为距离  
void init()//初始化  
{  
    fill(graph[0],graph[0]+MAX*MAX,INF);  
    fill(dist,dist+MAX,INF);  
    fill(visit,visit+MAX,false);  
}  
void Dijkstra(int s)  
{  
    dist[s]=0;
    //优先队列  
    priority_queue <P,vector<P>,greater<P> >que;//最后这两个>中间最好加上空格，防止一些编译器识别错误  
    que.push(P(0,s));  
    while(!que.empty())  
    {  
        P p=que.top();
        que.pop();
        int vi=p.second;//vi为当前源点编号
        if(visit[vi])
            continue;
        visit[vi]=true;
        for(int i=0;i<v;i++)
        {
            if(!visit[i]&&dist[i]>dist[vi]+graph[i][vi])//查找vi的相邻顶点
            {
                dist[i]=dist[vi]+graph[i][vi];
                que.push(P(dist[i],i));
            }  
        }  
   }
}
int main()  
{  
    scanf("%d%d%d",&v,&e,&s);  
    init();  
    for(int i=0;i<e;i++)  
    {  
        int from,to,cost;  
        scanf("%d%d%d",&from,&to,&cost);  
        graph[from][to]=graph[to][from]=cost;  
    }  
    Dijkstra(s);  
    for(int i=0;i<v;i++)  
    {
        printf("%d %d\n",i,dist[i]);
    }
    return 0;
}*/

/*vector实现邻接表+优先队列 (假设边一开始是字符型的，这么假设是为了加点难度)*/
/*#include<iostream>  
#include<cstdio>  
#include<vector>  
#include<map>  
#include<queue>  
#include<string>  
#include<cstring>  
#define inf 0x7fffffff  
using namespace std;  
const int MAXN = 205;  
int dis[MAXN];  
int n;  //顶点数目  
int m;  //边的条数  
string src,ed; //src是源点，ed是目标点  
typedef pair<int,int> pii;  
struct edge //建立边的结构体  
{  
    int u;  
    int v;  
    int w;  
    edge(int a,int b,int c) //构造函数，建立结构体的时候直接调用这个函数，方便了一个一个赋值。  
    {  
        u = a;  
        v = b;  
        w = c;  
    }  
};  
map<string,int>M; //利用map关联容器为字符串型的边进行标号  
vector<edge> G[MAXN];//邻接表  
void init()  
{  
    M.clear();//每次循环要对map清空  
    int cnt=0;  
    cin>>n>>m;
    string u,v;//字符型顶点  
    int w;//权值  
    for(int i=1;i<=m;i++){  
        cin>>u>>v>>w;  
        if(!M.count(u))  
            M.insert(make_pair(u,++cnt));  //make_pair不仅可以用在pair<>的插入中也可用在map，vector等容器中  
        if(!M.count(v))  
            M.insert(make_pair(v,++cnt));   //利用map关联容器为字符串型的边进行标号,1,2,3...注意A不一定是1号边，最先读入的才是1号边。  
        edge E1(M[u],M[v],w);  //建立无向边，调用构造函数，简洁。  
        edge E2(M[v],M[u],w);  
        G[M[u]].push_back(E1); //建立邻接表  
        G[M[v]].push_back(E2);  
    }  
    cin>>src>>ed;  
    for(int i =1;i<=n;i++) dis[i] = (i == M[src] ? 0 : inf);//初始化dis  
}  
void dijktra()  
{  
    priority_queue<pii,vector<pii>,greater<pii> > que;  
    que.push(make_pair(0,M[src]));//将起点插入队列，pair默认是优先处理first元素，故插入优先队列先弹出队列的优先级是依据dis[]大小  
    while(!que.empty())  
    {  
        pii tmp = que.top();  
        que.pop();  
        int x = tmp.second;  
        if(tmp.first != dis[x]) continue;     //可避免结点的重复拓展，这里每一个元素出队都相当于处理一次已标号结点，如果出队的这个元素，  
                                           //他带的dis,和当前的dis不相同，证明这个结点是被处理过的,这样就不需用开一个数组来标记哪些点被处理过了。  
        for(int  i = 0;i < G[x].size();i++)  
        {  
            int y = G[x][i].v;  
            int w = G[x][i].w;  
            if(dis[y] > dis[x] + w)  
            {  
                dis[y] = dis[x] + w;  
                que.push(make_pair(dis[y],y));  
            }  
        }  
    }  
}  
int main()  
{  
   // freopen("1.in","r",stdin);  
    int _;  
    cin>>_;  
    while(_--){  
        init();  
        dijktra();  
        if(dis[M[ed]]==inf) cout<<"-1"<<endl;  
        else cout<<dis[M[ed]]<<endl;  
        //输出源点依次到ABC的距离，不能直接把dis按顺序输出，否则可读性差，因为A点不一定是1号点，1号点是最先读入的点，所以利用map以对点A,B,C依排序，
        for(map<string,int>::iterator it=M.begin();it!=M.end();it++) printf("%d ",dis[it->second]);  
        putchar('\n');  
    }  
    return 0;  
}*/