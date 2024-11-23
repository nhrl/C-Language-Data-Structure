//linked list implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <unistd.h>

typedef struct node *nd;
struct node
{
	int data;
	nd next;
}NODE;

void input_num(int*);
nd create_stack(void);
void push(nd *,int);
int pop(nd *);
bool isEmpty(nd);
void To_binary(int);
void print(int);
void repeat(char *);
int check_rep(char);

int main(void)
{
	int num;
	char rep;
	system("cls");
	input_num(&num);
	To_binary(num);
	repeat(&rep);
	check_rep(rep);
}


void input_num(int *num)
{
	printf("\n\n\tEnter A Number: ");
	scanf("%d",num);
	return;
}

nd create_stack(void)
{
	nd temp=NULL;
	return temp;
}

void push(nd *tos,int num)
{
	nd temp=malloc(sizeof(NODE));
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

void To_binary(int num)
{
	int rem, data=num;
	bool check;
	nd tos;
	
	tos=create_stack();
	while(data!=0)
	{
		rem=data % 2;
		push(&tos,rem);
		data= data / 2;
	}
   
    check=isEmpty(tos);
    printf("\n\n\t%d =",num);
    while(!check)
    {
    	rem=pop(&tos);
    	print(rem);
    	check=isEmpty(tos);
	}
}

void print(int num)
{
	printf("%d",num);
}

void repeat(char *rep)
{
	getch();
	printf("\n\n\tTry Again Y/N: ");
	scanf(" %c",rep);
	return;
}

int check_rep(char rep)
{
	if(rep=='Y' || rep=='y')
	   return main();
}
