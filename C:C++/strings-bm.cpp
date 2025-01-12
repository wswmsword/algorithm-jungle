#include<iostream>
#include<string>
#include<algorithm>
#define MAX_CHAR 256
#define MAX_LENGTH 1057
using namespace std;
void GetBC(string &p,int &m,int bc[])   /* 计算坏字符数组 */
{
   int i;
   for(i=0;i<MAX_CHAR;++i)
      bc[i]=m;
   for(i=0;i<m-1;++i)
      bc[p[i]]=m-1-i;
}
void Suffixes(string &p,int &m,int suff[])   /* 计算最长公共后缀数组 */
{
   int f,g=m-1,i;
   suff[m-1]=m;
   for(i=m-2;i>=0;--i)
   {
      if(i>g&&suff[i+m-1-f]<i-g)
         suff[i]=suff[i+m-1-f];
      else
      {
         if(i<g)
            g=i;
         f=i;
         while(g>=0&&p[g]==p[g+m-1-f])   //前者从0开始，后者从m-1-f开始
            --g;
         suff[i]=f-g;   //已匹配的长度，f是本需比较的长度，g是未匹配的字符
      }
   }
   for(i=0;i<=m-1;++i)
      printf("suff[%d]=%d\n",i,suff[i]);
   // printf("\n");
}
void GetGS(string &p,int &m,int gs[])   /* 计算好后缀数组 */
{
   int i,j;
   int suff[MAX_LENGTH];   //后缀数组
   Suffixes(p,m,suff);
   for(i=0;i<m;++i)    // 第三种情况，不存在好后缀和字符串匹配，后移整个搜索词长度
      gs[i]=m;
   j=0;
   for(i=m-1;i>=0;--i)    // 第二种情况，存在好后缀，但不是最长的，和搜索词前缀匹配
   {
      if(suff[i]==i+1)
         for(;j<m-1-i;++j)
            if(gs[j]==m)
               gs[j]=m-1-i;
   }
   for(i=0;i<=m-2;++i)    // 第一种情况，最长的好后缀能与长字符串间有匹配
      gs[m-1-suff[i]]=m-1-i;
//    for(i=0;i<m;++i)
//       printf("%d ",gs[i]);
//    printf("\n");
}
void BM(string &s,int &n,string &p,int &m)   //s长m短
{
   int bc[MAX_LENGTH],gs[MAX_LENGTH];
   GetBC(p,m,bc);   //bad char
   GetGS(p,m,gs);   //good suff
   int j=0,i;
   while(j<=n-m)
   {
      for(i=m-1;i>=0&&p[i]==s[i+j];--i);
      if(i<0)
      {
         cout<<"在下标 "<<j<<" 位置找到匹配\n";
         j+=gs[0];
      }
      else
         j+=max(bc[s[i+j]]-m+1+i,gs[i]);
   }
}
int main()
{
   string s,p;
   int n,m;
   while(cin>>s>>p)
   {
      n=s.size();
      m=p.size();
      BM(s,n,p,m);
      cout<<endl;
   }
   return 0;
}
// #include <cstdio>  
// #include <cstring>  
// #include <algorithm>  
// #include <iostream>  
// #include <string>  
// using namespace std;  

// int sum=0;
// int f[10005];  
// int good[10777];
// int bad[577];
// int book_b[577];
// void g(string x)   //好字符   ABCDEFBCA   BCA
// {
//    int step=9999;
//    for(int i=0;i<x.size();i++)
//    {
//       int t=0;
      
//       for(int j=0;j<=i;j++)
//       {
//          if(x[j]!=x[x.size()-1-i+j])
//             break;
//          else
//             t++;
//       }
//       good[x.size()-1-i]=i==x.size()-1?step:(t==i+1?x.size()-i-1:x.size());   //下标是对比字符串的长度，就是短字符串的长度
//       if(i<x.size()-1)
//          step=good[x.size()-1-i]<step?good[x.size()-1-i]:step;
//    }
//    for(int i=0;i<x.size();i++)
//       printf(" %d ",good[i]);
//    printf("\n");
// }
// void b(string x)   //坏字符
// {
// //    for(int i=x.size()-1;i>=0;i--)
// //    {
// //       if(!book_b[x[i]-65])
// //       {
// //          bad[x[i]-65]=x.size()-i-1;   //下标是所有字符的长度
// //          book_b[x[i]-65]=1;
// //       }
// //    }
// //    for(int i=0;i<26;i++)
// //       if(book_b[i])
// //          continue;
// //       else
// //          bad[i]=x.size();
//    for(int i=x.size()-1;i>=0;i--)
//    {
      
//    }
//    for(int i=0;i<26;i++)
//       printf(" %d ",bad[i]);
//    printf("\n");
// }
// void find(string x,string y)
// {
//    g(x);   //生成好字符表
//    b(x);   //生成坏字符表
//    for(int i=x.size()-1;i<y.size();i++)   //往后遍历整个y串
//    {
//       int t=99999;
//       int step;
//       for(int j=i,k=x.size();j>i-x.size(),k>=0;j--,k--)   //从i开始往前数x串长度个数
//       {
//          if(x[k]==y[j])   //对应相等
//          {
//             t=t>good[j]?good[j]:t;
//             if(k==0)
//                sum++;
//          }
//          else
//          {
//             step=bad[y[j]-65]>t?bad[y[j]-65]-1:t-1;
//             i+=step;
//             break;
//          }
//       }
//    }
// }
// int main()
// {
//    string x,y;
//    cin>>x>>y;   //x短y长
//    find(x,y);
//    cout<<sum<<endl;
//    printf("\n");
//    return 0;
// }