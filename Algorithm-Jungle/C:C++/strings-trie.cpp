#include<stdio.h>
const int maxNode=1005*25;   //最大节点的数量
const int sigma_size=26;   //每个节点的子节点个数
int c[maxNode][sigma_size];   
int cnt[maxNode];
int sz;   //字典数中下一个节点的下标，根节点编号为0，不指向任何字符
void init()
{
   sz=1;
   memset(c[0],0,sizeof(c[0]));
   memset(cnt,0,sizeof(cnt));
}
int idx(char ch)
{
   return ch-'a';
}
void insert(char s[],int v=0)
{
   int u=0;
   for(int i=0;s[i];++i)
   {
      char ch=idx(s[i]);
      if(!c[u][ch])
      {
         memset(c[sz],0,sizeof(c[sz]));
         c[u][ch]=sz++;
      }
      u=c[u][ch];
      ++cnt[u];
   }
}
int query(char s[])
{
   int u=0,n=strlen(s);
   for(int i=0;i<n;++i)
   {
      char ch=idx(s[i]);
      if(!c[u][ch]||u!=0&&cnt[u]<=1)
         return i;
      u=c[u][ch];
   }
   return n;
}