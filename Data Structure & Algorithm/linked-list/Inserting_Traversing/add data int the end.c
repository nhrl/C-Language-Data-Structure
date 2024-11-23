#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};
void add_num(struct node*, int);

int main(void)
{
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head->data=78;
	head->next=NULL;
	
	add_num(head,56);
	add_num(head,70);
	
	struct node* ptr=head;
	
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
}
void add_num(struct node *head, int data)
{
	//create 2 pointer for new data and for traversing
	struct node *ptr,*temp;
	
	temp=(struct node*)malloc(sizeof(struct node));//create new node
	temp->data=data;
	temp->next=NULL;
	
	ptr=head;
	
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
}
