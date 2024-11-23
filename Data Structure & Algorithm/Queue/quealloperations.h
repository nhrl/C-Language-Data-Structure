//Queue operations
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define S 10

/*
typedef struct
{
	int data[S];
	int front;
	int rear;
}QUE;

//linear queue/ Array implementation
QUE createLQue(void)
{
	int j;
	QUE que;
	for(j=0; j<S; j++)
	{
		que.data[j]=0;
		que.front=0;
		que.rear=-1;
		return que;
	}
}
void enque(QUE *que,int data)
{
	que->rear=que->rear+1;
	que->data[que->rear]=data;
	return;
}

bool isempty(int rear)
{
   if(rear==-1)
      return true;
   else
      return false;
}

bool isFull(int rear)
{
    if(rear==MAXSize-1)
       return true;
    else
       return false;
}

int deque(QUE *que)
{
	int ret=que->data[que->front];
	que->front+=1;
	return ret;
}

//circular QUEUE/ Array Implementation
QUE createCque(void)
{
	int j;
	QUE que;
	for(j=0; j<S; j++)
	{
		que.data[j]=0;
		que.front=0;
		que.rear=0;
		return que;
	}
}
void enque(QUE *que, int data)
{
	que->data[que->rear]=data;
	que.rear=(que->rear+1)%S;
	return;
}

int deque(QUE *que)
{
	int ret=que->data[que->front];
	que->front++;
	return ret;
}

bool isfull(int front,int rear)
{
	bool full=false;
	if(front=(rear+1)%S)
	     full=true;
	return full;
}

bool isEmpty(int front, int rear)
{
	bool empty=false;
	if(rear==front)
	     empty=true;
	return empty;
}
*/

//linear Queue/ linked list implementation
/*
typedef struct node *nd;
struct node
{
	int data;
	nd next;
}QUE;

nd createque(void)
{
	nd *front=NULL;
	nd *rear=NULL;
	return *front,*rear;
}

void enque(nd *front, nd *rear, int data) //version 1
{
	nd temp=malloc(sizeof(QUE));
	temp->data=data;
	temp->next=NULL;
	
	if(*rear!=NULL)
	{
		(*rear)->next=data;
		*rear=data;
	}
	else
	{
		*rear=data;
		*rear=*front;
	}
}

void enque(nd *front, nd* rear, nd data)//whe are passing the node// Version 2
{
    if(*rear==NULL)
    {
       *rear=data;
       *front=*rear;
    }
    else
        (*rear)->next=data;
        *rear=data;
}

int dequeue(nd *front, nd *rear)
{
	int ret=(*front)->data;
	nd temp=*front;
	*front=(*front)->next;
	if(*front==NULL)
	    *rear=NULL;
	free(temp);
	return ret;
}

bool isempty(nd rear)
{
	bool empty=false;
	if(rear==NULL)
	    empty=true;
	return empty;
}
*/
