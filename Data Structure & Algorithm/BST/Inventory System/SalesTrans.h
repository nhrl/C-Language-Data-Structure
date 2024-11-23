#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define F while (getchar() != '\n')
#define I 4
#define S 30
typedef struct
{
	char ItemName[S];
	char TransID[I];
	int sold;
	float subtotal;
}SALES;

typedef struct salesnode *saleptr;
struct salesnode
{
	SALES sales;
	saleptr left;
	saleptr right;
}SALESNODE;

int input_quan_sold(void)
{
	int quan;
	printf("\n\n\tHow Many Will You Buy in This Item? ");
	scanf("%d",&quan);
	return quan;
}

void get_sales_info(char id[])
{
	F;
	printf("\n\n\tEnter Transaction ID: ");
	gets(id);
	return;
}

bool add_sales(saleptr *root, saleptr temp)
{
	saleptr ptr, ptr1;
	ptr = *root;
	if(*root == NULL)
	   *root = temp;
	else
	{
		while(ptr != NULL)
		{
			ptr1 = ptr;
			if(strcmp(temp->sales.ItemName, ptr->sales.ItemName) < 0)
			   ptr = ptr->left;
			else
			   ptr = ptr->right;
		}
		if(strcmp(temp->sales.ItemName, ptr1->sales.ItemName) < 0)
		    ptr1->left = temp;
		else
		    ptr1->right = temp;
	}
	return true;
}

void display_all_transData(saleptr root)
{
	printf("Transaction ID: %s \n",root->sales.TransID);
	printf("Item Name: %s \n",root->sales.ItemName);
	printf("Quantity Sold: %d\n",root->sales.sold);
	printf("Sub Total: %0.2f",root->sales.subtotal);
}

void display_all_saleTrans(saleptr root)
{
	if(root->left != NULL)
	   display_all_saleTrans(root->left);
	printf("\n\n");
	display_all_transData(root);
	if(root->right != NULL)
	   display_all_saleTrans(root->right);
}

