#include <stdio.h>
#include <conio.h>
#include <unistd.h>

void array_size(int*);
int elements(int*,int);
void position(int*);
int delete_num(int*,int,int);
int print(int*,int);

int main (void)
{
	int arr[50],size,pos;
	system("cls");
	array_size(&size);
	elements(arr,size);
	position(&pos);
	delete_num(arr,size,pos);
	print(arr,size);
}
void array_size(int* size)
{
	printf("Enter Number of Element: ");
	scanf("%d",size);
}
int elements(int arr[],int size)
{
	if(size<1 || size >50)
	{
		printf("Impossible!\n");
		printf("Enter Number Below 50 Only\n");
		printf("Press any key to continue");
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
void position(int*pos)
{
	printf("\nEnter Position to delete: ");
	scanf("%d",pos);
}
int delete_num(int arr[],int size,int pos)
{
	if(pos>size)
	{
		printf("\nInvalid!");
		getch();
		return main();
	}
	else
	{
		for(int i=pos-1; i<size; i++)
		{
			arr[i]=arr[i+1];
		}
	}
}
int print(int arr[],int size)
{
	for(int i=0; i<size-1; i++)
	{
		printf("%d ",arr[i]);
	}
	sleep(5);
	return main();
}
