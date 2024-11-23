#include <stdio.h>
#include <conio.h>
#include <unistd.h>

#define size 50

void size_array(int*);
int Input_array(int[],int);
void bubble_sort(int[],int);
void display_sort(int[],int);
void Value_search(int*);
int Binary_search(int[],int,int);
void display(int);

int main(void)
{
	int arr[size],elem,val,result;
	
	size_array(&elem);
	Input_array(arr,elem);
	bubble_sort(arr,elem);
	printf("\nSorted Array\n");
	display_sort(arr,elem);
	Value_search(&val);
	result=Binary_search(arr,elem,val);
	display(result);	
}
void size_array(int* el)
{
	printf("Enter size of array: ");
	scanf("%d",el);
}
int Input_array(int arr[],int el)
{
	if(el<1 || el >50)
	{
		printf("Impossible!\n");
		printf("Enter Number Below 50 Only\n");
		printf("Enter any key to continue ");
		getch();
		return main();
	}
	else
	{
		for(int i=0; i<el; i++)
		{
			printf("Enter Element %d: ",i+1);
			scanf("%d",&arr[i]);
		}
	}
}
void bubble_sort(int arr[],int el)
{
	int i,j,temp;
	for(i=0; i<el; i++)
	 for(j=0; j<el-1; j++)
	  if(arr[j]>arr[j+1])
	  {
	  	temp=arr[j];
	  	arr[j]=arr[j+1];
	  	arr[j+1]=temp;
	  }
}
void Value_search(int* value)
{
	printf("\n\nEnter Number to search:  ");
	scanf("%d",value);
}
int Binary_search(int arr[],int el,int val)
{
	int left=0, right=el-1;
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(arr[mid]==val)
		return mid;
		else if(val<arr[mid])
		right=mid-1;
		else
		left=mid+1;
	}
	return -1;
}
void display(int res)
{
	if(res==-1)
	{
		printf("Not Found");
	}
	else
	{
		printf("Found at index %d",res+1);
	}
}
void display_sort(int arr[],int el)
{
	for(int i=0; i<el; i++)
	{
		printf("%d ",arr[i]);
	}
}
