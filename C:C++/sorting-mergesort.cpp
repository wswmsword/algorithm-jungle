#include<stdio.h>
#include<stdlib.h>
void merge(int z[],int b[],int st,int mid,int ed)
{
   int i=st,j=mid+1,k=st;
   while(i!=mid+1&&j!=ed+1)
   {
      if(z[i]>z[j])
         b[k++]=z[j++];
      else
         b[k++]=z[i++];
   }
   while(i!=mid+1)
      b[k++]=z[i++];
   while(j!=ed+1)
      b[k++]=z[j++];
   for(i=st;i<=ed;i++)
      z[i]=b[i];
}
void mergesort(int z[],int b[],int st,int ed)
{
   int mid;
   if(st<ed)
   {
      mid=(st+ed)/2;
      mergesort(z,b,st,mid);
      mergesort(z,b,mid+1,ed);
      merge(z,b,st,mid,ed);
   }
}
int main()
{
   int i,n;
   int z[57],b[57];
   scanf("%d",&n);
   for(i=1;i<=n;i++)
      scanf("%d",&z[i]);
   mergesort(z,b,1,n);
   for(i=1;i<=n;i++)
      printf(" %d",z[i]);
   return 0;
}