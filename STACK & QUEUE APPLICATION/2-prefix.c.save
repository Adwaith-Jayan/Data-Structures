/* to convert infix to prefix */
#include <stdio.h>
#include <string.h>

#define size 30
char s[30];
int top=-1;

void push(char item)
{
	if(top==size-1)
		printf("Stack over\n");
	else
	{
		top++;
		s[top]=item;
	}
}

char pop()
{
	if(top==-1)
	{
		printf("Stack underdlow\n");
		return '\0';
	}
	else
	{
		char item=s[top];
		top--;
		return item;
	}
}

void reverse(char *s)
{
	char temp;
	int left=0;
	int right=strlen(s)-1;
	while(left<right)
	{
		temp=s[left];
		s[left]=s[right];
		s[right]=temp;
		left++;
		right--;
	}
}

int priority(char ch)
{
	if(ch==')')
		return 0;
	else if(ch=='+'|| ch=='-')
		return 1;
	else if(ch=='*' || ch=='/')
		return 2;
}

void infix_to_postfix(char infix[])
{
	char prefix[30];
	int i,k=0;
	reverse(infix);
	for(i=0;i<strlen(infix);i++)
	{
		if(infix[i]>='0' && infix[i]<='9')
		{
			prefix[k++]=infix[i];
		}
		else
		{
			
		}
	}
}






















