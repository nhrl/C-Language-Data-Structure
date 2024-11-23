#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node *next;
};


int main(void)
{
	struct node *ptr=malloc(sizeof(struct node));
	ptr->data=34;
	ptr->next=NULL;
	
	struct node *current=malloc(sizeof(struct node));
	current->data=45;
	current->next=NULL;
	
	ptr->next=current;
	
	printf("%d,%d ",ptr->next->data,ptr->data);
}
