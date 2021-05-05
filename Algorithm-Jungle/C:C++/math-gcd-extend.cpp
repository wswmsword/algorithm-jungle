#include<stdio.h>
void kcuf(int b,int m,int &x,int &y,int &i)
{
	// int x2,y2;
	// if (!m)
	// {
   //    i=b;
	// 	x=1;
	// 	y=0;
	// 	return ;
	// }
	// kcuf(m,b%m,x2,y2,i);
	// x=y2;
	// y=x2-(b/m)*y2;
   // return ;
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
int main()
{
   int i,b,m;
   int x,y;
   scanf("%d %d",&b,&m);
   kcuf(b,m,x,y,i);
   printf("(%d)*%d+(%d)*%d=%d",x,b,y,m,i);
   return 0;
}