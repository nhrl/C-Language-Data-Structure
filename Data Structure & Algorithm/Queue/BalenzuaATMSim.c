//Nhoriel Y. Balenzua
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 5
#define S 8

typedef struct
{
	char ATM_client[S];
}ACC;

typedef struct 
{
	ACC client[MAX];
	int front;
	int rear;
}QUE;

void create_que(QUE *);
void enque(QUE *,ACC);
ACC deque(QUE *);
bool isFull(int,int);
bool isEmpty(int,int);

ACC input_client(void);
void ATM_Simulation();
int Random_num_serve(void);
int Random_num_decide(void);

int main(void)
{
	ATM_Simulation();
}

void create_que(QUE *que)
{
	que->front=0;
	que->rear=0;
	return;
}

void enque(QUE *que,ACC client)
{
	que->client[que->rear]=client;
	que->rear=(que->rear+1) % MAX;
	return;
}

ACC deque(QUE *que)
{
	ACC ret_client=que->client[que->front];
	que->front=(que->front+1) % MAX;
	return ret_client;
}

bool isFull(int front,int rear)
{
	bool full=false;
	if(front==(rear+1)%MAX)
	     full=true;
	return full;
}

bool isEmpty(int front,int rear)
{
	bool empty=false;
	if(rear==front)
	     empty=true;
	return empty;
}

ACC input_client(void)
{
	ACC acc;
	printf("\n\n\tEnter Client Account Number: ");
	gets(acc.ATM_client);
	return acc;
}

void ATM_Simulation()
{
	int i, randnum, randnum2;
	bool empty,full;
	ACC clt;
	QUE que;
	
	create_que(&que);
	for(i=0; i<MAX-2; i++)
	{
		clt=input_client();
		enque(&que,clt);
	}
	
	empty=isEmpty(que.front,que.rear);
	while(!empty)
	{
		clt=deque(&que);
		randnum=Random_num_serve();
		printf("\n\tProcessing ATM %s",clt.ATM_client);
		printf("\n\tATM Serving Time %d Seconds...",randnum);
		sleep(randnum);
		printf("\n\tATM %s Complete...\n",clt.ATM_client);
		
		randnum2=Random_num_decide();
		if(randnum2 >= 5 && randnum2 <=10 )
		{
			full=isFull(que.front,que.rear);
			if(full)
			{
				printf("\n\n\tError!!! Queue is Full...");
				getch();
				exit(0);
			}
			else
			{
				clt=input_client();
				enque(&que, clt);
			}
		}
		empty=isEmpty(que.front,que.rear);
	}//end while loop
	printf("\n\n\tAll ATM Are Now Completed...");
	getch();
}

int Random_num_serve(void)
{
	int number;
	int low=5, high=10;
	
	srand(time(NULL));
	number=(rand() % (high-low+1)) + low;
	return number;
}

int Random_num_decide(void)
{
	int number;
	int low=1, high=10;
	
	srand(time(NULL));
	number=(rand() % (high-low+1)) + low;
	return number;
}
