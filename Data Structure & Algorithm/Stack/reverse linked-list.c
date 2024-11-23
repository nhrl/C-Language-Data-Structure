//reverse Number using stack
//linked-list implementation
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define S 100

typedef struct node *nd;
struct node
{
	int data;
	nd next;
}Stack;

nd create_stack(void);
void push(nd *, int);
int pop(nd *);
bool isEmpty(nd);
void Input_size(int*);
void input_data(int[],int);
void reverse(int[],int);
void print(int);
char repeat(void);
int repeat_prog(char);

int main(void)
{
	char rep;
	int size, arr[S];
	system("cls");
	Input_size(&size);
	input_data(arr,size);
	reverse(arr,size);
	rep=repeat();
	repeat_prog(rep);
}

nd create_stack(void)
{
	nd temp=NULL;
	return temp;
}

void push(nd *tos, int num)
{
	nd temp=malloc(sizeof(Stack));
	temp->data=num;
	temp->next=NULL;
	temp->next=*tos;
	*tos=temp;
	temp=NULL;
	return;
}

int pop(nd *tos)
{
	int ret=(*tos)->data;
	nd temp=*tos;
	*tos=(*tos)->next;
	free(temp);
	return ret;
}

bool isEmpty(nd next)
{
	if(next==NULL)
	   return true;
	else
	   return false;
}

void Input_size(int *size)
{
	printf("\n\n\tEnter Size: ");
	scanf("%d",size);
	return;
}

void input_data(int arr[],int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("\n\n\tElement %d: ",i+1);
		scanf("%d",&arr[i]);
	}
}

void reverse(int arr[],int size) 
{
	int ret,i;
	bool check;
	nd tos;
	
	tos=create_stack();
	for(i=0; i<size; i++)
	{
		ret=arr[i];
		push(&tos,ret);
	}
	
	check=isEmpty(tos);
	printf("\n\n\tReverse: ");
	while(!check)
	{
		ret=pop(&tos);
		print(ret);
		check=isEmpty(tos);
	}
}

void print(int num)
{
	printf("%d ",num);
}

char repeat(void)
{
	char rep;
	printf("\n\n\tRepeat Y/N: ");
	scanf(" %c",&rep);
	return rep;
}

int repeat_prog(char rep)
{
	if(rep=='y' || rep=='Y')
	  return main();
	else
	  printf("\n\n\tGood Bye!");
	  sleep(5);
}
