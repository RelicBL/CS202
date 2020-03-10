/* -----------------------------------------------------------------------------
FILENAME:          sales_struct_v2.h
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
Brandon Lieng	   2020-02-18	      Version 1.3 //
----------------------------------------------------------------------------- */
#ifndef __SALES_STRUCT_H__
#define __SALES_STRUCT_H__

#include <cstring>		//added for strcmp(), v1.2
#include <iostream>

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
	char fname[20];		// First name field (or data member)
	char lname[20];		// Last name field (or data member)
	Item_Info items[5];	// Nested structure, added for v1.1
};

// Function prototypes go here

void read_cust_info(Customer *, bool mode);
void show_cust_info(Customer *);
void calc_total(Customer *s);

#endif		// __SALES_STRUCT_H__


