#include<stdio.h>
void ce(int z)
{
   if(z!=0)
   {
      ce(z/2);
      printf("%d",z%2);
   }
}
int main()
{
   int z;
   int i,t;
   scanf("%d",&z);
   if(z==0)
      printf("0");
   else
      ce(z);
   return 0;
}