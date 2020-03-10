/* -----------------------------------------------------------------------------
FILENAME:          sales_struct_v5.h
DESCRIPTION:       Header file for sales_struct.cpp
USAGE:             used to learn about struct functions and to get us ready for Project 1
COMPILER:          Linux g++
NOTES:             Multiple versions will be created and added each class

MODIFICATION HISTORY:

Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-13         Version 1.1 // Basic version to read/write
					items to structure
					//Using nested structures
Brandon Lieng	   2020-02-18	      Version 1.2 Aadds currency-style formatting,
					price calculations, "-i" flag for interactive,
					and ARRAY_SIZE() macro
Brandon Lieng	   2020-02-18	      Version 1.3 // Tax_Rate added
					// Added calc total function
Brandon Lieng	   2020-02-20	      Version 1.4 // Reads input filename from command line
Brandon Lieng      2020-02-25         Version 1.5 // Adds customer array to handle multiple customers
----------------------------------------------------------------------------- */
#ifndef __SALES_STRUCT_H__
#define __SALES_STRUCT_H__

#include <cstring>		// Added for strcmp(), v1.2
#include <iostream>
#include <fstream>		// Added in v1.4

using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

const double TAX_RATE = 0.08265;	// Added v1.3

struct Item_Info
{
	char item_name[20];	// Name of item
	unsigned int qty;	// Quantity
	double price;		// Price per item
	double item_total;	// Total for items, added for v1.2
};

struct Customer
{
	int rec_num;		// Record num., added for v1.5
	char fname[20];		// First name field (or data member)
	char lname[20];		// Last name field (or data member)
	Item_Info items[9];	// Nested structure, added for v1.1
};

// Function prototypes go here

void read_file(char *file, Customer *s,int & num_recs);
void read_cust_info(istream &in, Customer *s, bool mode);
void show_cust_info(Customer *s);
void calc_total(Customer *s);
int read_recs(istream &in, Customer *s, bool mode);
void show_recs(Customer *s, int num);
void show_sizes(Customer *cust);

#endif		// __SALES_STRUCT_H__


