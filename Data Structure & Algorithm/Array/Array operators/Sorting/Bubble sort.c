#include <stdio.h>
#include <conio.h>
#include <unistd.h>


#define size 50

void input(int*);
int elements_array(int[],int);
void display(int[],int);
void BubbleSort(int[],int);
void indisplay(int arr[],int element); 

int main(void)
{
	int arr[size],elem;
	system("cls");
	input(&elem);
	elements_array(arr,elem);
	printf("\nElements Of Array\n");
	display(arr,elem);
	BubbleSort(arr,elem);
	printf("\nSorted Array\n");
	indisplay(arr,elem);
}
void input(int*element)
{
	printf("Enter Number Of Elements: ");
	scanf("%d",element);
}
int elements_array(int arr[],int element)
{
	if(element<1 || element >50)
	{
		printf("Impossible!\n");
		printf("Enter Number Below 50 Only\n");
		printf("Enter any key to continue ");
		getch();
		return main();
	}
	else
	{
		for(int i=0; i<element; i++)
		{
			printf("Enter Element %d: ",i+1);
			scanf("%d",&arr[i]);
		}
	}
}
void display(int arr[],int element)
{
	for(int i=0; i<element; i++)
	{
		printf("%d ",arr[i]);
	}
}
void BubbleSort(int arr[],int element)
{
	int i,j,temp;
	for(i=1; i<element; i++)
	  for(j=0; j<element-1; j++)
	  {
	  	if(arr[j]> arr[j+1])
	  	{
	  		temp=arr[j];
	  		arr[j]=arr[j+1];
	  		arr[j+1]=temp;
		  }
	  }
}
void indisplay(int arr[],int element) 
{
	for(int i=0; i<element; i++)
	    printf("%d ",arr[i]);
}
