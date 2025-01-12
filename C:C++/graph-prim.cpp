#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int INFINITE=1<<30;
struct Edge
{
   int v;
   int w;
   Edge(int v_=0,int w_=INFINITE):v(v_),w(w_){}
   bool operator<(const Edge&e)const
   {
      return w>e.w;   //在队列里，边权值越小越优先
   }
};
vector<vector <Edge> >G(110);   //图的邻接表
int HeapPrim(const vector<vector <Edge> >&G,int n)   //G是邻接表,n是顶点数目，返回值是最小生成树权值和
{
   int i,j,k;
   Edge xDist(0,0);
   priority_queue<Edge>pq;   //存放顶点及其到在建生成树的距离
   vector<int>vDist(n);   //各顶点到已经建好的那部分树的距离
   vector<int>vUsed(n);   //标记顶点是否已经被加入最小生成树
   int nDoneNum=0;   //已经被加入最小生成树的顶点数目
   for(i=0;i<n;i++)
   {
      vUsed[i]=0;
      vDist[i]=INFINITE;
   }
   nDoneNum=0;
   int nTotalW=0;   //最小生成树总权值
   pq.push(Edge(0,0));   //开始只有顶点0，它到最小生成树距离0
   while(nDoneNum<n&&!pq.empty())
   {
      do   //每次从队列里面拿离在建生成树最近的点
      {
         xDist=pq.top();
         pq.pop();
      }while(vUsed[xDist.v]==1&&!pq.empty());
      if(vUsed[xDist.v]==0)
      {
         nTotalW+=xDist.w;
         vUsed[xDist.v]=1;
         nDoneNum++;
         for(i=0;i<G[xDist.v].size();i++)   //更新新加入点的邻点
         {
            int k=G[xDist.v][i].v;
            if(vUsed[k]==0)
            {
               int w=G[xDist.v][i].w;
               if(vDist[k]>w)
               {
                  vDist[k]=w;
                  pq.push(Edge(k,w));
               }
            }
         }
      }
   }
   if(nDoneNum<n)
      return -1;
   return nTotalW;
}
int main()
{
   int N;
   while(cin>>N)
   {
      for(int i=0;i<N;++i)
         G[i].clear();
      for(int i=0;i<N;++i)
         for(int j=0;j<N;++j)
         {
            int w;
            cin>>w;
            G[i].push_back(Edge(j,w));
         }
      cout<<HeapPrim(G,N)<<endl;
   }
}
#include<stdio.h>
int main()
{
   int n,m,i,j,k,min,t1,t2,t3;
   int e[7][7],dis[7],book[7]={0};
   int inf=99999999;
   int count=0,sum=0;
   scanf("%d %d",&n,&m);
   for(i=1;i<=n;i++) 
      for(j=1;j<=n;j++)
         if(i==j)
            e[i][j]=0;
         else
            e[i][j]=inf;
   for(i=1;i<=m;i++)
   {
      scanf("%d %d %d",&t1,&t2,&t3);
      e[t1][t2]=t3;
      e[t2][t1]=t3;
   }
   for(i=1;i<=n;i++)
      dis[i]=e[1][i];
   book[1]=1;
   count++;
   while(count<n)
   {
      min=inf;
      for(i=1;i<=n;i++)
      {
         if(book[i]==0&&dis[i]<min)
         {
            min=dis[i];
            j=i;
         }
      }
      book[j]=1;
      count++;
      sum=sum+dis[j];
      for(k=1;k<=n;k++)
         if(book[k]==0&&dis[k]>e[j][k])
            dis[k]=e[j][k];
   }
   printf("%d",sum);
   return 0;
}