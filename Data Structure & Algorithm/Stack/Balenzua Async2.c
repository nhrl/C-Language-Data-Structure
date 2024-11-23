//This program will evaluates postfix expression and output the result
//Nhoriel Y. Balenzua
//Date Started: 03/06/2022
//Date Finished: 03/07/2022

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#define S 100

typedef struct node *nd;
struct node
{
	char exp;
	nd next;
}NODE;

nd createStack(void);
void push(nd *, int);
char pop(nd *);
bool isEmpty(nd);
void inputexp(char[]);
void evaluate_exp(char[]);
void display(int);
void displayError(void);

int main(void)
{
	char exp[S];
    inputexp(exp);
    evaluate_exp(exp);
}

nd createStack(void)
{
	nd temp=NULL;
	return temp;
}

void push(nd *tos, int exp)
{
	nd temp=malloc(sizeof(NODE));
	temp->exp=exp;
	temp->next=NULL;
	temp->next=*tos;
	*tos=temp;
	temp=NULL;
	return;
}

char pop(nd *tos)
{
	char ret=(*tos)->exp;
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

void inputexp(char exp[])
{
	printf("\n\n\tEnter Postfix Expression: ");
	gets(exp);
	return;
}

void evaluate_exp(char exp[])
{
	int i=0, A, B, conv, result;
	char ch;
	bool empty;
	nd tos;
	
	tos=createStack();
	while(exp[i]!='\0')
	{
		ch=exp[i];
		
		if(ch>='0' && ch<='9')
		{
			conv=ch-'0';
			push(&tos,conv);
		}
		else
		{
			empty=isEmpty(tos);
			if(empty)
				displayError();
			A=pop(&tos);
			
			empty=isEmpty(tos);
			if(empty)
				displayError();
			B=pop(&tos);
			
				switch(ch)
				{
				case '+':
					result=B+A;
					push(&tos,result);
					break;
				case '-':
					result=B-A;
					push(&tos,result);
					break;
				case '*':
					result=B*A;
					push(&tos,result);
					break;
				case '/':
					result=B/A;
					push(&tos,result);
					break;
				}
		}
		i++;
	}//end of while loop
	
	empty=isEmpty(tos);
	printf("\n\n\tResult: ");
	while(!empty)
	{
		result=pop(&tos);
		display(result);
		empty=isEmpty(tos);
	}
	getch();
}

void display(int result)
{
	printf("%d ",result);
}

void displayError(void)
{
	printf("\n\n\tError!!! Invalid Postfix Expression");
	getch();
	exit(0);
}
