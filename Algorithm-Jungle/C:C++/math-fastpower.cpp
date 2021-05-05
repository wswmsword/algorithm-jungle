// #include<stdio.h>
// int powermod(int x,int y,int z)
// {
//    int ans=1;
//    x=x%z;
//    while(y>0)
//    {
//       if(y%2==1)
//          ans=(ans*x)%z;
//       y=y/2;
//       x=(x*x)%z;
//    }
//    return ans;
// }
// int main()
// {
//    int x,y,z;
//    scanf("%d %d %d",&x,&y,&z);   //x^y%z
//    printf("%d\n",powermod(x,y,z));
//    return 0;
// }


#include<stdio.h>
int powermod(int x,int y,int z)
{
   int ans=1;
   x=x%z;
   while(y!=0)
   {
      if(y&1!=0)
         ans=(ans*x)%z;
      y>>=1;
      x=(x*x)%z;
   }
   return ans;
}
int main()
{
   int x,y,z;
   scanf("%d %d %d",&x,&y,&z);
   printf("%d",powermod(x,y,z));
   return 0;
}