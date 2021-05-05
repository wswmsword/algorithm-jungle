/*#include<stdio.h>
#include<stdlib.h>
int z[57];
void swap(int x,int y)
{
   int t=z[x];
   z[x]=z[y];
   z[y]=t;
}
int par(int c[],int left,int right)
{
   int i=right;
   int j=left-1;
   while(1)
   {
      while(c[--i]>c[right]&&i>left);
      while(c[++j]<c[right]);
      if(i>=j)
         swap(i,j);
      else
      {
         swap(j,right);
         break;
      }
   }
   return j;
}
void quicksort(int z[],int left,int right)
{
   if(left<right)
   {
      int partition=par(z,left,right);
      quicksort(z,left,partition-1);
      quicksort(z,partition+1,right);
   }
}
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
      scanf("%d",&z[i]);
   quicksort(z,1,n);
   for(int i=1;i<=n;i++)
      printf(" %d",z[i]);
   printf("\n");
   return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
int z[57];
void swap(int x,int y)
{
	int t=z[x];
	z[x]=z[y];
	z[y]=t;
}
int par(int left,int right)
{
	int i=left;
	int j=right+1;
	while(1)
	{
		while(z[--j]>z[left]);
		while(z[++i]<z[left]&&i<right);
		if(j>i)
		   swap(i,j);
		else
		{
			swap(j,left);
			break;
		}
	}
	return j;
}
void quicksort(int left,int right)
{
	if(left<right)
	{
		int partition=par(left,right);
		quicksort(left,partition-1);
		quicksort(partition+1,right);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	   scanf("%d",&z[i]);
	quicksort(1,n);
	for(int i=1;i<=n;i++)
	   printf(" %d",z[i]);
	printf("\n");
	return 0;
}//designed by 智 with love