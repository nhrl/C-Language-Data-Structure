#include <stdio.h>
#include <unistd.h>

#define A 5
#define B 5
int row(int [A][B]);
int col(int [A][B]);

int main(void)
{

	int arr[A][B];
	
	for(int c=0; c<A; c++)
	{
		printf("Row %d:\n",c+1);
		for(int m=0; m<B; m++)
		{
			printf("Column %d:",m+1);
			scanf("%d",&arr[c][m]);
		}
	}
	row(arr);
	col(arr);
	
}
int row(int arr[A][B])
{
	int i,j,sum=0;
	printf("\nRow total\n");
	for(i=0;i<A;i++)
	{
		for(j=0;j<B;j++)
		{
			sum+=arr[i][j];
		}
		printf(" %d ",sum);
		sum=0;
	}
}
int col(int arr[A][B])
{
	int i,j,sum=0;
		printf("\nColumn total\n");
	for(i=0;i<A;i++)
	{
		for(j=0;j<B;j++)
		{
			sum+=arr[j][i];
		}
		printf(" %d ",sum);
		sum=0;
	}
}


