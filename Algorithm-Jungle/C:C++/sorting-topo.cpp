#include<iostream>
#include<cstdio>
using namespace std;
int de[101];
int que[10001];
int head[101];
int ans[101],qaq=0;
struct edge
{
   int to,next; 
}g[10001]; 
int n,num;
void ins(int u,int v)   //u比v高
{ 
   g[++num].next=head[u];
   head[u]=num;
   g[num].to=v;
} 
void toposort()   //拓扑排序
{ 
   int h=1,t=0;
   for(int i=1;i<=n;i++) 
      if(de[i]==0)
         que[++t]=i;//我们只做大自然的搬运工
   while(h<=t)//农夫山泉有点甜
   {
      int tmp=que[h];
      ans[++qaq]=tmp;
      for(int i=head[tmp];i;i=g[i].next)
         if(!--de[g[i].to])
            que[++t]=g[i].to;
      h++;
   }
} 
int main()
{
   scanf("%d",&n);   //n个士兵
   int x,y;
   while(~scanf("%d%d",&x,&y))   //x比y高
   {
      de[y]++;   //y度加一
      ins(x,y);
   }
   toposort();
   if(qaq<n)printf("-1\n");
   else
   {
      for(int i=1;i<qaq;i++)
         printf("%d ",ans[i]);
      printf("%d\n",ans[qaq]);
   }
}