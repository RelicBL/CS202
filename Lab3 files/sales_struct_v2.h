#ifndef __SALES_STRUCT_H__
#define __SALES_STRUCT_H__

// sales_struct_v2.h
// Header file for sales_struct.cpp

// Version 1.1 ... basic version to read/write items to structure
//		.. using nested structures
// Version 1.2 ... adds currency-style formatting, price calculations,
//		   "-i" flag for interactive mode, and ARRAY_SIZE() macro

#include <cstring>		//added for strcmp(), v1.2
#include <iostream>

using namespace std;

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

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

#endif		// __SALES_STRUCT_H__


