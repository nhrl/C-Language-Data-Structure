#include <stdio.h>
#include <conio.h>
#include <unistd.h>

void EnterElements(int*);
int Enter_Array(int*,int);
void EnterValue(int*);
int Found(int*,int,int);

int main(void)
{
	int arr[50],elem,val;
	
	system("cls");
	EnterElements(&elem);
	Enter_Array(arr,elem);
	EnterValue(&val);
	Found(arr,val,elem);
}
void EnterElements(int *elements)
{
	printf("How Many Elements? ");
	scanf("%d",elements);
}
int Enter_Array(int arr[],int element)
{
	if(element<1 || element>50)
	{
		printf("Impossible!\n");
		printf("Enter Below 50 Only\n");
		printf("Press any key to continue");
		getch();
		return main();
	}
	else
	{
		for(int i=0; i<element; i++)
		{
			printf("Element Number %d: ",i+1);
			scanf("%d",&arr[i]);
		}
	}
}
void EnterValue(int*value)
{
	printf("\nEnter A Value to Search: ");
	scanf("%d",value);
}
int Found(int arr[],int value,int element)
{
	//searching
	for(int i=0; i<element;i++)
	{
		if(arr[i]==value)
		{
			printf("Found: %d",arr[i]);
			getch();
			return main();
		}
		else
		{
			printf("Value %d Not Found",value);
			getch();
			return main();
		}
	}
}
