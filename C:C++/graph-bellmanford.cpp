/*#include<stdio.h>
int main()
{
   int dis[10];
    int n,m,u[10],v[10],w[10];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
       scanf("%d %d %d",&u[i],&v[i],&w[i]);
    for(int i=1;i<=n;i++)
       dis[i]=99999999;
   dis[1]=0;
    for(int k=1;k<=n-1;k++)
    {
        int flag=1;
       for(int i=1;i<=m;i++)
           if(dis[v[i]]>dis[u[i]]+w[i])
            {
                flag=0;
               dis[v[i]]=dis[u[i]]+w[i];
            }
        if(flag)
           break;
    }
    for(int i=1;i<=n;i++)
       printf(" %d ",dis[i]);
    return 0;
}*/
#include<stdio.h>
int main()
{
    int dis[57];
    int u[57],v[57],w[57];
    int i,j,k;
    int n,m;
    int flag;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
       scanf("%d %d %d",&u[i],&v[i],&w[i]);
    for(i=1;i<=n;i++)
       dis[i]=99999999;
    dis[1]=0;
    for(k=1;k<n;k++)
    {
        flag=1;
        i=1;
        while(i<=m)
        {
            if(dis[v[i]]>dis[u[i]]+w[i])
            {
                dis[v[i]]=dis[u[i]]+w[i];
                flag=0;
            }
            i++;
        }
        if(flag)
           break;
    }
    i=1;
    while(i<=n)
       printf(" %d ",dis[i++]);
    return 0;
}