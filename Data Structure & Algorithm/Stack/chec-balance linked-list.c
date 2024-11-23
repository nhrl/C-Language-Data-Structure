//check if the delimiters are balance 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>

#define S 100

typedef struct node *nd;
struct node
{
	char delim;
	nd next;
}NODE;

void input_exp(char []);
nd create_stack(void);
void push(nd *, char);
char pop(nd *);
bool isEmpty(nd);
void display(char [],bool);
bool check_delim(char[]);

int main(void)
{
	char exp[S];
	bool balance;
	input_exp(exp);
	balance=check_delim(exp);
	display(exp,balance);
}

void input_exp(char exp[])
{
	printf("Enter Expression: ");
	gets(exp);
}

nd create_stack(void)
{
	nd temp=NULL;
	return temp;
}

void push(nd *tos, char exp)
{
	nd temp=malloc(sizeof(NODE));
	temp->delim=exp;
	temp->next=NULL;
	temp->next=*tos;
	*tos=temp;
	temp=NULL;
	return;
}

char pop(nd *tos)
{
	char ret_exp=(*tos)->delim;
	nd temp= *tos;
	*tos=(*tos)->next;
	free(temp);
	return ret_exp;
}

bool isEmpty(nd next)
{
	if(next==NULL)
	   return true;
	else
	   return false;
}

void display(char exp[],bool balance)
{
	if(balance)
	  printf("Expression %s is Balance:",exp);
	else
	  printf("Expression %s is not Balance:",exp);
}

bool check_delim(char arr[])
{
	bool check, balance=true;
	int j=0;
	char exp, retchar;
	nd tos;
	
	tos=create_stack();
	while(arr[j]!='\0')
	{
		exp=arr[j];
		if(exp=='(')
		  push(&tos,exp);
		else if(exp==')')
		{
			check=isEmpty(tos);
			if(check)
			{
				balance=false;
				break;
			}
			else
			   pop(&tos);
		}
		j++;
	}
	check=isEmpty(tos);
	if(!check)
	   balance=false;
	return balance;
}
