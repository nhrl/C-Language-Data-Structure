#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodetree *nodPtr;
struct nodetree
{
	int data;
	nodPtr left;
	nodPtr right;
}NODETREE;

void insertData(nodPtr *, int);
bool SearchData(nodPtr , int);
void DisplayAllData(nodPtr );
int addData(void);
int searchMin(nodPtr );
int searchMax(nodPtr );
bool searchDelete(nodPtr *, nodPtr*, int);
bool deleteLeaf(nodPtr *,nodPtr *, nodPtr *);
bool deleteonechild(nodPtr *,nodPtr *, nodPtr *);
bool deletetwochildSuccessor(nodPtr *, nodPtr *);

int main(void)
{
	nodPtr root = NULL;//create root
	nodPtr ptr, ptr1;
	bool found, deleted;
	int num,ch;
	
	do{
    system("cls");
	printf("\n\n");
	printf("\t1] Insert Data\n");
	printf("\t2] Search for Specific Value\n");
	printf("\t3] Display All Value\n");
	printf("\t4] Display Max Value\n");
	printf("\t5] Display Min Value\n");
	printf("\t6] Delete\n");
	printf("\t7] Exit\n");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	
	   switch(ch)
	   {
		case 1: num=addData();
		        insertData(&root, num);
			break;
		case 2: num = addData();
		        found = SearchData(root, num);
		        if(found)
		        	printf("\n\tData %d is Found..",num);
				else
				    printf("\n\tData %d is not Found..",num);
			getch();
			break;
		case 3: if(root != NULL)
		     {
		     	DisplayAllData(root);
			 }
			 else
			    printf("\n\n\tBST is Empty");
			    getch();
	       	break;
	    case 4: if(root != NULL)
	            {
	            	num=searchMax(root);
	            	printf("\n\n\tMax Value is %d",num);
				}
				else
				    printf("\n\n\tBST is Empty");
				    getch();
	    	break;
	    case 5: if(root != NULL)
	            {
	                num=searchMin(root);
	                printf("\n\n\tMin Value is %d",num);
				}
				else
				    printf("\n\n\tBST is Empty");
				    getch();
				break;
		case 6: if(root != NULL)
		        {
		        	num = addData();
		        	ptr = root;
		        	found = searchDelete(&ptr, &ptr1, num);
		        	if(found)
		        	{
		        		if(ptr->left == NULL && ptr->right == NULL)
		        		  deleted = deleteLeaf(&root, &ptr, &ptr1);
		        		else if((ptr->left != NULL) && (ptr->right != NULL))
		        		  deleted = deletetwochildSuccessor(&ptr, &ptr1);
		        		else
		        		  deleted = deleteonechild(&root ,&ptr, &ptr1);
		        		if(deleted)
		        		   printf("\n\n\t%d Deleted Successfully...",num);
		        		else
		        		   printf("\n\n\tError...");
					}
					else
					printf("\n\n\t%d is not Found",num);
				}
				else
				    printf("\n\n\tBST is Empty");
				    getch();
				break;
		case 7: printf("\n\n\tExit Program");
		        sleep(5);
		        exit(0);
		        break;
		default: printf("\n\t Incorrect Choice!");
		     getch();
	   }
	}while(ch != 8);
	
	
}

int addData(void)
{
	int num;
	printf("\n\tInput Number: ");
	scanf("%d",&num);
	return num;
}

void insertData(nodPtr *root, int num)
{
	nodPtr ptr, ptr1, temp=malloc(sizeof(NODETREE));
	ptr=*root;
	
	temp->data=num;
	temp->left=NULL;
	temp->right=NULL;
	
	if(*root==NULL)
	  *root=temp;
	else
	{
		while(ptr!=NULL)
		{
			ptr1=ptr;
			if(temp->data <= ptr->data)
			   ptr=ptr->left;
			else
			   ptr=ptr->right;
		}//end of traversal
		//insert
		if(temp->data <=ptr1->data)
		   ptr1->left=temp;
		else
		   ptr1->right=temp;
	}
}

bool SearchData(nodPtr root, int searchNum)
{
	bool found=false;
	nodPtr ptr=root;
	
	while((!found) && (ptr!=NULL))
	{
		if(searchNum == ptr->data)
		{
			found = true;
		}
		else if(searchNum <= ptr->data)
		      ptr = ptr->left;
		else
		      ptr = ptr->right; 
	}
	return found;
}

void DisplayAllData(nodPtr root)
{
	if(root->left != NULL)
	  DisplayAllData(root->left);
	printf("\n\n");
	printf("Element : %d",root->data);
	if(root->right != NULL)
	  DisplayAllData(root->right);
	return;
}

int searchMin(nodPtr root)
{
	nodPtr ptr=root;
	while(ptr->left != NULL)
	    ptr= ptr->left;
	return ptr->data;
}

int searchMax(nodPtr root)
{
	nodPtr ptr=root;
	while(ptr->right != NULL)
	    ptr= ptr->right;
	return ptr->data;
}

bool searchDelete(nodPtr *ptr, nodPtr *ptr1, int num)
{
	bool found = false;
	
	while((!found) && (*ptr!=NULL))
	{
		if(num == (*ptr)->data)
		found = true;
		else
		{
			*ptr1 = *ptr;
			if(num < (*ptr)->data)
			   *ptr = (*ptr)->left;
			else
			   *ptr = (*ptr)->right;	  
		}
	}
	return found;
}

bool deleteLeaf(nodPtr *root,nodPtr *ptr, nodPtr *ptr1)
{
	if(*root == *ptr)
		*root = NULL;
	else
	{
		if((*ptr)->data < (*ptr1)->data)
		    (*ptr1)->left = NULL;
		else
		    (*ptr1)->right = NULL;
	}
	free(*ptr);
	return true;
}

bool deleteonechild(nodPtr *root,nodPtr *ptr, nodPtr *ptr1)
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
		if((*ptr)->data < (*ptr1)->data)
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

bool deletetwochildSuccessor(nodPtr *ptr, nodPtr *ptr1)
{
	nodPtr ptr2 = NULL;
	
	*ptr1 = (*ptr)->right;
	while((*ptr1)->left != NULL)
	{
		ptr2 = *ptr1;
		*ptr1 = (*ptr1)->left;
	}
	(*ptr)->data = (*ptr1)->data;
	
	if(ptr2 != NULL)
	{
		if((*ptr1)->right == NULL)
		   ptr2->left = NULL;
		else
		   ptr2->left = (*ptr1)->right;
	}
	else
	{
		if((*ptr1)->right == NULL)
		   (*ptr)->right = NULL;
		else
		   (*ptr)->right = (*ptr1)->right;
	}
	free(*ptr1);
	return true;
}
