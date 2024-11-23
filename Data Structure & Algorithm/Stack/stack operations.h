//Stack operations
#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define S 100
//Array Implementation
/*
typedef struct
{
	int data[S];
	int next;
}STACK;

STACK createstack(void)
{
	int i;
	STACK stk;
	for(i=0; i<S; i++)
	{
		stk.data[i]=0;
		stk.next=-1;
		return stk;
	}
}

void Createstack(STACK *stk)
{
	int i;
	for(i=0; i<S; i++)
	{
		stk->data[i]=0;
		stk->next=0;
		return;
	}
}

void push(STACK *stk, int data)
{
	stk->next=stk->next+1;
	stk->data[stk->next]=data;
	return;
}

int pop(STACK *stk)
{
	int ret=stk->data[stk->next];
	stk->next=stk->next-1;
	return ret;
}

bool isFull(int next)
{
	if(next==S-1)
	   return true;
	else
	   return false;
}

bool isEmpty(int next)
{
	if(next==-1)
	   return true;
	else
	   return false;
}
*/

//linked list Implementation
typedef struct node *nd;
struct node
{
	int data;
	nd next;
}STACK;

nd createStack(void)
{
	nd temp=NULL;
	return temp;
}

void push(nd *tos, int data)
{
	nd temp=malloc(sizeof(STACK));
	temp->data=data;
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
