#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int size;
void heapsort(int z[],int n)
{
   int i,j,h,k;
   for(i=n/2-1;i>=0;i--)
   {
      while(2*i+1<n)
      {
         j=2*i+1;   //左子树
         if(j+1<n)   //右子树
            if(z[j]<z[j+1])   //有右子树再判断两个子树的大小
               j++;
         if(z[j]>z[i])    //交换
         {
            int t=z[i];
            z[i]=z[j];
            z[j]=t;
            i=j;   //可能破坏了下面的
         }
         else
            break;
      }
   }
   for(i=n-1;i>0;i--)
   {
      int t=z[0];
      z[0]=z[i];
      z[i]=t;
      k=0;
      while(2*k+1<i)
      {
         j=2*k+1;
         if(j+1<i)
            if(z[j]<z[j+1])
               j++;
         if(z[k]<z[j])
         {
            t=z[k];
            z[k]=z[j];
            z[j]=t;
            k=j;
         }
         else
            break;
      }
   }
}
int main()
{
   int z[57];
   scanf("%d",&size);
   for(int i=0;i<size;i++)
      scanf("%d",&z[i]);
   printf("之前");
   for(int i=0;i<size;i++)
      printf("%d ",z[i]);
   printf("\n");
   heapsort(z,size);
   printf("以后");
   for(int i=0;i<size;i++)
      printf("%d ",z[i]);
   printf("\n");
   return 0;
}