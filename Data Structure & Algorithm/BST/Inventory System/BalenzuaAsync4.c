//This program is a Simple Inventory System
//Nhoriel Y Balenzua
//Start: 04/11/22
//End:04/14/22 
#include <windows.h>
#include "Item.h"
#include "SalesTrans.h"

void line(void);

int main(void)
{
	char Itemname[N], ID[I];
	ITEM inv;
	SALES info;
	itemptr temp, itemroot = NULL, ptr, ptr1;
	saleptr salestemp, salesroot = NULL;
	bool added, found, deleted;
	int ch, quanSold, i;
	do
	{
		F;
		system("cls");
		line();
		printf("\n\t\t\t\t\t\tINVENTORY SYSTEM");
		printf("\n\n");
	    line();
		printf("\n\n\t\t\t1]Add New Item\n");
		printf("\t\t\t2]Delete an Item\n");
		printf("\t\t\t3]Sales Transaction\n");
		printf("\t\t\t4]Display Sales Transaction\n");
		printf("\t\t\t5]Display All Items\n");
		printf("\t\t\t6]Exit\n\n");
		line();
		printf("\n\t\t\tChoice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: inv = get_item_info();
			        temp = malloc(sizeof(NODETREE));
			        temp->item = inv;
			        temp->left = NULL;
			        temp->right = NULL;
			        found = search_for_duplicate(itemroot, inv.name);
			        if(found)
			        {
			        	printf("\n\n\tItem Already Exist...");
			        	getch();
					}
					else
					{
						added = add_item(&itemroot, temp); 
				        if(added)
					        printf("\n\n\tItem Added Successfully...");
				        else
					        printf("\n\n\tError! Item Not Added Successfully...");
				        getch();
					}
			    break;
			case 2: if(itemroot != NULL)
			        {
			          input_nameto_search(Itemname);
			          ptr = itemroot;
			          found = search_for_delete(&ptr, &ptr1, Itemname);
					  if(found)
					  {
					  	    printf("\n\n\tDeleting Item Name %s...",Itemname);
					  	    sleep(3);
					        if((ptr->left == NULL) && (ptr->right == NULL))
					            deleted = delete_leaf(&itemroot, &ptr, &ptr1);
						    else if((ptr->left != NULL) && (ptr->right != NULL))
						        deleted = delete_two_child(&itemroot, &ptr, &ptr1);
						    else
						        deleted = delete_one_child(&itemroot, &ptr, &ptr1);
						    if(deleted)
						        printf("\n\n\tItem Name %s Deleted Successfully...",Itemname);
						    else
							    printf("\n\n\tItem Name %s was Not Deleted Successfully...",Itemname);   
					  }
					  else
					  {
					  	printf("\n\n\tItem Name %s not found...",Itemname);
					  }	
					}
					else
						printf("\n\n\tInventory is Empty...");
			            getch();
			    break;
			case 3: if(itemroot != NULL)
		            {
		            	input_nameto_search(Itemname);
			            ptr = itemroot;
			            found = search_for_delete(&ptr, &ptr1, Itemname);
			            if(found)
			            {
			        	    quanSold = input_quan_sold();
			        	    if(quanSold <= ptr->item.quan)
			        	    { 
							    get_sales_info(ID);
							    
			        	    	salestemp = malloc(sizeof(SALESNODE));
			        	    	strcpy(salestemp->sales.TransID, ID);
			        	    	strcpy(salestemp->sales.ItemName, Itemname);
			        	    	salestemp->sales.sold = quanSold;
								salestemp->sales.subtotal = ptr->item.price * quanSold;
								salestemp->left = NULL;
								salestemp->right = NULL; 
								
								added = add_sales(&salesroot, salestemp);
								if(added)
								{
									ptr->item.quan = ptr->item.quan - quanSold;
									printf("\n\n\tSales Transaction Added Successfully...");
								}
								else
								    printf("\n\n\tError! Sales Transaction Not Added Successfully..."); 
						    }
						    else if(ptr->item.quan <=0)
					     	    printf("\n\n\tSorry Item %s Does Not Have Enough Quantity Onhand...",Itemname);
						    else
							    printf("\n\n\tSorry Item %s Does Not Have Enough Quantity Onhand...",Itemname);
					    }
					    else
						    printf("\n\n\tItem Name %s does not exist...",Itemname);
					}
					else
					   printf("\n\n\tInventory is Empty...");
					   getch();
				break;
			case 4: if(salesroot != NULL)
			        	display_all_saleTrans(salesroot);
			        else
			            printf("\n\n\tSales Transaction is Empty...");
			            getch();
			    break;
			
			case 5: if(itemroot != NULL)
			        {
			        	F;
			        	printf("\n\n\n");
			        	printf(" Item Name\tQuantity\tPrice");
			           	display_all_items(itemroot);
					}
			        else
			            printf("\n\n\tInventory is Empty...");
			            getch();
			    break;
			case 6: printf("\n\n\tApplication will close in 3 seconds...");
			        sleep(3);
			        break;
			default:printf("\n\n\tInvalid Menu Choice...");
			        sleep(2);
			        break;
		}
	}while(ch !=6);
}

void line(void)
{
	int i;
	for(i=0 ; i<120; i++)
	{
		printf("=");
	}
}
