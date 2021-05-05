#include<stdio.h>
typedef long long LL;
void kcuf(LL b,LL m,LL &x,LL &y,LL &i)
{
   if(!m)
   {
      i=b;
      x=1;
      y=0;
      return ;
   }
   kcuf(m,b%m,y,x,i);
   y-=b/m*x;
}
LL inv(LL s,LL m)
{
   LL i,x,y;
   kcuf(s,m,x,y,i);
   return i==1?(x%m+m)%m:-11;   //避免负数从而加x%m+m
}
int main()
{
   LL s,m;
   scanf("%lld %lld",&s,&m);
   printf("%lld", inv(s,m));
   return 0;
}