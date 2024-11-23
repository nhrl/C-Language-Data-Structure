#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node* add(struct node*, int);

int main(void)
{
	struct node *head=malloc(sizeof(struct node));
	head->data=50;
	head->next=NULL;
	
	struct node *ptr=head;
	ptr=add(ptr,56);
	ptr=add(ptr,58);
	ptr=add(ptr,46);
	
	ptr=head;
	
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
}
struct node* add(struct node *ptr, int data)
{
	struct node *temp=malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	
	//this will add the data at the end
	ptr->next=temp;
	return temp;
}
