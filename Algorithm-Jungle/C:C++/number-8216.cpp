#include<string.h>
#include<math.h>
#include<stdio.h>
char Z[100100];
char H[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int TO[400400];
int E[200200];
int main()
{
   int n,i,l,j=0,temp=0;
   temp=0;
   memset(Z,'\0',sizeof(Z));
   scanf("%s",Z);
   l=strlen(Z);
   for(i=0;i<l;i++)
   {
      switch(Z[i])
      {
         case '0':{TO[j++]=0;TO[j++]=0;TO[j++]=0;}break;
         case '1':{TO[j++]=0;TO[j++]=0;TO[j++]=1;}break;
         case '2':{TO[j++]=0;TO[j++]=1;TO[j++]=0;}break;
         case '3':{TO[j++]=0;TO[j++]=1;TO[j++]=1;}break;
         case '4':{TO[j++]=1;TO[j++]=0;TO[j++]=0;}break;
         case '5':{TO[j++]=1;TO[j++]=0;TO[j++]=1;}break;
         case '6':{TO[j++]=1;TO[j++]=1;TO[j++]=0;}break;
         case '7':{TO[j++]=1;TO[j++]=1;TO[j++]=1;}break;
         
      }
   }
   j--;
   for(i=j;i>=0;i-=4)
      E[temp++]=TO[i]*1+TO[i-1]*2+TO[i-2]*4+TO[i-3]*8;
   for(i=temp-1;i>=0;i--)
   {
      if((i==temp-1)&&E[i]==0)continue;
      printf("%c",H[E[i]]);
   }
   return 0;
}