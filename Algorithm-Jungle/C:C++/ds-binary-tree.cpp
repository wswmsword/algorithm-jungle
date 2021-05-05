#include<stdio.h>
#include<stdlib.h>
typedef struct Bitnode
{
   char data;
   struct Bitnode *L,*R;
}node;
node *create()
{
   char pt;
   scanf("%c",&pt);
   node *T;
   if(pt=='#')
      T=NULL;
   else
   {
      T=(node*)malloc(sizeof(node));
      T->data=pt;
      T->L=create();
      T->R=create();
   }
   return T;
}
void preorder(node *T)
{
   if(T)
   {
      printf("%c",T->data);
      preorder(T->L);
      preorder(T->R);
   }
}
int main()
{
   node *T;
   T=create();
   preorder(T);
   printf("\n");
   return 0;
}