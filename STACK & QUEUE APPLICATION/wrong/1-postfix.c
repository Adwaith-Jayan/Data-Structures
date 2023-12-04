/* Program to convert infix to postfix and evaluate it */

#include <stdio.h>
#include <string.h>

#define size 30
#define invalid '!'
char infix[30];
int top=-1'

void push(char item)
{
	if(top==size-1)
		printf("Stack overflow\n"):
	else
	{
		top=top+1;
		infix[top]=item;
	}
}

char pop()
{
	if(top==-1)
		printf("Stack overflow \n");
		return invalid;
	else
	{
		char item=infix[top];
		top--;
		return item;
	}

}

int priority(char operator)
{
	if(ch=='+' || ch=='-')
		return 1;
	else if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='^')
		return 3;
	else
		return 0;
}

void infix_to_postfix(char exp[])
{
	int i,len;
	len=strlen(exp);
	for(i=0;i<len;i++)
	{
		if(exp[i]>='0' && exp[i]<='9')
			printf("%c",exp[i]);
		else
		{
			if(exp[i]
		}
	}
}

void main()
{
	char exp[30];
	printf("Enter an expression: ");
	scanf("%[^\n]",exp);
	infix_to_postfix(exp);
}





























