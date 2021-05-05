#include<stdio.h>
int main()
{
   int n,m;
   int u[57],v[57],w[57];
   int first[57],next[57];
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
      first[i]=-1;
   for(int i=1;i<=m;i++)
   {
      scanf("%d %d %d",&u[i],&v[i],&w[i]);   //始，末，长
      next[i]=first[u[i]];
      first[u[i]]=i;
   }
   for(int i=1;i<=n;i++)
   {
      int t=first[i];
      while(t!=-1)
      {
         printf(" %d ",t);
        t=next[t];
      }
      printf("\n");
   }
}