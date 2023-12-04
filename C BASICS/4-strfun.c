/* Program to implement built in string function */

#include <stdio.h>
int StringLength(char *s)
{
	int len=0;
	while(*s!='\0')
	{
		len++;
		s++;
	}
	return len;
}
void StringCopy(char *s1, char *s2)
{
	while(*s2!='\0')
	{
		*s1=*s2;
		s1++;
		s2++;
	}
}
int StringCompare(char *s1,char *s2)
{
	while(*s1!='\0' && *s2!='\0')
	{
		if(*s1<*s2)
			return -1;
		else if(*s1>*s2)
			return 1;
		s1++,s2++;
	}
	if(*s1=='\0' && *s2=='\0')
		return 0;
	else if(*s1=='\0')
		return -1;
	else
		return 1;
}

void StringConcat(char *s1, char  *s2)
{
	int i;
	//for(i=0;s1[i]!='\0';i++);
	//printf("%d\n",i);
	while(*s1!='\0')
		s1++;
	//s1=s1+i
	while(*s2!='\0')
	{
		*s1=*s2;
		s1++;
		s2++;
	}
}
void main()
{
	//Finding length
	char s[30];
	printf("Enter a string: ");
	scanf("%[^\n]",s);
	printf("Length =%d\n\n",StringLength(s));

	//Copying a string S2 to S1
	char s1[30],s2[30];
	printf("Enter a string S2= ");
	scanf(" %[^\n]",s2);
	StringCopy(s1,s2);
	printf("S1=%s\n\n",s1);

	//String Comparison

	char str1[30],str2[30];
	printf("Enter string 1:");
	scanf(" %[^\n]",str1);
	printf("Enter string 2:");
	scanf(" %[^\n]",str2);
	int result=StringCompare(str1,str2);
	if(result<0)
		printf("str1 is less than str2\n");
	else if(result==0)
		printf("Str1 is equal to str2\n");
	else
		printf("Str 1 is greater than str2\n");

	//Concate two string
	char string1[30],string2[30];
	printf("Enter string1: ");
	scanf(" %[^\n]",string1);
	printf("Enter String2: ");
	scanf(" %[^\n]",string2);
	StringConcat(string1,string2);
	printf("%s\n",string1);










}


























