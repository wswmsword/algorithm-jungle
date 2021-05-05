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
int PowSumMod(int a,int n,int p)
{
   if(n==1)
      return a%p;
   if(n&1==0)
      return (1+powermod(a,n/2,p))*PowSumMod(a,n/2,p)%p;
   else
      return ((1+powermod(a,(n-1)/2,p))*PowSumMod(a,(n-1)/2,p)+powermod(a,n,p))%p;
}
int main()
{
   int a,n,p;
   scanf("%d %d %d",&a,&n,&p);
   printf("%d",PowSumMod(a,n,p));
   return 0;
}