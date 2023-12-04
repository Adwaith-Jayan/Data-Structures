#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
   char data;
   struct node* llink;
   struct node* rlink;
}node;
void insert(node *header,char ch)
{
    node* temp, *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=ch;
    if(header->rlink==NULL)
    {
       header->rlink=newnode;
       newnode->llink=header;
       newnode->rlink=NULL;
       return;
    }
    temp=header->rlink;
    while(temp->rlink!=NULL)
    {
       temp=temp->rlink;
    }
    temp->rlink=newnode;
    newnode->llink=temp;
    newnode->rlink=NULL;
    return;
}
int palindrome(node * header)
{
   node *ptr1,*ptr2;
   ptr1=header->rlink;
   ptr2=header->rlink;
   while(ptr2->rlink!=NULL)
   {
      ptr2=ptr2->rlink;
   }
   while(ptr1!=ptr2 && ptr2->rlink!=ptr1)
   {
      if(ptr1->data!=ptr2->data)
         return 0;
      ptr1=ptr1->rlink;
      ptr2=ptr2->llink;
   }
   return 1;
}

void main()
{
    char str[30];
    int i;
    node* header;
    header=(node*)malloc(sizeof(node));
    header->rlink=NULL;
    header->llink=NULL;
    printf("Enter a string : ");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++)
    {
       insert(header,str[i]);
    }
    if(palindrome(header))
    {
       printf("It is palindrome\n");
    }
    else
       printf("It is not\n");
}





