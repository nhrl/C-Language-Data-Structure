//array implementation
#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>

#define S 100

typedef struct node
{
	int data[S];
	int next;
}Stack;

void Input_num(int*);
Stack create_stack(void);
void push(Stack*, int);
int pop(Stack *);
bool isEmpty(int);
bool isFull(int);
int To_binary(int);
void print(int);
char repeat(void);
char repeat_condition(char);


int main(void)
{
	int num;
	char rep;
	system("cls");
	Input_num(&num);
	To_binary(num);
	rep=repeat();
	repeat_condition(rep);
	
}

void Input_num(int *num)
{
	printf("\n\n\tEnter Number: ");
	scanf("%d",num);
	return;
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

int To_binary(int num)
{
	int rem , data=num;
	bool check;
	Stack stk;
	
	stk=create_stack();
	while(data!=0)
	{
		check=isFull(stk.next);
		rem=data % 2;
		if(check)
		{
			printf("\n\n\tStack is Full! ");
			getch();
			exit(0);
		}
		else
		{
			push(&stk,rem);
			data=data / 2;
		}
	}
	check=isEmpty(stk.next);
	printf("\n\n\t %d =",num);
	while(!check)
	{
		rem=pop(&stk);
		print(rem);
		check=isEmpty(stk.next);
	}
}

void print(int num)
{
	printf("%d",num);
}

char repeat(void)
{
	char rep;
	getch();
	printf("\n\n\tRepeat Y/N? ");
	scanf(" %c",&rep);
	return rep;
}

char repeat_condition(char rep)
{
	if(rep=='Y' || rep== 'y')
	  return main();
}
