#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

#define S 10

typedef struct node *nd;
struct node
{
	int dat_element;
	nd next;
}NODE;

typedef struct
{
	nd left;
}HASH;

int get_Data();
void init_Hash_Table(HASH []);
int hash_Truncation(int);
void separate_Chaining(HASH [],int);
void display_Hash_Table(HASH []);
bool delete_Data(HASH [],int);
bool search_element(HASH [], int, int * ); // if found we will show the location - index

int main(void)
{
	int choice, dat_e, location;
	bool found, deleted;
	HASH hash_Table[S];
	
	init_Hash_Table(hash_Table);
	do{
		system("cls");
		printf("\n\n\t1] Insert an element\n");
		printf("\t2] Search an element\n");
		printf("\t3] Display all elements\n");
		printf("\t4] Delete an element\n");
		printf("\t5] Exit\n\n");
		printf("\tChoice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:		dat_e = get_Data();
						separate_Chaining(hash_Table, dat_e);
						display_Hash_Table(hash_Table);
						break;
			case 2:		dat_e = get_Data();
						found = search_element(hash_Table, dat_e,&location);
						if(found)
							printf("\n\n\t%d is located at index %d",dat_e,location);
						else
							printf("\n\n\t%d is not found...",dat_e);
						sleep(2);
						break;
			case 3:		display_Hash_Table(hash_Table);
						break;
			case 4:		dat_e = get_Data();
						deleted = delete_Data(hash_Table, dat_e);
						if(deleted)
							printf("\n\n\t%d was successfully deleted...",dat_e);
						else
							printf("\n\n\tThe system failed to delete %d",dat_e);
						sleep(3);
						break;
			case 5:		printf("\n\n\tProgram will close in 2 seconds...");
						sleep(2);
						break;
		}// end of switch
	}while (choice != 5);
}

int get_Data(void)
{
	int data_e;
	printf("\n\n\tInput an integer data: ");
	scanf("%d",&data_e);
	return data_e;
}

void init_Hash_Table(HASH hash_Table[])
{
	int i;
	for(i = 0 ; i < S; i++)
		hash_Table[i].left = NULL;
	return;
}

int hash_Truncation(int key)
{
	int dat_index = key % 10;
	return dat_index;
}

void separate_Chaining(HASH hash_Table[],int key)
{
	int index;
	nd temp = malloc(sizeof(NODE));
	temp->dat_element = key;
	temp->next = NULL;
	index = hash_Truncation(key);
	if(hash_Table[index].left != NULL) //if true then there is already at least one node
		temp->next = hash_Table[index].left;
	hash_Table[index].left = temp;

	return;
}

void display_Hash_Table(HASH hash_Table[])
{
	int i;
	nd ptr;
	system("cls");
	printf("\n\n");
	for(i = 0; i < S;i++)
	{
		ptr = hash_Table[i].left;
		printf("\t%d",i);
		while(ptr != NULL)
		{
			printf("\t%d",ptr->dat_element);
			ptr = ptr->next;
		}
		printf("\n");
	}
	getch();
}

bool delete_Data(HASH hash_Table[],int key)
{
	bool deleted = false;
	int index;
	nd ptr, ptr1 = NULL;
	index = hash_Truncation(key);
	if(hash_Table[index].left != NULL)
	{
		ptr = hash_Table[index].left;
		while(ptr != NULL)
		{
			if(ptr->dat_element == key)
			{
				if (ptr1 == NULL)
				{
					if(ptr->next != NULL)
						hash_Table[index].left = ptr->next;
					else
						hash_Table[index].left = NULL;
				}
				else
				{
					if(ptr->next == NULL)
						ptr1->next = NULL;
					else
						ptr1->next = ptr->next;
				}
				free(ptr);
				deleted = true;
				break;
			}//end of if
			else
			{
				ptr1 = ptr;
				ptr = ptr->next;
			}
		}
	}
	return deleted;
}

bool search_element(HASH hash_Table[],int key,int *location)
{
	int index; 
	bool found = false;
	nd ptr;
	index = hash_Truncation(key);
	if(hash_Table[index].left != NULL)
	{
		ptr = hash_Table[index].left;
		while(ptr != NULL)
		{
			if(ptr->dat_element == key)
			{
				*location = index;
				found = true;
				break;
			}
			else
				ptr = ptr->next;
		}
	}
	return found;
}
