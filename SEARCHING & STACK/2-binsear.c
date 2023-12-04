/* Binary search */
#include <stdio.h>
void main()
{
	int a[30],i,n,key,top,mid,bot,found;
	char opt='y';
	printf("How many number ?");
	scanf("%d",&n);
	printf("Enter %d numbers in ascending order:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	while(opt=='y'||opt=='Y')
	{
		top=0;
		bot=n-1;
		found=0;
		printf("Enter number to search: ");
		scanf("%d",&key);
		while(top<=bot)
		{
			mid=(top+bot)/2;
			if(key<a[mid])
			{
				bot=mid-1;
			}
			else if(key>a[mid])
				top=mid+1;
			else
			{
				found=1;
				break;
			}
		}
		if(found)
			printf("Found at Index %d\n",mid);
		else
			printf("Not found\n");
		
		printf("Do you want to countinue?(y/n) ");
		scanf(" %c",&opt);
	}
}

