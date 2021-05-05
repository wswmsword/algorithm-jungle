#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream> 
using namespace std;
int N;
struct matrix
{
   int z[5][7];
}origin,res;
matrix multiply(matrix x,matrix y)
{
   matrix temp;
   memset(temp.z,0,sizeof(temp.z));
   for(int i=0;i<3;i++)
      for(int j=0;j<3;j++)
         for(int k=0;k<3;k++)
            temp.z[i][j]+=x.z[i][k]*y.z[k][j];
   return temp;
}
void init()
{
   printf("随机矩阵如下：\n");
   for(int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
      {
         origin.z[i][j]=rand()%10;
         printf("%9d",origin.z[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   memset(res.z,0,sizeof(res.z));
   res.z[0][0]=res.z[1][1]=res.z[2][2]=1;   //将res.z初始化为单位矩阵 
}
void calc(int n,int w)
{
   while(n)
   {
      if(n&1)   //当前幂次为奇数
         res=multiply(res,origin);
      n>>=1;
      origin=multiply(origin,origin);
   }
   printf("%d次幂结果如下：\n",w);
   for(int i=0;i<3;i++)
   {
      for(int j=0;j<3;j++)
         printf("%9d",res.z[i][j]);
      printf("\n");
   }
   printf("\n");
}
int main()
{
   while(cin>>N)   //N次方
   {
      init();   //生成随机3*3的矩阵
      calc(N,N);
   }
   return 0;
}