/* Bubble sort using pointer */

#include <stdio.h>
void bubblesort(int * a, int size)
{
	int temp,i,j;
	for(i=0;i<size-1;i++)
		for(j=0;j<size-i-1;j++)
		{
			if(*(a+j)>*(a+j+1))
			{
				temp=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=temp;
			}
		}
}
void main()
{
	int a[30],i,n;
	printf("Enter number of elements ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Sorted is \n");
	bubblesort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
