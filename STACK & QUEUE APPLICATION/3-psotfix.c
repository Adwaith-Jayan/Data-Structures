/* program to convert infix to postfix without using stack */
#include <stdio.h>
char op[30];
char postfix[30];
int k=0,j=0;
int isp(char ch)
{
   switch(ch)
   {
      case '+':
      case '-': return 2;
      case '*':
      case '/': return 4;
      case '^': return 5;
      case '(': return 0;
   }
}
int icp(char ch)
{
   switch(ch)
   {
      case '+':
      case '-': return 1;
      case '*':
      case '/': return 3;
      case '^': return 6;
      case '(': return 7;
   }
}

void topostfix(char infix[])
{
    for(int i=0;infix[i]!='\0';i++)
    {
       char ch=infix[i];
       if(ch >='0' && ch<='9' || ch=='(')
       {
           postfix[k++]=ch;
       }
       else if(ch==')')
       {
          while(op[j-1]!='(')
          {
	       postfix[k++]=op[--j];
          }
          j--;
       }
       else
       {
           while(j>0 && icp(ch)<=isp(op[j-1]))
           {
                postfix[k++]=op[--j];
           }
           op[j++]=ch;
       }
    }
    while(j>0)
    	postfix[k++]=op[--j];
    postfix[k]='\0';
}
void main()
{
    char infix[30];
    printf("Enter an infix expression:");
    scanf("%s",infix);
    topostfix(infix);
    printf("\nPostfix=%s\n",postfix);
}







