/* Program to demonstarte linear search */
#include <stdio.h>
void main()
{
	int a[30],n,i,key;
    	int found;
	char opt='y';
	printf("How many number? ");
	scanf("%d",&n);
	printf("Enter %d numbers\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	while(opt=='y'||opt=='Y')
	{
		found=0;
		printf("Enter the number to be searched: ");
		scanf("%d",&key);
		for(i=0;i<n;i++)
		{
			if(a[i]==key)
			{
				found=1;
				break;
			}
		}
		if(found)
		{
			printf("Found at Index:%d\n",i);
		}
		else
		{
			printf("Number not found\n");
		}
		printf("Do you want to countinue(y/n)? ");
		scanf(" %c",&opt);
	}

}
