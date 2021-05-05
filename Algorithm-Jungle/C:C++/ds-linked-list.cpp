#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
};
int InsertList(LinkList head,int x,int i)
{
   ListNode *p,*s;
   p=GetNode(head,i-1);
   if(p==NULL)
   {
      printf("no %d\n",i-1);
      return 0;
   }
   s=(ListNode *)malloc(sizeof(ListNode));
   if(s==NULL)
   {
      printf("fail\n");
      return 0;
   }
   s->data=x;
   s->next=p->next;
   p->next=s;
   return 1;
}
int main()
{
   struct node *head;
   int n;
   scanf("%d",&n);
   head=NULL;
   int z;
   struct node *p,*q;
   for(int i=1;i<=n;i++)
   {
      scanf("%d",&z);
      p=(struct node *)malloc(sizeof(struct node));
      p->data=z;
      p->next=NULL;
      if(head==NULL)
         head=p;
      else
         q->next=p;
      q=p;
   }
   struct node *t;
   t=head;
   while(t!=NULL)
   {
      printf(" %d",t->data);
      t=t->next;
   }
   printf("\n");
   return 0;
}