#include<stdio.h>
int z[577];
int n,m;
void init()
{
   for(int i=1;i<=n;i++)
      z[i]=i;
}
int find(int v)
{
   if(z[v]==v)
      return v;
   else
   {
      z[v]=find(z[v]);
      return z[v];     //递归方法
      /*int i=v;
      while(z[i]!=i)
         i=z[i];
      while(z[v]!=i)   //循环找到老大
      {
         int t=z[v];
         z[v]=i;
         v=t;
      }
      return v;*/
   }
}
void merge(int x,int y)
{
   int t0,t1;
   t0=find(x);
   t1=find(y);
   if(t0!=t1)
      z[t1]=t0;
}
int main()
{
   scanf("%d%d",&n,&m);   //n个点
   init();
   int x,y;
   for(int i=1;i<=m;i++)
   {
      scanf("%d%d",&x,&y);
      merge(x,y);
   }
   int count=0;
   for(int i=1;i<=n;i++)
      if(z[i]==i)
         count++;
   printf("%d\n",count);   //输出count个老大
   return 0;
}