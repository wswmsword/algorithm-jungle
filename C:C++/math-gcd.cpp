#include<stdio.h>
int main()
{
   int x,y;
   int i;
   scanf("%d %d",&x,&y);
   if(y>x)
   {
      x=x+y;
      y=x-y;
   }
   for(i=x%y;i;i=x%y)
   {
      x=y;
      y=i;
   }
   printf("%d",y);
   return 0;
}