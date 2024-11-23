#include <stdio.h>
#include <conio.h>//for getch();
#include <unistd.h>

void Number_array(int*);
int input_elements(int*,int);
int output_array(int*,int);

int main(void)
{
	int arr[50],size,i;
	system("cls");
	
	Number_array(&size);
	input_elements(arr,size);
	output_array(arr,size);
}
void Number_array(int* size)
{
	printf("Enter Number of Elements: ");
	scanf("%d",size);
}
int input_elements(int arr[],int size)
{
	if(size <1 || size >50)
	{
		printf("Impossible!\n");
		printf("Enter Number Below 50 Only\n");
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
int output_array(int arr[],int size)
{
	printf("\nElements Of Array\n");
	for(int i=0; i<size; i++)
		{
			printf("%d ",arr[i]);
		}
		sleep(5);
		return main();
}
