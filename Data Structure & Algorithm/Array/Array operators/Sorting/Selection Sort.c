#include <stdio.h>
#include <conio.h>
#include <unistd.h>
#define size 50

void Enter_Array(int*);
int input_Array(int[],int);
void unsorted_out(int[],int);
int sort_Array(int[],int);
void  swap(int [], int ,int );
void sorted_out(int[],int);


int main(void)
{
	int arr[size],elements;
	system("cls");
	Enter_Array(&elements);
	input_Array(arr,elements);
	unsorted_out(arr,elements);
	sort_Array(arr,elements);
	sorted_out(arr,elements);
}
void Enter_Array(int* elem)
{
	printf("Enter Number of Elements: ");
	scanf("%d",elem);
}
int input_Array(int arr[],int elem)
{
	if(elem<1 || elem >size)
	{
		printf("Invalid!\n");
		printf("Enter Number Below 50 Only\n");
		printf("Press any keyword");
		getch();
		return main();
	}
	else
	{
		for(int i=0; i<elem; i++)
		{
			printf("Element Number %d: ",i+1);
			scanf("%d",&arr[i]);
		}
	}
}
void unsorted_out(int arr[],int elem)
{
	printf("\nUnsorted Array\n");
	for(int i=0; i<elem; i++)
	{
		printf("%d ",arr[i]);
	}
}
int sort_Array(int arr[],int elem)
{
	int small;
	int i,j;
	
	for(i=0; i<elem-i; i++)
	{
		small=i;
		for (j=i+1; j< elem; j++)
		if(arr[j] < arr[small])
		small=j;
		
		swap(arr,i,small);
	}
}
void  swap(int arr[], int sec,int small)
{
	int temp;
	temp=arr[sec];
	arr[sec]=arr[small];
	arr[small]=temp;
}
void sorted_out(int arr[],int elem)
{
	printf("\nSorted Array\n");
	for(int i=0; i<elem; i++)
	{
		printf("%d  ",arr[i]);
	}
}
