/* -----------------------------------------------------------------------------
FILENAME:          sales_struct_v1.cpp
DESCRIPTION:       Test program for structures
USAGE:             used to learn about struct functions to get us ready for Project 1
COMPILER:          Linux g++
NOTES:             Multiple versions will be created and added each class

MODIFICATION HISTORY:

Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-11         Version 1.1 ... basic version to read/write
					items to structure
					...using nested structures 
----------------------------------------------------------------------------- */
#include "sales_struct_v1.h"

using namespace std;

const char PROGRAMMER_NAME[] = "Brandon Lieng";
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       The program's main entry point
RETURNS:           0
NOTES:             int argc, 	// Number of parameters on the command line
		   char *argv[] // An array of pointers to C-strings
		   		// Using nested structures
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
	Customer cust;

	cout << endl;
	cout << "The size of object 'Customer' is: "
	     << sizeof(Customer) << endl;
	cout << "The size of object 'Item_Info' is: "
	     << sizeof(Item_Info) << endl;
	cout << endl;

	read_cust_info(& cust);		// Data input
	show_cust_info(& cust);		// Output statements

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
	
	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          read_cust_info()
DESCRIPTION:       Function demonstrates how to use pointers to access structures
RETURNS:           0
NOTES:             int argc,    // Number of parameters on the command line
                   char *argv[] // An array of pointers to C-strings
                                // (also known as the "arrow operator" to access structure)
------------------------------------------------------------------------------- */
void read_cust_info(Customer *s)
{
	cout << "The size of pointer 's' is: " << sizeof(s) << endl << endl;

	cout << "Enter first name: ";
	cin >> (*s).fname;

	cout << "Enter last name: ";
	cin >> (*s).lname;

	for (int i = 0;i < 5; ++i)
	{
		cout << "Enter item name" << i+1 << ": ";
		cin >> (*s).items[i].item_name;

		cout << "Enter    quantity: ";
		cin >> (*s).items[i].qty;

		cout << "Enter    price : ";
		cin >> (*s).items[i].price;
	}
}
/* -----------------------------------------------------------------------------
FUNCTION:          show_cust_info()
DESCRIPTION:       Function demonstrates how to use pointers to access structures
RETURNS:           0
NOTES:             int argc, 	// Number of parameters on the command line
		   char *argv[] // An array of pointers to C-strings
				// (also known as the "arrow operator" to access structure)
------------------------------------------------------------------------------- */
void show_cust_info(Customer *s)
{
	cout << endl;			// Output statements
	printf("Customers: %s %s\n", s->fname, s->lname);
	printf("Item\t\tQty\t  Price\n");

	for (int i = 0; i < 5; ++i)
	{
		printf("%-16s %2d\t %f\n", s->items[i].item_name,
			s->items[i].qty, s->items[i].price);
	}
}
