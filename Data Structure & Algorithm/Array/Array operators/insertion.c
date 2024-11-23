#include <stdio.h>
#include <conio.h>
#include <unistd.h>

void EnterSize(int*);
int Enter_elements(int*,int);
void EnterValue(int*);
int EnterPosition(int*,int);
void Add_number(int*,int,int,int);
int print(int*,int);

int main(void)
{
	int arr[50],size,value,pos;
	system("cls");
	EnterSize(&size);
	Enter_elements(arr,size);
	EnterValue(&value);
	EnterPosition(&pos,size);
	Add_number(arr,size,value,pos);
	print(arr,size);
}
void EnterSize(int* size)
{
	printf("Enter How Many Elements: ");
	scanf("%d",size);
}
int Enter_elements(int arr[],int size)
{
	if(size<1 || size>50)
	{
		printf("Impossible!\n");
		printf("Enter Below 50 Only\n");
		printf("Enter any Key to Continue\n");
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
void EnterValue(int* val)
{
	printf("\nEnter Value to add: ");
	scanf("%d",val);
}
int EnterPosition(int* position,int size)
{
	printf("Enter Position: ");
		scanf("%d",position);
		
	if(*position < 1 || *position >size)
	{
		printf("Not Valid!\n");
		getch();
		return main();
	}
}
void Add_number(int arr[],int size, int value,int position )
{
	int i;
	//insertion
	for(i=size-1; i>=position-1; i--)
	{
		//swap
		arr[i+1]=arr[i];
	}
	//add the value
	arr[position-1]=value;
	//increment size of array
	size++;
}
int print(int arr[],int size)
{
	for(int i=0; i<size+1; i++)
	{
		printf("%d ",arr[i]);
	}
	sleep(5);
	return main();
}
