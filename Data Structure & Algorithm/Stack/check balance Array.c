//check Expression if Balance or not
//Array Implementation
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>//for exit function

#define S 100

typedef struct node
{
	char delim[S];
	int next;
}Stack;

void Input_exp(char []);
Stack create_stack(void);
void push(Stack *,char);
char pop(Stack *);
bool isEmpty(int);
bool isFull(int);
void display(char[],bool);
bool check_exp(char[]);


int main(void)
{
	char exp[S];
	bool balance;
	Input_exp(exp);
	balance=check_exp(exp);
	display(exp,balance);
}

void Input_exp(char exp[])
{
	printf("\n\n\tInput a parenthesized expression: ");
	gets(exp);
	return;
}
Stack create_stack(void)
{
	int i;
	Stack stk;
	for(i=0; i<S-1; i++)
	{
		stk.delim[i]=0;
		stk.next=-1;
		return stk;
	}
}

void push(Stack *tos,char exp)
{
	tos->next=tos->next+1;
	tos->delim[tos->next]=exp;
	return;
}

char pop(Stack *tos)
{
	char ret=tos->delim[tos->next];
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

bool check_exp(char exp[])
{
	bool check, balance=true;
	int j=0;
	char elem, retchar;
	Stack tos;
	
	tos=create_stack();
	while(exp[j]!='\0')
	{
		elem=exp[j];
		check=isFull(tos.next);
		if(check)
		{
			printf("\n\n\tStack Is Full!");
			getch();
			exit(0);
		}
		else
		{
		   if(elem=='(')
		      push(&tos,elem);
		   else if(elem==')')
		   {
			  check=isEmpty(tos.next);
			  if(check)
			  {
				balance=false;
				break;
			  } 
			  else
			   pop(&tos);
		    }
	    }
	  j++;
	}
	check=isEmpty(tos.next);
	if(!check)
	   balance=false;
	return balance;
	   
}

void display(char exp[],bool balance)
{
	if(balance)
		printf("\n\n\tThe expression %s has balance delimeters.",exp);
	else
		printf("\n\n\tThe expression %s has an unbalance delimeters.",exp);
	getch();
	return;
}
