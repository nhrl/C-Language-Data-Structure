#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#define F while (getchar() != '\n')
#define N 30
typedef struct
{
	char name[N];
	short int quan;
	float price;
}ITEM;

typedef struct nodetree *itemptr;
struct nodetree
{
	ITEM item;
	itemptr left;
	itemptr right;	
}NODETREE;

ITEM get_item_info(void)
{
	ITEM item;
	F;
	printf("\n\tItem Name: ");
	gets(item.name);
	printf("\tQuantity: ");
	scanf("%d",&item.quan);
	printf("\tPrice: ");
	scanf("%f",&item.price);
	return item;
}

bool add_item(itemptr *root, itemptr temp)
{
	itemptr ptr, ptr1;
	ptr = *root;
	
	if(*root == NULL)
	   *root = temp;
	else
	{
		while(ptr != NULL)
		{
			ptr1 = ptr;
			if(strcmp(temp->item.name, ptr->item.name) < 0)
			   ptr = ptr->left;
			else
			   ptr = ptr->right;
		}
		if(strcmp(temp->item.name, ptr1->item.name) < 0)
		   ptr1->left = temp;
		else
		   ptr1->right = temp;
	} 
	return true;  
}

bool search_for_duplicate(itemptr root, char name[])
{
	bool found = false;
	itemptr ptr = root;
	
	while((!found) && (ptr != NULL))
	{
		if(strcmp(name, ptr->item.name) == 0)
		   found = true;
		else if(strcmp(name, ptr->item.name) <0)
		   ptr = ptr->left;
		else
		   ptr = ptr->right;
	}
	return found;
}

void display_all_data(itemptr root)
{
	printf(" %s\t\t%d\t\t%0.2f",root->item.name,root->item.quan,root->item.price);
}

void display_all_items(itemptr root)
{
	if(root->left != NULL)
	   display_all_items(root->left);
	printf("\n");
	display_all_data(root);
	if(root->right != NULL)
	   display_all_items(root->right);
}

bool search_for_delete(itemptr *ptr, itemptr *ptr1, char name[])
{
	bool found = false;
	int comp;
	while((!found) && (*ptr != NULL))
	{
		comp = strcmp(name, (*ptr)->item.name);
		if (comp != 0)
        {
          *ptr1 = *ptr;
          if (comp < 0)
          *ptr = (*ptr) -> left;
          else if (comp > 0)
          *ptr = (*ptr)->right;
        }
        else
         found = true;
	}
	return found;
}

void input_nameto_search(char name[])
{
	F;
	printf("\n\n\tInput Item Name To Search: ");
	gets(name);
	return;
}

bool delete_leaf(itemptr *root, itemptr *ptr, itemptr *ptr1)
{
	if(*ptr == *root)
	   *root = NULL;
	else
	{
	 	if(strcmp((*ptr)->item.name, (*ptr1)->item.name) < 0)
	 	   (*ptr1)->left = NULL;
	 	else
	 	   (*ptr1)->right = NULL;
	}
	free(*ptr);
	return true;
}

bool delete_one_child(itemptr *root, itemptr *ptr, itemptr *ptr1)
{
	if(*ptr == *root)
	{
		if((*ptr)->right == NULL) 
		   *root = (*ptr)->left;
		else
		   *root = (*ptr)->right;
	}
	else
	{
		if(strcmp((*ptr)->item.name, (*ptr1)->item.name) < 0)
		{
			if((*ptr)->right == NULL)
			   (*ptr1)->left = (*ptr)->left;
			else
			   (*ptr1)->left = (*ptr)->right;
		}
		else
		{
			if((*ptr)->right == NULL)
			  (*ptr1)->right = (*ptr)->left;
			else
			  (*ptr1)->right = (*ptr)->right;
		}
	}
	free(*ptr);
	return true;
}

bool delete_two_child(itemptr *root, itemptr *ptr, itemptr *ptr1)
{
	itemptr ptr2 = NULL;
	*ptr1 = (*ptr)->right;
	while((*ptr1)->left != NULL)
	{
		ptr2 = *ptr1;
		*ptr1 = (*ptr1)->left;
	}
	(*ptr)->item = (*ptr1)->item;
	
	if(ptr2 == NULL)
	{
		if((*ptr1)->right == NULL)
		  (*ptr)->right = NULL;
		else
		  (*ptr)->right = (*ptr1)->right;
	}
	else
	{
		if((*ptr1)->right == NULL)
		  ptr2->left = NULL;
		else
		  ptr2->left = (*ptr1)->right;
	}
	free(*ptr1);
	return true;
}

