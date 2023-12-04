/* to reverse a queue using stacking in linked list */
#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
   int data;
   struct stack* link;
}stack;
typedef struct queue
{
  int data;
  struct queue* link;
}queue;
stack* top;
queue* f=NULL,*r=NULL;

void enqueue(int item)
{
   queue* newnode;
   newnode=(queue*)malloc(sizeof(queue));
   newnode->data=item;
   newnode->link=NULL;
   if(f==NULL && r==NULL)
   {
      f=r=newnode;
   }
   else
   {
       r->link=newnode;
       r=newnode;
   }
}
int dequeue()
{
   int item;
   queue* temp=f;
   item=f->data;
   f=f->link;
   free(temp);
   return item;
}
void display()
{
   queue* temp=f;
   printf("Queue is\n");
   while(temp!=NULL)
   {
      printf("%d  ",temp->data);
      temp=temp->link;
   }
}

void push(int item)
{
   stack* newnode;
   newnode=(stack*)malloc(sizeof(stack));
   newnode->data=item;
   newnode->link=top;
   top=newnode;
}
int pop()
{
   stack* temp=top;
   int item;
   item=top->data;
   top=top->link;
   free(temp);
   return item;
}
void reverse()
{
   while(f!=NULL)
   {
      push(dequeue());
   }
   printf("Queue in reverse is\n");
   while(top!=NULL)
   {
      printf("%d ",pop());
   }
}

void main()
{
   int choice;
   printf("1.Insert\n2.Display\n3.Reverse\n4.Exit");
   do
   {
      printf("Enter choice: ");
      scanf("%d",&choice);
      switch(choice)
      {
          case 1:int data;
		 printf("Enter data to insert: ");
            	 scanf("%d",&data);
                 enqueue(data);
                 break;
	  case 2: display();break;
	  case 3:reverse();break;
	  case 4:break;
      }

   }
   while(choice!=4);
}








