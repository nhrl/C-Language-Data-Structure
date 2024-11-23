#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node* add_beg(struct node*,int);

int main(void)
{
	//this will help us to create a node
	struct node *head=malloc(sizeof(struct node));
	head->data=56;
	head->next=NULL;
	
	//this create a second node
	struct node *current=malloc(sizeof(struct node));
	current->data=10;
	current->next=NULL;
	head->next=current;
	
	int data=90;
	
	struct node *ptr=head;
	head=add_beg(ptr,data);
	
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
struct node* add_beg(struct node *head,int data)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	//temp link to head
	temp->next=head;
	//head is pointing to temp
	head=temp;
	return head;
}
