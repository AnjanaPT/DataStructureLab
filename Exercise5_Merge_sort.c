#include<stdio.h>
int main()
{
	int i,j,a1[10],n1,a2[10],n2,a3[100],n,t,min,k=0;
	printf("\nEnter the size of first array : ");
	scanf("%d",&n1);
	printf("\nEnter the array elements\n");
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a1[i]);
	}
	printf("\nEnter the size of second array : ");
	scanf("%d",&n2);
	printf("\nEnter the array elements\n");
	for(i=0;i<n2;i++)
	{
		scanf("%d",&a2[i]);
	}
	n=n1+n2;
	for(i=0;i<n1;i++)
	{
		a3[k++]=a1[i];
	}
	for(i=0;i<n2;i++)
	{
		a3[k++]=a2[i];
	}
	printf("\nMERGED ARRAY ELEMENTS \n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a3[i]);
	}
	for(i=0;i<n;i++)
	{
		min=a3[i];
		for(j=i+1;j<n;j++)
		{
			if(min>a3[j])
			{
				t=min;
				min=a3[j];
				a3[j]=t;
			}
		}
		a3[i]=min;
	}
	printf("\n\nMERGED ARRAY ELEMENTS AFTER SORTING\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a3[i]);
	}
	return 0;
}
