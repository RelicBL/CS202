/* -----------------------------------------------------------------------------
FILENAME:          sales_struct_v5.cpp
DESCRIPTION:       Test program for structures
USAGE:             used to learn about struct functions to get us ready for Project 1
		   ./sales_struct_v4
		   ./sales_struct_v4 -1
		   ./sales_struct_v4 -f // flag to read file
COMPILER:          GNU g++ compiler on Linux
NOTES:             Multiple versions will be created and added each class

MODIFICATION HISTORY:

Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-13         Version 1.1 // Basic version to read/write
					items to structure
					// Using nested structures
Brandon Lieng	   2020-02-18	      Version 1.2 // Adds currency-style formatting,
					price calculations, "-i" flag for interactive,
					and ARRAY_SIZE() macro
Brandon Lieng	   2020-02-18	      Version 1.3 // Create dynamic memory for 
					"cust" in main()
					// Adds calc_total() function
Brandon Lieng      2020-02-20	      Version 1.4 //Reads input filename from command line

----------------------------------------------------------------------------- */
#include "sales_struct_v5.h"

using namespace std;

const char PROGRAMMER_NAME[] = "Brandon Lieng";
/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       The program's main entry point
RETURNS:           0
NOTES:             int argc,	// Number of parameters on the command line
		   char *argv[] // An array of pointers to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
	int num_recs = 0;
	bool mode = 0;
	Customer *cust = new Customer[20];

	if (argc > 1 && strcmp(argv[1],"-1")==0)	// Test mode
		show_sizes(cust);

	else if (argc > 1 && !strcmp(argv[1],"-f")) 	//Deleted old if statement, added else if
		read_file(argv[2], cust, num_recs);	// Input from file
	else
		num_recs = read_recs(cin, cust, 1);

	

	show_recs(cust, num_recs);			// Output statements
	
	delete []  cust;
	
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;	

	return 0;
}

/* -----------------------------------------------------------------------------
FUNCTION:          show_recs()
DESCRIPTION:       Outputs the variable sizes to console
RETURNS:           void
NOTES:             int argc, // Number of parameters on the command line
                   char *argv[] //An array of pointers to C-strings
------------------------------------------------------------------------------- */
void show_sizes(Customer *cust)
{
	cout << endl;
	printf("The size of 'Customer'   is:  %ld\n", sizeof(Customer));
	printf("The size of 'Item_Info'  is:  %ld\n", sizeof(Item_Info));
	printf("The size of 'cust' ptr  is:   %ld\n", sizeof(cust));
}

/* -----------------------------------------------------------------------------
FUNCTION:          read_file()
DESCRIPTION:       Demonstrating how to read from a file using ifstream
RETURNS:           0
NOTES:             int argc, // Number of parameters on the command line
		   char *argv[] //An array of pointers to C-strings
------------------------------------------------------------------------------- */
void read_file(char * file, Customer *s, int &num_recs)
{
	ifstream infile(file);

	if (!infile)		// Test for errors
		cout << "\nError opening file: " << file << "\n\n";
	
	else
	{
		cout << "input file: " << file << endl;
		num_recs = read_recs(infile, s, 0);	// Input without prompts v1.5 change
		infile.close();
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          read_recs()
DESCRIPTION:       Reads customer records iteratively, using array element addresses
RETURNS:           0
NOTES:             int argc, // Number of parameters on the command line
                   char *argv[] //An array of pointers to C-strings
                   mode: 0 = batch, 1 = interactive
------------------------------------------------------------------------------- */
int read_recs(istream &in, Customer *s, bool mode)
{
	int num = 0;
	while(num < 20)
	{
		read_cust_info(in, &s[num], mode);
		if (in.eof())break;
		s[num++].rec_num = num;
	}
	printf("\n%3d records read.\n", num);

	return num;
}
/* -----------------------------------------------------------------------------
FUNCTION:          read_cust_info()
DESCRIPTION:       Demonstrating how to use pointers to access structure
q
q
q
q
q
q
                   (also known as the "arrow operator") to access structure
RETURNS:           0
NOTES:             int argc, // Number of parameters on the command line
                   char *argv[] //An array of pointers to C-strings
		   mode: 0 = batch, 1 = interactive
------------------------------------------------------------------------------- */
void read_cust_info(istream &in, Customer *s, bool mode)
{
//	cout << "The size of pointer 's' is: " << sizeof(s) << endl << endl;
	
	if (mode) cout << "Enter first name: ";		// Data input
	in >> (*s).fname;

	if (mode) cout << "Enter last name: ";
	in >> (*s).lname;
	
	for (int i = 0;i < ARRAY_SIZE((*s).items); ++i)
	{
		if (mode) cout << "Enter item name" << i+1 << ": ";
		in >> (*s).items[i].item_name;

		if (strcmp(s->items[i].item_name,"$")==0) break; // Added in v1.3
								 // "$" means end of record.
		if (mode) cout << "Enter  quantity: ";
		in >> (*s).items[i].qty;

		if (mode) cout << "Enter  price : ";
		in >> (*s).items[i].price;

		(*s).items[i].item_total = (*s).items[i].price * (*s).items[i].qty;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          show_recs()
DESCRIPTION:       Displays customer records iteratively, using pointer arithmatic
RETURNS:           0
NOTES:             int argc, // Number of parameters on the command line
                   char *argv[] //An array of pointers to C-strings
------------------------------------------------------------------------------- */
void show_recs(Customer *s, int num)	//1.5 Added code
{
	for(int i = 0; i < num; i++)
	{
		show_cust_info(s+i);
		calc_total(s+i);
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
	printf("Rec. num: %d\n", s->rec_num);
	printf("Customer: %s %s\n", s->fname, s->lname);
	printf("Item   Qty    Price          Qty*Price\n");

	for (int i = 0; i < ARRAY_SIZE(s->items); ++i)
	{
		if (strcmp(s->items[i].item_name,"$")==0) break; // Added in v1.4		
								 // "$" means end of record
		printf("%-16s %2d\t %7.2f  %10.2f\n", s->items[i].item_name,
			s->items[i].qty, s->items[i].price, s ->items[i].item_total);
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          calc_total()
DESCRIPTION:       Adds up the item_total in subotal, calculate taxes,
                   and finals totals.
RETURNS:           0
NOTES:             int argc, // Number of parameters on the command line
                   char *argv[] //An array of pointers to C-strings
------------------------------------------------------------------------------- */
void calc_total(Customer *s)
{
	double sub_total = 0.0;
	double sales_tax;
	double sales_tot;

	for (int i = 0;i < ARRAY_SIZE(s->items); ++i)
	{
		sub_total += s->items[i].item_total;
	}

	sales_tax = sub_total * TAX_RATE;
	sales_tot = sub_total + sales_tax;

	printf("$ Subtotal: %30.2f\n", sub_total);
	printf("$      tax: %18.3f%% %10.2f\n", 100*TAX_RATE, sales_tax);
	printf("$    Total: %30.2f\n", sales_tot);
}
