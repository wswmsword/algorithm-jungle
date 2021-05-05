#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int f[100000057];
void marry(string x)
{
   int i;
   int j;
   for(i=1;i<x.size();i++)
   {
      j=f[i];
      while(j&&x[j]!=x[i])
         j=f[j];
      f[i+1]=(x[i]==x[j])?j+1:0;
   }
   for(i=1;i<=x.size();++i)
      printf("%d ",f[i]);
}
int find(string x,string y)
{
   int sum=0;
   int j=0,i=0;
   marry(x);
   for(i=0;i<y.size();i++)
   {
      while(j&&x[j]!=y[i])
         j=f[j];
      j=(x[j]==y[i])?j+1:0;
      sum=(j==x.size())?sum+1:sum;
   }
   return sum;
}
int main()
{
   string x,y;
   cin>>x>>y;
   cout<<find(x,y)<<endl;
   return 0;
}