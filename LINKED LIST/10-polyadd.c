/* To represent two polynomials using linked list and perform addition operation */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int coeff;
   int exp;
   struct node* link;
}node;

void insertpoly(node* header,int exp,int coeff)
{
   node* newnode,*temp;
   newnode=(node*)malloc(sizeof(node));
   newnode->coeff=coeff;
   newnode->exp=exp;
   newnode->link=NULL;
   if(header->link==NULL)
   {
      header->link=newnode;
      return;
   }
   temp=header;
   while(temp->link!=NULL)
   {
      temp=temp->link;
   }
   temp->link=newnode;
   return;
}

void display(node* header)
{
   node* ptr=header->link;
   while(ptr!=NULL)
   {
      printf("%dx^%d",ptr->coeff,ptr->exp);
      if (ptr->link != NULL)
      {
            printf(" + ");
      }
      ptr=ptr->link;
   }
   printf("\n");
}

void addpoly(node* poly1,node* poly2,node* result)
{
   node *p1=poly1->link;
   node *p2=poly2->link;
   while(p1!=NULL && p2!=NULL)
   {
      if(p1->exp>p2->exp)
      {
         insertpoly(result,p1->exp,p1->coeff);
         p1=p1->link;
      }
      else if(p1->exp<p2->exp)
      {
         insertpoly(result,p2->exp,p2->coeff);
         p2=p2->link;
      }
      else
      {
         insertpoly(result,p1->exp,p1->coeff+p2->coeff);
         p1=p1->link;
         p2=p2->link;
      }
   }
   while(p1!=NULL)
   {
      insertpoly(result,p1->exp,p1->coeff);
      p1=p1->link;
   }
   while(p2!=NULL)
   {
      insertpoly(result,p2->exp,p2->coeff);
      p2=p2->link;
   }
}

void main()
{
   int m,n,x;
   node* P,*Q,*R;
   P=(node*)malloc(sizeof(node));
   Q=(node*)malloc(sizeof(node));
   R=(node*)malloc(sizeof(node));
   P->link=NULL;
   Q->link=NULL;
   R->link=NULL;
   printf("Enter degrees of first and second polynomial: ");
   scanf("%d%d",&m,&n);
   printf("Enter first polynomail\n");
   for(int i=m;i>=0;i--)
   {
      printf("Enter coefficient: ");
      scanf("%d",&x);
      if(x==0)
         continue;
      insertpoly(P,i,x);

   }
   printf("Enter second polynomail\n");
   for(int i=n;i>=0;i--)
   {
      printf("Enter coefficient : ");
      scanf("%d",&x);
      if(x==0)
         continue;
      insertpoly(Q,i,x);
   }
   //addpoly(P,Q,R);
   multiplypoly(P,Q,R);
   printf("Polnomials are\n");
   printf("P: ");
   display(P);
   printf("Q: ");
   display(Q);
   printf("Sum is: ");
   display(R);
}

