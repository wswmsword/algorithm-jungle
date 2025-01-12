#include<stdio.h>
char H[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void ce(int z)
{
   if(z!=0)
   {
      ce(z/16);
      printf("%c",H[z%16]);
   }

}
int main()
{
   int z=0;
   scanf("%d",&z);
   if(z==0)
	  printf("%c",H[0]);
   else
   {	 
      ce(z);
   }	
   return 0;
}