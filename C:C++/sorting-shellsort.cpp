#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define size 10
void shellsort(int *z,int len)
{
   for(int r=len/2;r>=1;r/=2)
   {
      for(int i=r;i<len;i++)
      {
         int temp=z[i];
         int j=i-r;
         while(j>=0&&temp<z[j])
         {
            z[j+r]=z[j];
            j-=r;
         }
         z[j+r]=temp;
      }
   }
}
int main()
{
   int z[size+17];
   srand(time(NULL));
   for(int i=0;i<size;i++)
      z[i]=rand()/1000+100;
   printf("之前");
   for(int i=0;i<size;i++)
      printf(" %d",z[i]);
   printf("\n");
   shellsort(z,size);
   printf("以后");
   for(int i=0;i<size;i++)
      printf(" %d",z[i]);
   printf("\n");
   return 0;
}