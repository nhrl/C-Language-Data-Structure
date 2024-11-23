//This program will make the inputed array reverse
//array implementation
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

#define S 100

typedef struct node
{
	int data[S];
	int next;
}Stack;

Stack create_stack(void);
void push(Stack *, int);
int pop(Stack *);
bool isEmpty(int);
bool isFull(int);
void Elements_array(int*);
void input_array(int [],int);
void reverse(int [],int);
void display(int);

int main(void)
{
	int size, arr[S];
	Elements_array(&size);
	input_array(arr,size);
	reverse(arr,size);
	getch();
}


Stack create_stack(void)
{
	int i;
	Stack stk;
	for(i=0; i<S-1; i++)
	{
		stk.data[i]=0;
		stk.next=-1;
		return stk;
	}
	
}

void push(Stack *tos, int num)
{
	tos->next=tos->next+1;
	tos->data[tos->next]=num;
	return;
}

int pop(Stack *tos)
{
	int ret=tos->data[tos->next];
	tos->next=tos->next-1;
	return ret;
}

bool isEmpty(int next)
{
	if(next==-1)
	   return true;
	else
	   return false;
}

bool isFull(int next)
{
	if(next==S-1)
	   return true;
	else
	   return false;
}

void Elements_array(int *size)
{
	printf("Size of array: ");
	scanf("%d",size);
	return;
}

void input_array(int arr[],int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("\n\n\tElements %d: ",i+1);
		scanf("%d",&arr[i]);
	}
}

void reverse(int arr[],int size)
{
	int i,rem;
	Stack tos;
	bool check;
	
	tos=create_stack();
	
	for(i=0; i<size; i++)
	{
		rem=arr[i];
		push(&tos,rem);
	}
	
	check=isEmpty(tos.next);
	printf("\n\n\tReverse: ");
	while(!check)
	{
		rem=pop(&tos);
		display(rem);
		check=isEmpty(tos.next);
	}
	
}

void display(int num)
{
	printf("%d ",num);
}
