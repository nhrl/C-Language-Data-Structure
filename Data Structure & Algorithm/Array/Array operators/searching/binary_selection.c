#include <stdio.h>
#include <conio.h>
#include <unistd.h>

#define sizes 50

void Enter_elements(int*);
int Elements_Array(int[],int);
int sorting(int[],int);
void swap(int[],int,int);
void search(int*);
int binary_search(int[],int,int);
void print_result(int);

int main(void)
{
	int arr[sizes],Size_elem,pos,result;
	system("cls");
	Enter_elements(&Size_elem);
	Elements_Array(arr,Size_elem);
	sorting(arr,Size_elem);
	search(&pos);
	result=binary_search(arr,pos,Size_elem);
	print_result(result);
}
void Enter_elements(int* size)
{
	printf("Enter Number of Elements: ");
	scanf("%d",size);
}
int Elements_Array(int arr[],int size)
{
	if(size <1 || size >sizes)
	{
		printf("Impossible!\n");
		printf("Enter Number Below 50 only\n");
		printf("Press any key to continue ");
		getch();
		return main();
	}
	else
	{
		for(int i=0; i<size; i++)
		{
			printf("Element Number %d: ",i+1);
			scanf("%d",&arr[i]);
		}
	}
}
int sorting(int arr[],int size)
{
	int small;
	int i,j;
	
	for(i=0; i<size-i; i++)
	{
		small=i;
		for (j=i+1; j< size; j++)
		if(arr[j] < arr[small])
		small=j;
		
		swap(arr,i,small);
	}
}
void swap(int arr[],int sec,int small)
{
	int temp;
	temp=arr[sec];
	arr[sec]=arr[small];
	arr[small]=temp;
}
void search(int* position)
{
	printf("\nEnter Number to Search: ");
	scanf("%d", position);
}
int binary_search(int arr[],int pos,int size)
{
	int left=0, right=size-1;
	int mid;
	
	while(left<=right)
	{
		mid=(left+right)/2;
		if(arr[mid]==pos)
		return mid;
		else if(pos<arr[mid])
		right=mid-1;
		else
		left=mid+1;
	}
	return -1;
}
void print_result(int res)
{
	if(res==-1)
	{
		printf("Not Found");
	}
	else
	{
		printf("Found in Index %d",res);
	}
}
