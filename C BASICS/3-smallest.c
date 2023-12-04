/* To find the smallest number using pointers in an array */

#include <stdio.h>
void main()
{
	int a[30],i,n;
	int *ptr;
	printf("Number of elements ?");
	scanf("%d",&n);
	printf("Enter %d numbers : ",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	ptr=a;
	int smallest=*ptr;
	for(i=0;i<n;i++)
	{
		if(smallest>*ptr)
		{
			smallest=*ptr;
			ptr++;
		}
		else
			ptr++;
	}
	printf("%d",smallest);
	printf("\n\n");
}
