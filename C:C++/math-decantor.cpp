#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n;
char c[5777];
long long fac(int n)
{
   long long r=1;
   int i;
   for(i=1;i<=n;i++)
      r*=i;
   return r;
}
void swap(int x,int y)
{
   char t=c[x];
   c[x]=c[y];
   c[y]=t;
}
int par(int left,int right)
{
   int i=left;
   int j=right+1;
   while(1)
   {
      while(c[++i]<c[left]&&i<right);
      while(c[--j]>c[left]);
      if(i<j)
         swap(i,j);
      else
      {
         swap(left,j);
         return j;
      }
   }
}
void quickg(int left,int right)
{
   if(left<right)
   {
      int partition=par(left,right);
      quickg(left,partition-1);
      quickg(partition+1,right);
   }
}
int book[5777];
void KT(char b[],int i)
{
   int t;
   int j,k;
   memset(book,0,sizeof(book));
   for(j=1;j<=strlen(c);j++)
   {
      t=i/fac(strlen(c)-j);
      for(k=0;k<strlen(c);k++)
         if(!book[k])
         {
            if(t==0)
               break;
            --t;
         }
      b[j]=c[k];
      book[k]=1;
      i%=fac(strlen(c)-j);
   }
}
int main()
{
   int i,j;
   int z;
   scanf("%s %d",c,&z);
   char b[57];
   sort(c,c+strlen(c));
//    quickg(0,strlen(c)-1);
   KT(b,z);
   for(i=1;i<=strlen(c);i++)
      printf("%c",b[i]);
   printf("\n");
   return 0;
}