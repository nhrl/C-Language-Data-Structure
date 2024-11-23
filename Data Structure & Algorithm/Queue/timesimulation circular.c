#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#define F while (getchar() != '\n')
#define N 10
#define Q 4
#define T 10

typedef struct
{
	char name[N];
	int duration;
}PROCESS;

typedef struct
{
	PROCESS porc[Q];
	int q_front;
	int q_rear;
}QUEUE;

void createCque(QUEUE *);
void enque(QUEUE *,PROCESS);
PROCESS deque(QUEUE *);
bool isFull(int,int);
bool isEmpty(int,int);
void timeSimulation();
PROCESS input(void);


int main(void)
{
	timeSimulation();
}

void createCque(QUEUE *que)
{
	que->q_front=0;
	que->q_rear=0;
	return;
}

void enque(QUEUE *que,PROCESS process)
{
	que->porc[que->q_rear]=process;
	que->q_rear=(que->q_rear+1) % Q;
	return;
}

PROCESS deque(QUEUE *que)
{
	PROCESS process=que->porc[que->q_front];
	que->q_front=(que->q_front+1) % Q;
	return process;
}

bool isFull(int front,int rear)
{
	bool full=false;
	if(front==(rear+1)%Q)
	     full=true;
	return full;
}

bool isEmpty(int front,int rear)
{
	bool empty=false;
	if(front==rear)
	     empty=true;
	return empty;
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
void timeSimulation()
{
	PROCESS process;
	bool empty,full;
	QUEUE que;
	
	createCque(&que);
	
	full=isFull(que.q_front,que.q_rear);
	while(!full)
	{
		process=input();
		enque(&que,process);
		full=isFull(que.q_front,que.q_rear);
	}
	
	empty=isEmpty(que.q_front,que.q_rear);
	while(!empty)
	{
		process=deque(&que);
		printf("\n\n\tProcessing Name %s....",process.name);
		printf("\n\n\tDuration %d...",process.duration);
		if(process.duration>T)
		{
			process.duration=process.duration-T;
			sleep(T);
			full=isFull(que.q_front,que.q_rear);
			if(full)
			{
				printf("\n\n\tError!!! QUEUE is FULL...");
				sleep(3);
				exit(0);
			}
			else
			{
				enque(&que,process);
				printf("\n\n\tTime Remaining %d....",process.duration);
			}
		}
		else
		{
			sleep(process.duration);
			printf("\n\n\tProcess %s complete...",process.name);
		}
		empty=isEmpty(que.q_front,que.q_rear);
	}//end of while loop
	printf("\n\n\tAll are executed");
	sleep(5);
}
