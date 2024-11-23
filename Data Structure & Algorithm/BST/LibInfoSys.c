/*
	This is a simple simulation of a library information system. Book cataloging is not included in
	the simulation. This program lacks the book return module, as a practice do the return module.
	
	Just like the borrow transaction, implement all modules related to book returns as a header file.
	Modify LibInfoSys.c but the modications are all about calling the modules in the return transaction
	header file.
	
	This program does not implement all the possible error trappings. Expect the program to crash at 
	some point.
	
	NOTE: the .C file and all the .H files that you created must be on the same folder.
*/

#include <windows.h>
#include "bookDetails.h"
#include "borrowerDetails.h"
#include "borrowTrans.h"

int main(void)
{
	int ch;
	char bkNum[B], bNo[4];
	bool success, found, bkFound;
	BOOK bk;
	BORROWER br;
	brPtr brTemp, brRoot = NULL;
	bkPtr temp, bkRoot= NULL, ptr, ptr1 ;
	brTrans borTransTemp, borTransRoot = NULL;
	BORTRANS bortrans;
	
	do{
		system("cls");
		printf("\n\n\t1] Add Book Record\n");
		printf("\t2] Add Borrower Record\n");
		printf("\t3] Borrow a Book\n");
		printf("\t4] Return a Book\n");
		printf("\t5] View Borrow Transactions\n");
		printf("\t6] View All Book Records\n");
		printf("\t7] Search a Book\n");
		printf("\t8] Delete Book Record\n");
		printf("\t9] Exit\n\n");
		printf("\tChoice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	bk = get_Book_Info();
					temp = malloc(sizeof(NODEBOOK));
					temp->book = bk;
					temp->left = NULL;
					temp->right = NULL;
					success = insert_Book_Data(&bkRoot,temp);
					if(success)
						printf("\n\n\tBook details was added successfully...");
					else
						printf("\n\n\tError: data not added...");
					getch();
					break;
			case 2: br = get_Borrower_Info();
					brTemp = malloc(sizeof(BORROWERNODE));
					brTemp->borrower = br;
					brTemp->left = NULL;
					brTemp->right = NULL;
					success = add_Borrower_Details(&brRoot,brTemp);
					if(success)
						printf("\n\n\tBorrower details was added successfully...");
					else
						printf("\n\n\tError: data not added...");
					getch();
					break;
			case 3:	get_Borrower_No(bNo);
					found = search_Borrower(brRoot, bNo);
					if(found)
					{
						get_Book_No(bkNum);
						ptr = bkRoot;
						bkFound = search_Delete_Book(&ptr, &ptr1,bkNum); //search_Book_No(bkRoot,bkNum);
						if (bkFound)
						{
							get_Borrow_Trans_Details(&bortrans);
												
							borTransTemp = malloc(sizeof(BORNODE));
							strcpy(borTransTemp->bortrans.bkNum,bkNum);
							strcpy(borTransTemp->bortrans.brNo, bNo);
							strcat(bNo,bkNum);
							strcpy(borTransTemp->bortrans.borrow_No ,bNo );
							strcpy(borTransTemp->bortrans.dateBorrow , bortrans.dateBorrow);
							strcpy(borTransTemp->bortrans.dateDue , bortrans.dateDue);
							borTransTemp->left = NULL;
							borTransTemp->right = NULL;
							success = insert_Borrow_Transaction(&borTransRoot,borTransTemp);
							if(success)
							{
								ptr->book.bkStatus = 'U';
								printf("\n\n\tBorrow transaction details was added successfully...");
							}
							else
								printf("\n\n\tError: data not added...");
							
						}
						else
							printf("\n\n\tBook number %s is not on the list.",bkNum);
					}
					else
						printf("\n\n\tBorrower number %s is not on the list.",bNo);
					getch();
					break;
			case 4:	printf("\n\tThis feature is not available...");
					printf("\n\tYou do this module as a practice. NO need to submit...");
					getch();
					//add your function calls to the modules in return header file
					break;
			case 5:	if (borTransRoot != NULL)
						show_Borrow_Transactions(borTransRoot);
					else
						printf("\n\tNo borrow transactions yet....");
					getch();
					break;
			case 6: if(bkRoot != NULL)
						show_Col_Headings(bkRoot);
					else
						printf("\n\tThere are no books available...")				;
					getch();
					break;
			case 7: get_Book_No(bkNum);
					found = search_Book_Details(bkRoot,bkNum);
					if(!found)
						printf("\n\n\tBook number %s is not on the list.",bkNum);
					getch();
					break;
			case 8: get_Book_No(bkNum);
					ptr = bkRoot;
					found = search_Delete_Book(&ptr, &ptr1,bkNum);
					if (found)
					{
						if((ptr->left == NULL) && (ptr->right == NULL))
							success = delete_Leaf(&bkRoot, &ptr, &ptr1);
						else if ((ptr->left != NULL) && (ptr->right != NULL))
							success = delete_Two_Children(&ptr, &ptr1);
						else
							success = delete_One_Child(&bkRoot, &ptr, &ptr1);
						if(success)
							printf("\n\tBook record was successfully deleted...");
						else
							printf("\n\tError: Book record was not deleted...");
					}
					else
						printf("\n\n\tBook number %s is not on the list.",bkNum);
					getch();
					break;
			case 9:	printf("\n\n\tApplication will close in 3 seconds...");
					sleep(3);
					break;
			default:printf("\n\n\tInvalid menu choice...");
					sleep(2);
		}// end of switch
	}while(ch != 9);
	return 0;
	
}
