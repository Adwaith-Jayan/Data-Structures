/* To represent two variable polynomials using linked list and perform addition */
#include <stdio.h>
#include <stdlib.h>

typedef struct poly
{
   int coeff;
   int exp_x;
   int exp_y;
   struct poly* link;
}node;

void insertpoly(node* header, int coeff,int exp_x,int exp_y)
{
   node* newnode,*ptr;
   newnode=(node*)malloc(sizeof(node));
   newnode->coeff=coeff;
   newnode->exp_x=exp_x;
   newnode->exp_y=exp_y;
   newnode->link=NULL;
   if(header->link==NULL)
   {
      header->link=newnode;
      return;
   }
   ptr=header;
   while(ptr->link!=NULL)
   {
      ptr=ptr->link;
   }
   ptr->link=newnode;
}
void display(node* header)
{
   node *ptr=header->link;
   while(ptr!=NULL)
   {
      printf("%dx^%dy^%d",ptr->coeff,ptr->exp_x,ptr->exp_y);
      if(ptr->link!=NULL)
      {
         printf(" + ");
      }
      ptr=ptr->link;
   }
   printf("\n");
}

void addpoly(node* poly1,node *poly2, node* result)
{
   node* p1=poly1->link;
   node* p2=poly2->link;
   while(p1!=NULL && p2!=NULL)
   {
      if((p1->exp_x > p2->exp_x) || (p1->exp_x == p2->exp_x && p1->exp_y>p2->exp_y))
      {
          insertpoly(result,p1->coeff,p1->exp_x,p1->exp_y);
          p1=p1->link;
      }
      else if((p1->exp_x < p2->exp_x) || (p1->exp_x == p2->exp_x && p1->exp_y < p2->exp_y))
      {
          insertpoly(result,p2->coeff,p2->exp_x,p2->exp_y);
          p2=p2->link;
      }
      else
      {
         insertpoly(result, p1->coeff + p2->coeff, p1->exp_x, p1->exp_y);
         p1 = p1->link;
         p2 = p2->link;
      }
   }
   while (p1 != NULL)
   {
      insertpoly(result, p1->coeff, p1->exp_x, p1->exp_y);
      p1 = p1->link;
   }

   while (p2 != NULL)
   {
      insertpoly(result, p2->coeff, p2->exp_x, p2->exp_y);
      p2 = p2->link;
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
   printf("Enter degrees of first polynomial(x,y): ");
   scanf("%d%d",&m,&n);
   printf("Enter first polynomial\n\n");
   for(int i=m;i>=0;i--)
   {
      for(int j=n;j>=0;j--)
      {
         printf("Enter coefficinet of x^%d . y^%d : ",i,j);
         scanf("%d",&x);
         if(x!=0)
         {
            insertpoly(P,x,i,j);
         }
      }
   }
   printf("Enter degrees of second polynomial (x and y): ");
   scanf("%d%d", &m, &n);

   printf("Enter second polynomial:\n");
   for (int i = m; i >= 0; i--)
   {
      for (int j = n; j >= 0; j--)
      {
         printf("Enter coefficient for x^%d * y^%d: ", i, j);
         scanf("%d", &x);
         if (x != 0)
         {
             insertpoly(Q, x, i, j);
         }
      }
   }
   addpoly(P,Q,R);
   printf("Polynomials are:\n");
   printf("P: ");
   display(P);
   printf("Q: ");
   display(Q);
   printf("Sum is: ");
   display(R);
}







