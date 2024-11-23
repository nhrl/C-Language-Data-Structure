#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void print(struct node*);
void count(struct node*);
void input(int*);
void add_num(struct node*,int);

int main(void)
{
	int num;
	struct node *head=(struct node*)malloc(sizeof(struct node));
	head->data=78;
	head->link=NULL;
	
	struct node *current=(struct node*)malloc(sizeof(struct node));
	current->data=67;
	current->link=NULL;
	head->link=current;
	
	current=(struct node*)malloc(sizeof(struct node));
	current->data=12;
	current->link=NULL;
	
	head->link->link=current;

	print(head);
	count(head);
	
	return 0;
}
void print(struct node *head)
{
	if(head==NULL)
	 printf("Linked-List is Empty");
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
}
void count(struct node *head)
{
	int count=0;
	if(head==NULL)
	 printf("Linked list is empty");
	struct node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("\nCount %d",count);
}

