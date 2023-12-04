/* Program to implement linked list with menu driven operations */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int data;
   struct node* link;
}node;
void display(node* header)
{
   node* ptr;
   ptr=header->link;
   if(ptr==NULL)
   {
      printf("List empty\n");
      return;
   }
   printf("Linked list is\n");
   while(ptr!=NULL)
   {
      printf("%d  ",ptr->data);
      ptr=ptr->link;
   }
}
void Insert_front(node* header,int x)
{
   node* newnode;
   newnode=(node*)malloc(sizeof(node));
   newnode->data=x;
   newnode->link=header->link;
   header->link=newnode;
}
void Insert_end(node* header,int x)
{
   node* newnode,*ptr;
   newnode=(node*)malloc(sizeof(node));
   ptr=header;
   while(ptr->link!=NULL)
   {
      ptr=ptr->link;
   }
   newnode->data=x;
   newnode->link=NULL;
   ptr->link=newnode;
}
void Insert_any(node* header,int x,int key)
{
   node* newnode,*ptr;
   newnode=(node*)malloc(sizeof(node));
   ptr=header;
   while(ptr->data!=key && ptr->link!=NULL)
   {
      ptr=ptr->link;
   }
   if(ptr->link==NULL)
   {
      printf("Not present\n");
      return;
   }
   newnode->data=x;
   newnode->link=ptr->link;
   ptr->link=newnode;
}

void Delete_front(node* header)
{
   node* ptr=header->link;
   header->link=ptr->link;
   printf("Node deleted, %d\n",ptr->data);
   free(ptr);
}
void Delete_end(node* header)
{
   node* temp;
   node* ptr=header->link;
   while(ptr->link!=NULL)
   {
      temp=ptr;
      ptr=ptr->link;
   }
   temp->link=NULL;
   printf("Node deleted, %d\n",ptr->data);
   free(ptr);
}
void Delete_any(node* header,int key)
{
   node* ptr,*temp;
   ptr=header->link;
   while(ptr->data!=key && ptr->link!=NULL)
   {
      temp=ptr;
      ptr=ptr->link;
   }
   temp->link=ptr->link;
   printf("Node deleted, %d\n",ptr->data);
   free(ptr);
}

void main()
{
   int choice;
   node* header, *newnode,*ptr;
   header=(node*)malloc(sizeof(node));
   printf("1.Display\n2.Insert Front\n3.Insert End\n4.Insert after\n5.Delete front\n6.Delete end\n7.Delete any\n8.Exit\n");
   do
   {
      printf("\nEnter choice: ");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
		display(header);
		break;
         case 2:
		int data1;
		printf("Enter data to insert: ");
                scanf("%d",&data1);
                Insert_front(header,data1);
		break;

	 case 3:
		int data2;
                printf("Enter data to insert: ");
                scanf("%d",&data2);
		Insert_end(header,data2);
		break;

	 case 4:
		int key1;
		int data3;
		printf("Enter data of node after which new node has to be inserted: ");
		scanf("%d",&key1);
		printf("Enter data to be inserted: ");
		scanf("%d",&data3);
		Insert_any(header,data3,key1);
		break;

	 case 5:
		Delete_front(header);
		break;

	 case 6:
		Delete_end(header);
		break;

	 case 7:
		int key2;
		printf("Enter the data to be deleted: ");
		scanf("%d",&key2);
		Delete_any(header,key2);
		break;

	 case 8:
		break;

      }
   }
   while(choice!=8);
}
















