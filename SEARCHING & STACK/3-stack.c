/* Implement stack using array */
#include <stdio.h>
#define INVALID -99999
#define size 5
int s[10],top=-1;
void push(int item)
{
	if(top==size-1)
	{
		printf("Over flow\n");
	}
	else
	{
		top=top+1;
		s[top]=item;
	}
}
int pop()
{
	if(top==-1)
	{
		printf("Stack overflow\n");
		return INVALID;
	}
	else
	{
		int item=s[top];
		top=top-1;
		return item;
	}
}
void display()
{
	int i;
	printf("Stack is\n");
	for(i=0;i<size;i++)
		printf("%d  ",s[i]);
}

void main()
{
	char opt='y';
	int choice;
	int item;
	while(opt=='y'||opt=='Y')
	{
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Display\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Enter number to push: ");
			scanf("%d",&item);
			push(item);
		}
		else if(choice==2)
		{
			int element;
			element=pop();
			if(element!=INVALID)
				printf("Elemented deleted, %d\n",element);
		}
		else
			display();
		printf("\nDo you want to countinue? ");
		scanf(" %c",&opt);
	}
}


























