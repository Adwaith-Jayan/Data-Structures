#include <stdio.h>
#include <string.h>
#include <math.h>
#define size 30
char s[30];
int stack[30];
int top=-1;
char postfix[30];
int k=0;
void push(char ch)
{
   if(top==size-1)
   {
      printf("Stack overflow\n");
   }
   else
   {
      top=top+1;
      s[top]=ch;
   }
}
char pop()
{
   char item;
   if(top==-1)
   {
      return '\0';
   }
   else
   {
      item=s[top];
      top--;
      return item;
   }
}
void push2(int item)
{
    top++;
    stack[top]=item;
}
int pop2()
{
   int item=stack[top];
   top--;
   return item;
}
int icp(char ch)
{
   switch(ch)
   {
      case '+': return 1;
      case '-' : return 1;
      case '*' :return 3;
      case '/' : return 3;
      case '^' : return 6;
      case '(' : return 7;
   }
}
int isp(char ch)
{
   switch(ch)
   {
      case '+' :return 2;
      case '-': return 2;
      case '/':return 4;
      case '*': return 4;
      case '^' : return 5;
      case '(':return 0;
   }
}

void infix_to_postfix(char infix[])
{
   int i;
   for(i=0;i<strlen(infix);i++)
   {
      char ch=infix[i];
      if(ch>='0'&& ch<='9')
      {
         postfix[k++]=ch;
      }
      else if(ch==')')
      {
         char x=pop();
         while(x!='(')
         {
            postfix[k++]=x;
            x=pop();
         }
      }
      else
      {
         if(top!=-1)
         {
           char y=pop();
           while(isp(y)>=icp(ch))
           {
              postfix[k++]=y;
              y=pop();
           }
           push(y);
         }
         push(ch);
      }
   }
   while(top!=-1)
   {
      postfix[k++]=pop();
   }
   postfix[k]='\0';
}
void evaluate()
{
   int i;
   for(i=0;i<strlen(postfix);i++)
   {
      char ch=postfix[i];
      if(ch>='0' && ch<= '9')
      {
          push2(ch-'0');
      }
      else
      {
          switch(ch)
          {
             case '+': int operand2=pop2();
		     int operand1=pop2();
		     int result1=operand1+operand2;
                     push2(result1);break;

	     case '-':
    		     int op2 = pop2();
    	             int op1 = pop2();
    		     int result2 = op1 - op2;
    		     push2(result2);
    		     break;

   	     case '*':
                      int oper2=pop2();
		      int oper1=pop2();
		      int result3=oper1 * oper2;
		      push2(result3);
	              break;
	     case '/':
			int opera2=pop2();
			int opera1=pop2();
			int result4=opera1/opera2;
			push2(result4);
			break;
	     case '^':
			int operan2=pop2();
			int operan1=pop2();
			int result5=(int)pow(operan1,operan2);
			push2(result5);
			break;

          }
      }
   }
   printf("\n\n\tEvaluation\n");
   printf("Ans= %d\n",pop2());
}

void main()
{
   char infix[30];
   printf("Enter an infix expression: ");
   scanf("%s",infix);
   infix_to_postfix(infix);
   printf("Postfix expression is: %s\n",postfix);
   top=-1;
   evaluate(); 
}











