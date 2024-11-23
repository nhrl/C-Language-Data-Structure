#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define F while (getchar() != '\n')
#define N 15
#define T 10

typedef struct 
{
	char name[N];
	int duration;
}PROCESS;

typedef struct node *ptr;
struct node
{
	PROCESS proc;
	ptr next;
}NODE;

void createCque(ptr *,ptr *);
void enque(ptr *, ptr *, PROCESS);
PROCESS deque(ptr *, ptr *);
bool isEmpty(ptr);
void timeSimulation(int);
PROCESS input(void);
void input_size(int *);

int main (void)
{
	int size;
	input_size(&size);
	timeSimulation(size);
}

void input_size(int *size)
{
	printf("\n\n\tEnter Number of Size you want to insert: ");
	scanf("%d",size);
	return;
}

PROCESS input(void)
{
	PROCESS process;
	F;
	printf("\n\n\tEnter Name: ");
	gets(process.name);
	printf("\n\n\tEnter Duration: ");
	scanf("%d",&process.duration);
	return process;
}

void createCque(ptr *front,ptr *rear)
{
	*front=NULL;
	*rear=NULL;
	return;
}

void enque(ptr *front, ptr *rear, PROCESS process)
{
	ptr temp=malloc(sizeof(NODE));
	temp->proc=process;
	temp->next=NULL;
	if(*rear==NULL)
	  {
	    *rear=temp;
	  	*front=temp;
	  }
	  else
	  {
	  	(*rear)->next=temp;
	  	*rear=temp;
	  }
}

PROCESS deque(ptr *front, ptr *rear)
{
	PROCESS process=(*front)->proc;
	ptr pt=*front;
	*front=(*front)->next;
	if(*front==NULL)
	    *rear=*front;
	free(pt);
	return process;
}

bool isEmpty(ptr rear)
{
	bool empty=false;
	if(rear==NULL)
	   empty=true;
	return empty;
}

void timeSimulation(int size)
{
	int i;
	PROCESS process;
	bool empty;
	ptr front, rear;
	
	createCque(&front,&rear);
	
	for(i=1; i <= size; i++)
	{
		process=input();
		enque(&front, &rear, process);
	}
	empty=isEmpty(rear);
	while(!empty)
	{
		process = deque(&front,&rear);
		printf("\n\n\t Processing %s: ",process.name);
		printf("\n\n\t Duration %d: ",process.duration );
		
		if(process.duration > T)
		{
			process.duration = process.duration - T;
			sleep(T);
			enque(&front, &rear, process);
			printf("\n\n\t Remaining Time %d: ",process.duration);
		}
		else
		{
			sleep(process.duration);
			printf("\n\n\t Processing %s complete...",process.name);
		}
		empty=isEmpty(rear);
	}//end of while loop
	printf("\n\n\t All are Executed!");
	sleep(3);
	return;
}

