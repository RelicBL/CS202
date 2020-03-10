/* -----------------------------------------------------------------------------
FILENAME:          sales_struct_v2.cpp
DESCRIPTION:       Test program for structures
USAGE:             used to learn about struct functions to get us ready for Project 1
COMPILER:          GNU g++ compiler on Linux
NOTES:             Multiple versions will be created and added each class

MODIFICATION HISTORY:

Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-13         Version 1.1 ... basic version to read/write
					items to structure
					...using nested structures
Brandon Lieng	   2020-02-18	      Version 1.2 ... adds currency-style formatting,
					price calculations, "-i" flag for interactive,
					and ARRAY_SIZE() macro
Brandon Lieng	   2020-02-18	      Version 1.3 ... 

----------------------------------------------------------------------------- */
#include "sales_struct_v2.h"

using namespace std;

const char PROGRAMMER_NAME[] = "Brandon Lieng";
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       The program's main entry point
RETURNS:           0
NOTES:             int argc, // Number of parameters on the command line
		   char *argv[] //An array of pointers to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
	bool mode = 0;
	Customer cust;

	cout << endl;
	cout << "The size of object 'Customer' is: "
	     << sizeof(Customer) << endl;
	cout << "The size of object 'Item_Info' is: "
	     << sizeof(Item_Info) << endl;
	cout << endl;

	if (argc > 1 && strcmp(argv[1],"-i")==0) mode = 1;	// Interactive mode

	read_cust_info(& cust, mode);		// Data input
	show_cust_info(& cust);			// Output statements

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          read_cust_info()
DESCRIPTION:       Demonstrating how to use pointers to access structure
		   (also known as the "arrow operator") to access structure
RETURNS:           0
NOTES:             int argc, // Number of parameters on the command line
		   char *argv[] //An array of pointers to C-strings
------------------------------------------------------------------------------- */
void read_cust_info(Customer *s, bool mode)
{
	cout << "The size of pointer 's' is: " << sizeof(s) << endl << endl;
	
	if (mode) cout << "Enter first name: ";
	cin >> (*s).fname;

	if (mode) cout << "Enter last name: ";
	cin >> (*s).lname;

	for (int i = 0;i < ARRAY_SIZE((*s).items); ++i)
	{
		if (mode) cout << "Enter item name" << i+1 << ": ";
		cin >> (*s).items[i].item_name;

		if (mode) cout << "Enter  quantity: ";
		cin >> (*s).items[i].qty;

		if (mode) cout << "Enter  price : ";
		cin >> (*s).items[i].price;

		(*s).items[i].item_total = (*s).items[i].price * (*s).items[i].qty;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          show_cust_info()
DESCRIPTION:       Demonstrating how to use structure pointer operator
                   (also known as the "arrow operator") to access structure
RETURNS:           0
NOTES:             int argc, // Number of parameters on the command line
                   char *argv[] //An array of pointers to C-strings
------------------------------------------------------------------------------- */
void show_cust_info(Customer *s)
{
	cout << endl;			// Output statements
	printf("Customer: %s %s\n", s->fname, s->lname);
	printf("Item\t\tQty\t  Price	Qty*Price\n");

	for (int i = 0; i < ARRAY_SIZE(s->items); ++i)
	{
		printf("%-16s %2d\t %7.2f  %10.2f\n", s->items[i].item_name,
			s->items[i].qty, s->items[i].price, s ->items[i].item_total);
	}
}
