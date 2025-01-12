#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1000];
char s_new[2000];
int p[2000];
int Init()
{
   int len=strlen(s);
   s_new[0]='$';   //防止越界
   s_new[1]='#';
   int j=2;
   for(int i=0;i<len;i++)   //归为奇数长
   {
      s_new[j++]=s[i];
      s_new[j++]='#';
   }
   s_new[j]='\0';
   return j;   //返回 s_new 的长度
}
int Manacher()
{
   int len=Init();   //取得新字符串长度并完成向 s_new 的转换
   int max_len=-1;   //最长回文长度
   int id;
   int mx=0;
   for(int i=1;i<len;i++)
   {
      if(i<mx)
         p[i]=min(p[2*id-i],mx-i);   //mx和2*id-i的含义
      else
         p[i]=1;
      while(s_new[i-p[i]]==s_new[i+p[i]])   //无需边界判断，左有'$',右有'\0'
         p[i]++;
      if(mx<i+p[i])   //希望mx尽可能的远，这样才能更有机会执行if(i<mx)这句代码，从而提高效率
      {
         id=i;
         mx=i+p[i];
      }
      max_len=max(max_len,p[i]-1);
   }
   return max_len;
}
int main()
{
   while(printf("输入字符串：\n"))
   {
      scanf("%s",s);
      printf("最长回文长度为 %d\n\n",Manacher());
   }
   return 0;
}