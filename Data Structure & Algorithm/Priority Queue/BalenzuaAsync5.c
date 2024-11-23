#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>

#define Q 6
#define D 7
#define DIV 101
#define MAX 20 //maximum process duration
#define MIN 3 // minimum process duration

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
typedef struct
{
	char procName[10];
	int duration;
}PRC;

typedef struct
{
	PRC pQueue[Q];
	int pSize;
}PQUEUE;

PQUEUE init_Priority_Queue();
void process_Control(PRC []);
bool empty_Priority_Queue(int);
bool full_Priority_Queue(int);
void insert_Priority_Queue(PRC , PQUEUE *);
PRC heap_Delete_Max(PQUEUE *);
void Max_heapify(int, PRC [], int);
PRC generate_Task();
int randomTime(int);
int randomQueue(void);
void build_max_heap(int,PQUEUE *);

int main(void)
{
	PRC init_Tasks[3] = {{"Process 1",8},{"Process 2",5},{"Process 3",9}}; // initial job processes
	srand(time(NULL));
	process_Control(init_Tasks);
	printf("\n\n\tSimulation terminates in 2 seconds...");
	sleep(2);
	return 0;
}

PQUEUE init_Priority_Queue(void)
{
	int j;
	PQUEUE p;
	for (j = 0; j < Q; j++)
	{
		p.pQueue[j].duration = 0;
		strcpy(p.pQueue[j].procName,"");
	}
	p.pSize = 0;
	return p;
}

void process_Control(PRC task_list[])
{
	int j, newTask, newDur;
	bool full, empty;
	PRC proc, newJob;
	PQUEUE H;
	
	H = init_Priority_Queue();
	for(j = 0; j < 3; j++)
	{
		full = full_Priority_Queue(H.pSize);
		if(!full)
		{
			insert_Priority_Queue(task_list[j],&H);
			build_max_heap(j,&H);
		}	
		else
		{
			printf("\n\n\tError: memory overflow...");
			sleep(4);
			break;
		}
	}// end of for loop
	
	empty = empty_Priority_Queue(H.pSize);
	while(!empty) // start of job scheduling simulation
	{
		system("cls");
		
		for(j = 1; j <= H.pSize; j++)
		{
			gotoxy(50,5+j);printf("Name: %s\tDuration: %d",H.pQueue[j].procName,H.pQueue[j].duration);
		}
		proc = heap_Delete_Max(&H);
		gotoxy(10,7);printf("Processing....\n");
		gotoxy(10,8);printf("Process Name: %s",proc.procName);
		gotoxy(10,9);printf("Process Duration: %d",proc.duration);
		sleep(proc.duration);
		gotoxy(10,11);printf("Job is completed...");
		sleep(2);
		newTask = randomQueue();

		if ((newTask % 2) == 0) // if newTask is even, then it will generate new job; otherwise it does not generate new job
		{
			newJob = generate_Task();
			full = full_Priority_Queue(H.pSize);
			if(!full)
			{
				insert_Priority_Queue(newJob,&H);
				for(j = 1; j <= H.pSize; j++) // tp include newly added task to the display
				{
					gotoxy(50,5+j);printf("Name: %s\tDuration: %d",H.pQueue[j].procName,H.pQueue[j].duration);
					build_max_heap(j,&H);
				}
			}
				
			else
			{
				printf("\n\n\tError: memory overflow...");
				sleep(4);
				break;
			}
		}
	empty = empty_Priority_Queue(H.pSize);
	}// end of job scheduling simulation
}

bool empty_Priority_Queue(int size)
{
	bool empty = false;
	if (size == 0)
		empty = true;
	return empty;
}

bool full_Priority_Queue(int size) 
{
	bool full = false;
	if (size == (Q - 1))
		full = true;
	return full;
}

void insert_Priority_Queue(PRC p, PQUEUE *H)
{
	unsigned int i = ++H->pSize;
	
	while(H->pQueue[i/2].duration > p.duration)
	{
		H->pQueue[i] = H->pQueue[i/2];
		i /= 2;
	}
	H->pQueue[i] = p;
}

PRC heap_Delete_Max(PQUEUE *H)
{
	int j;
	PRC min = H->pQueue[1];
	H->pQueue[1] = H->pQueue[H->pSize];
	H->pSize = H->pSize - 1;
	Max_heapify(1,H->pQueue,H->pSize); // heapify(1, &H)

	return min;
}

void Max_heapify(int i, PRC pQueue[], int size)
{
	int l, r, largest;
	PRC temp;
	l = 2 * i;
	r = (2 * i) + 1;
	if ((l <= size) && (pQueue[l].duration > pQueue[i].duration))
		largest = l;
	else
		largest = i;
	if((r <= size) && (pQueue[r].duration > pQueue[largest].duration))
		largest = r;
	if(largest != i)
	{
		//begin swap
		temp = pQueue[i];
		pQueue[i] = pQueue[largest];
		pQueue[largest] = temp;
		//end of swap
		Max_heapify(largest, pQueue, size);
	}
}

PRC generate_Task(void)
{
	int static count = 4; // count serves as the task number; it starts with 4 since there are already three initial tasks
	char c[6];
	int range;
	PRC p;
	
	range = MAX - MIN;
	p.duration = randomTime(range); //generates the duration of the new task
	itoa(count,c,10); // converts count which is an integer to string
	strcpy(p.procName,"Process "); 
	strcat(p.procName,c); // concatenates the word "Process" and the string equivalent of count
	count++;
	return p;
}

int randomTime(int range)
{
	return (rand() % range + MIN); 
}

int randomQueue(void)
{
	return (rand() % DIV);
}

void build_max_heap(int n, PQUEUE *H) 
{
  int i;
  for(i=n/2; i>=1; i--) 
  {
    Max_heapify(i,H->pQueue,H->pSize);
  }
}
