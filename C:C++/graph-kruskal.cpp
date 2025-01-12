#include<stdio.h>
struct edge
{
	int u;
	int v;
	int w;
};
struct edge e[10];
int n,m;
int f[7]={0},sum=0,count=0;
void quicksort(int left,int right)   //快排
{
	int i,j;
	struct edge t;
	if(left>right)
		return;
	i=left;
	j=right;
	while(i!=j)
	{
		while(e[j].w>=e[left].w&&i<j)
			j--;
		while(e[i].w<=e[left].w&&i<j)
			i++;
		if(i<j)
		{
			t=e[i];
			e[i]=e[j];
			e[j]=t;
		}
	}
	t=e[left];
	e[left]=e[i];
	e[i]=t;
	quicksort(left,i-1);
	quicksort(i+1,right);
	return;
}

int getf(int v)   //并查集
{
	// if(f[v]==v)
	// 	return v;
	// else
	// {
	// 	f[v]=getf(f[v]);
	// 	return f[v];
	// }
	int home,t;
	home=v;
	while(v!=f[v])
		v=f[v];
	while(home!=v)
	{
		t=f[home];
		f[home]=v;
		home=t;
	}
	return v;
}
int merge(int v,int u)   //并查集
{
	int t1,t2;
	t1=getf(v);
	t2=getf(u);
	if(t1!=t2)
	{
		f[t2]=t1;
		return 1;
	}
	return 0;
}
int main()
{
	int i;
	scanf("%d %d",&n,&m);   //n个节点m条边
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	quicksort(1,m);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=1;i<=m;i++)
	{
		if(merge(e[i].u,e[i].v))
		{
			count++;
			sum=sum+e[i].w;
		}
		if(count==n-1)   //让n个点连通的n-1条边
		   break;
	}
	printf("%d",sum);
	getchar();getchar();
	return 0;
}