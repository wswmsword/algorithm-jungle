#include<stdio.h>
int z[57][57];
int main()
{
   int n,m;
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
         if(i!=j)
            z[i][j]=99999999;
   for(int o=1;o<=m;o++)
   {
      int t,y,u;
      scanf("%d %d %d",&t,&y,&u);
      z[t][y]=u;
   }
   for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
            if(z[i][j]>z[i][k]+z[k][j])
               z[i][j]=z[i][k]+z[k][j];
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
         printf(" %d ",z[i][j]);
      printf("\n");
   }
   return 0;
}