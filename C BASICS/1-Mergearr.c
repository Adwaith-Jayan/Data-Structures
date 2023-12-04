/* Program to merge two sorted arrays in asceding order*/
#include <stdio.h>
void main()
{
	int a[30],b[30],merge[60],i,j,k,m,n;
	printf("Number of elements in first array:");
	scanf("%d",&m);
	printf("Enter %d numbers:",m);
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
	printf("Number of elements in second array? ");
	scanf("%d",&n);
	printf("Enter %d numbers:",n);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	i=0,j=0,k=0;
	printf("%p\n%p\n",a,&a[1]);
	while(i<m && j<n)
	{
		if(a[i]<b[j])
			merge[k++]=a[i++];
		else
			merge[k++]=b[j++];
	}
	while(i<m)
		merge[k++]=a[i++];
	while(j<n)
		merge[k++]=b[j++];
	for(i=0;i<k;i++)
		printf("%d  ",merge[i]);
	printf("\n\n");
}




