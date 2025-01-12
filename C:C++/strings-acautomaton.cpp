#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=500010+5;
const int SIGMA_SIZE=26;
struct ACAutomata
{
   int nxt[maxn][SIGMA_SIZE];
   int fail[maxn];
   int end[maxn];
   int root,L;
   int newnode()
   {
      for(int i=0;i<SIGMA_SIZE;++i)
         nxt[L][i]=-1;
      end[L++]=0;
      return L-1;
   }
   int idx(char ch)
   {
      return ch-'a';
   }
   void init()
   {
      L=0;
      root=newnode();
   }
   void insert(char buf[])
   {
      int len=strlen(buf);
      int now=root;
      // printf("now=%d\n",now);
      for(int i=0;i<len;++i)
      {
         char ch=idx(buf[i]);
         if(nxt[now][ch]==-1)
            nxt[now][ch]=newnode();
         now=nxt[now][ch];
      }
      end[now]++;
   }
   void build()
   {
      queue<int> q;
      // queue[root]=root;
      for(int i=0;i<SIGMA_SIZE;++i)
         if(nxt[root][i]==-1)
            nxt[root][i]=root;
         else
         {
            fail[nxt[root][i]]=root;
            q.push(nxt[root][i]);
         }
      while(!q.empty())
      {
         int now=q.front();
         q.pop();
         for(int i=0;i<SIGMA_SIZE;++i)
            if(nxt[now][i]==-1)
               nxt[now][i]=nxt[fail[now]][i];
            else
            {
               fail[nxt[now][i]]=nxt[fail[now]][i];
               q.push(nxt[now][i]);
            }
      }
   }
   int query(char buf[])
   {
      int len=strlen(buf);
      int now=root;
      int res=0;
      for(int i=0;i<len;++i)
      {
         now=nxt[now][idx(buf[i])];
         int tmp=now;
         while(tmp!=root)
         {
            res+=end[tmp];
            end[tmp]=0;
            tmp=fail[tmp];
         }
      }
      return res;
   }
   void Debug()
   {
      for(int i=0;i<L;++i)
      {
         printf("id=%3d,fail=%3d,end=%3d,chi=[",i,fail[i],end[i]);
         for(int j=0;j<SIGMA_SIZE;++j)
            printf("%2d",nxt[i][j]);
         printf("]\n");
      }
   }
};
char buf[1000010];
ACAutomata ac;
int main()
{
   int t;
   int n;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d",&n);
      ac.init();
      for(int i=0;i<n;++i)
      {
         scanf("%s",buf);
         ac.insert(buf);
      }
      ac.build();
      scanf("%s",buf);
      printf("%d\n",ac.query(buf));   //buf里检测
   }
   return 0;
}