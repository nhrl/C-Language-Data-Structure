#include <stdio.h>
#define N 8

int main (void)
{
	int arr[N]={34,56,32,67,89,90,32,21};
	printf("Proper Order\n");
	for(int i=0;i<N;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nReverse Order\n");
	{
		for(int i=7;i>=0;i--)
		{
			printf("%d ",arr[i]);
		}
	}
}
