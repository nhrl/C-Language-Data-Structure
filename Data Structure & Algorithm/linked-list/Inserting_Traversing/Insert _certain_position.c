#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
void add_end(struct node*,int);
void add_pos(struct node*,int,int);

int main(void)
{
	struct node *head=malloc(sizeof(struct node));
	head->data=30;
	head->next=NULL;
	
	add_end(head,56);
	add_end(head,65);
	
	int data=90, pos=3;
	
    add_pos(head,data,pos);
    
    struct node *ptr=head;
    ptr=head;
    while(ptr!=NULL)
    {
    	printf("%d ",ptr->data);
    	ptr=ptr->next;
	}
}
void add_end(struct node *head,int data)
{
	struct node *temp,*ptr;
	temp=malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;
}
void add_pos(struct node *head,int data,int pos)
{
	struct node *ptr=head;
	struct node *temp=malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	pos--;
	while(pos !=1)
	{
		ptr=ptr->next;
		pos--;
	}
	temp->next=ptr->next;
	ptr->next=temp;
}
