#include <stdio.h>

int binary_search(int[],int);
void output(int);
int main(void)
{
	int target,dis;
	int arr[]={1,2,3,4,5,6,7,8,9};
	
	printf("Enter A number you want to search: ");
	scanf("%d",&target);
	
	dis=binary_search(arr,target);
	
	if(dis==-1)
	{
		printf("Not found");
	}
	else
	{
		printf("found at index %d",dis);
	}
}
int binary_search(int arr[],int target)
{
	int left=0, right=10-1;
	int mid;
	
	while(left<=right)
	{
		mid=(left+right)/2;
		if(arr[mid]==target)
		    return mid;
		else if(target < arr[mid])
		    right=mid-1;
		else
		    left=mid+1;
	}
	return -1;
}

