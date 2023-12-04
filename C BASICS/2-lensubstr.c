/* Prgogram to find the length of longest substring and display it */
#include <stdio.h>
#include <string.h>

int substrlen(char *s)
{
	int len=strlen(s);
	int seen[256];
	int start=0;
	int end=0;
	int length=0;
	for(int i=0;i<256;i++)
	{
		seen[i]=-1;
	}
	for(end=0;end<len;end++)
	{
		if(seen[s[end]]>=start)
		{
			start=seen[s[end]]+1;
		}
		seen[s[end]]=end;
		if(end-start+1>length)
		{
			length=end-start+1;
		}
	}
	return length;
}
void main()
{
	char str[30];
	int length,i;
	printf("Enter a string:");
	scanf("%[^\n]",str);
	length=substrlen(str);
	printf("Longest Substring is: ");
	for(i=0;i<length;i++)
		printf("%c" ,str[i]);
	printf("\nLength=%d\n",length);
}
