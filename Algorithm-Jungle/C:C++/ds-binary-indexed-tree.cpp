#include<stdio.h>
int N;
int c[157][157];
int lowbit(int t)
{
   return t&(-t);
}
void update(int x,int y,int v)
{
   int i,j,k;
   for(i=x;i<N+1;i+=lowbit(i))
      for(j=y;j<N+1;j+=lowbit(j))
         c[i][j]+=v;
}
int query(int x,int y)
{
   int res=0;
   int i,j,k;
   for(i=x;i>0;i-=lowbit(i))
      for(j=y;j>0;j-=lowbit(j))
         res+=c[i][j];
   return res;
}
int sum(int x,int y,int xx,int yy)
{
   --x;--y;
   return query(xx,yy)+query(x,y)-query(xx,y)-query(x,yy);
}
int main()
{
   int v;
   int i,j,k;
   scanf("%d",&N);
   for(i=1;i<N+1;++i)
      for(j=1;j<N+1;++j)
      {
         scanf("%d",&v);
         update(i,j,v);
      }
   printf("%d..\n",sum(2,2,3,3));
   return 0;
}