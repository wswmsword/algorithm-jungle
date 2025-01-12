#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm> 
#include<iostream>
#include<cstdio>
#define For(a,b,c) for(a=b;a<=c;a++)
#include<queue>
#define inf 999999999
using namespace std;
const int maxn=1010;
int rong[510][510],liu[510][510];
int p[maxn];
int m,n;
int pre[maxn];
int sum;
void internet()
{
   queue<int>q;
	while(1)   //不断通过bfs来找增光路，然后ans+=增光路上的流量。
	{
      int i,j;
      memset(p,0,sizeof(p));
      p[1]=inf;   //这里的p数组有两个作用，一是用来标记是非访问过，其次是用来记增广路上的瓶颈。
      q.push(1);
		while(!q.empty())
		{
         int ans=q.front();
         q.pop();
			For(i,1,n)
			{
				if(!p[i]&&liu[ans][i]<rong[ans][i])
				{
					p[i]=min(p[ans],rong[ans][i]-liu[ans][i]);
					printf("p[%d]=%d ",i,p[i]);
               pre[i]=ans;//记录增广路。
               q.push(i);
            }
			}
			printf("\n");
		}
		if(!p[n])
      	break;//如果n点找不到增光路，说明已经没增广路到汇点了。
      sum+=p[n];
      int tmp=n;
		while(pre[tmp])   //不断调整流量大小。
		{
         liu[pre[tmp]][tmp]+=p[n];
			liu[tmp][pre[tmp]]-=p[n];
         tmp=pre[tmp];
		}
   }
}
int main()
{
   int i,j,k;
   int x,y,z;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
      sum=0;
      memset(pre,0,sizeof(pre));
      memset(rong,0,sizeof(rong));
		memset(liu,0,sizeof(liu));
		For(i,1,m)
		{
         scanf("%d%d%d",&x,&y,&z);
         rong[x][y]+=z;   //x到y的最大流量
      }
      internet();
		printf("%d\n",sum);
   }
	return 0;
}