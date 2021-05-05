#include<stdio.h>
int main()
{
	int n,m,i,j,k;
	int u[8],v[8],w[8];
	int first[6],next[8];
	int dis[6]={0};
	int book[6]={0};
   int que[101]={0};
	int head=1,tail=1;
	int inf=99999999;
	scanf("%d %d",&n,&m);   //n个根据地 m条路
	for(i=2;i<=n;i++)
	   dis[i]=inf;
	for(i=1;i<=n;i++)
	   first[i]=-1;   //初始化邻接表
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		next[i]=first[u[i]];   //邻接表
		first[u[i]]=i;
	}
	que[tail]=1;
	tail++;
	book[1]=1;
	while(head<tail)
	{
		k=first[que[head]];
		while(k!=-1)
		{
			if(dis[v[k]]>dis[u[k]]+w[k])
			{
				dis[v[k]]=dis[u[k]]+w[k];
				if(book[v[k]]==0)
				{
					que[tail]=v[k];
					tail++;
					book[v[k]]=1;
				}
			}
			k=next[k];
		}
		book[que[head]]=0;
		head++;
	}
	for(i=1;i<=n;i++)
	   printf(" %d ",dis[i]);
	return 0;
}