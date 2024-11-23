#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <math.h>

#define F while (getchar() != '\n')
#define S 10
#define K 27

typedef struct
{
    char empId[5];
    char empLName[15];
    char empFName[20];
    char empMInitial[3];
    char empAddr[50];
}EMPNAME;

typedef struct node *ndPtr;
struct node
{
    EMPNAME name;
    ndPtr next;
}EMPLOYEE;

typedef struct
{
    ndPtr left;
}HASH;

void init_Hash_Table(HASH []);
EMPNAME get_data(void);
void display_Hash_Table(HASH []);
int string_convert(char []);
void separate_Chaining(HASH [],int, EMPNAME);
int hash_Truncation(int);
void display_Hash_Table(HASH []);
EMPNAME get_data_search(void);
bool search_element(HASH [], int, EMPNAME *, char []);
bool delete_data(HASH [], int, char []);

int main(void)
{
	int choice, key;
	char con;
	bool found, deleted;
	EMPNAME empname,lname;
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
			case 1: empname = get_data();
			        key = string_convert(empname.empLName);
			        separate_Chaining(hash_Table, key, empname);
			        display_Hash_Table(hash_Table);
			    break;
			case 2: lname= get_data_search();
			        key = string_convert(lname.empLName);
			        found = search_element(hash_Table, key, &empname, lname.empLName);
			        if(found)
			        {
			        	printf("\n\tLast Name: %s", empname.empLName);
			        	printf("\n\tFirst Name: %s", empname.empFName);
			        	printf("\n\tMiddle Initial: %s",empname.empMInitial);
			        	printf("\n\tAddress: %s", empname.empAddr);
			        	sleep(5);
					}
					else
					    printf("\n\tEmployee Not Found");
					sleep(2);
			    break;
			case 3: display_Hash_Table(hash_Table);
				break;
			case 4: lname= get_data_search();
			        key = string_convert(lname.empLName);
			        found = search_element(hash_Table, key, &empname, lname.empLName);
			        if(found)
			        {
			        	printf("\n\tID: %s",empname.empId);
			        	printf("\n\tLast Name: %s", empname.empLName);
			        	printf("\n\tFirst Name: %s", empname.empFName);
			        	printf("\n\tMiddle Initial: %s",empname.empMInitial);
			        	printf("\n\tAddress: %s", empname.empAddr);
			        	printf("\n\n\tYou Want to Delete this Record Y/N?: ");
			        	scanf("%c",&con);
			        	if(con == 'Y' || con == 'y')
			        	{
			        		deleted = delete_data(hash_Table,key,lname.empLName);
			        		if(deleted)
			        			printf("\n\tEmployee Record Deleted Successfully...");
			        		else
			        		    printf("\n\tEmployee Record Failed to Delete...");
			        	sleep(5);
						}
						else
						{
							printf("\n\tDelete Canceled...");
							sleep(3);
						}
					}
					else
					    printf("\n\tEmployee Not Found");
					sleep(2);
			    break;
			case 5: printf("\n\n\tProgram will close in 2 seconds...");
					sleep(2);
				break;
		}
	}while(choice != 5);
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

EMPNAME get_data_search(void)
{
	EMPNAME name;
	F;
	printf("\n\tEnter Last Name: ");
	gets(name.empLName);
	return name;
}

EMPNAME get_data(void)
{
	EMPNAME Empname;
	F;
	printf("\n\tEnter ID: ");
	gets(Empname.empId);
	printf("\tEnter Last Name: ");
	gets(Empname.empLName);
	printf("\tEnter First Name: ");
	gets(Empname.empFName);
	printf("\tEnter Middle Name: ");
	gets(Empname.empMInitial);
	printf("\tEnter Address: ");
	gets(Empname.empAddr);
	
	return Empname;
}

void display_Hash_Table(HASH hash_Table[])
{
	int i;
	ndPtr ptr;
	system("cls");
	printf("\n\n");
	for(i = 0; i < S;i++)
	{
		ptr = hash_Table[i].left;
		printf("\t%d",i);
		while(ptr != NULL)
		{
			printf("\t%s",ptr->name.empLName);
			ptr = ptr->next;
		}
		printf("\n");
	}
	getch();
}

int string_convert(char emp[])
{
	int key = 0, j;
	
	for(j = 0; j <2; j++)
	{
		key = key + (pow(K,j) * emp[j]);
	}
	return key;
}

void separate_Chaining(HASH hash_table[],int key, EMPNAME empname)
{
	int index;
	ndPtr temp = malloc(sizeof(EMPLOYEE));
	temp->name = empname;
	temp->next = NULL;
	index = hash_Truncation(key);
	if(hash_table[index].left != NULL)
	   temp->next = hash_table[index].left;
	hash_table[index].left = temp;
	return;
}

bool search_element(HASH hash_table[], int key, EMPNAME *empname, char lname [])
{
	int index;
	ndPtr ptr;
	bool found = false;
	index = hash_Truncation(key);
	if(hash_table[index].left != NULL)
	{
		ptr = hash_table[index].left;
		while(ptr != NULL)
		{
			if(strcmp(lname, ptr->name.empLName) == 0)
			{
				*empname = ptr->name;
				found = true;
				break;
			}
			else
			    ptr = ptr->next;
		}
	}
	return found;
}

bool delete_data(HASH hash_table[], int key, char lname[])
{
	int index;
	bool deleted = false;
	ndPtr ptr, ptr1 = NULL;
	index = hash_Truncation(key);
	if(hash_table[index].left != NULL)
	{
		ptr = hash_table[index].left;
		while(ptr != NULL)
		{
			if(strcmp(lname, ptr->name.empLName) == 0)
			{
				if(ptr1 == NULL)
				{
					if(ptr->next != NULL)
					   hash_table[index].left = ptr->next;
					else
					   hash_table[index].left = NULL;
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
