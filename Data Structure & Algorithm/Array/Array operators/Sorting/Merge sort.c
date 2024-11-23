#include <stdio.h>
#include <conio.h>
#include <unistd.h>

#define size 50
void Size_array(int*);
int Input_array(int[],int);
void display_array(int[],int);
void mergesort(int[],int,int);
void merge(int[],int,int,int);
void display_sorted(int[],int);

int main(void)
{
	int arr[size],elem;
	Size_array(&elem);
	Input_array(arr,elem);
	printf("\nUnsorted Array\n");
	display_array(arr,elem);
	mergesort(arr,0,elem-1);
	printf("\nSorted Array\n");
	display_sorted(arr,elem);
}
void Size_array(int* el)
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
void display_array(int arr[],int el)
{
	for(int i=0; i<el; i++)
	printf("%d ",arr[i]);
}
void mergesort(int arr[],int first,int last)
{
	int mid;
	if(first<last)
	{
		mid=(first+last)/2;
		mergesort(arr,first,mid);
		mergesort(arr,mid+1,last);
		merge(arr,first,mid,last);
	}
}
void merge(int arr[],int first,int mid,int last)
{
	int b[50],i,j,k;
	i=first;
	j=mid+1;
	k=first;
	
	while(i<=mid && j<=last)
	{
		if(arr[i]<=arr[j])
		  b[k++]=arr[i++];
		else
		  b[k++]=arr[j++];
	}
	if(i>mid)
	{
		while(j<=last)
		  b[k++]=arr[j++];
	}
	else
	{
		while(i<=mid)
		  b[k++]=arr[i++];
	}
	for(i=first; i<=last;i++)
	{
		arr[i]=b[i];
	}
}
void display_sorted(int arr[],int el)
{
	for(int i=0; i<el; i++)
	printf("%d ",arr[i]);
}
