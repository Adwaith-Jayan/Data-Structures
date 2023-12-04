//* PALINDROME USING STACK */
#include <stdio.h>
#include <string.h>
#define size 10
#define invalid '!'
char s[10],top=1;
void push(char item)
{
	if(top==size-1)
		printf("STAck overflow");
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
		printf("STACk Overflow");
		return invalid;
	}
	else
	{
		char item;
		item=s[top];
		top=top-1;
		return item;
	}
}
void main()
{
	char str[30];
	int len,i;
	int palindrome=1;
	printf("Enter a string: ");
	scanf("%[^\n]",str);
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		push(str[i]);
	}
	for(i=0;i<len;i++)
	{
		if(str[i]!=pop())
		{
			palindrome=0;
			break;
		}
	}
	if(palindrome)
		printf("It is palindrome");
	else
		printf("IT is not");
}







