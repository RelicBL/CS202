/* -----------------------------------------------------------------------------
FILENAME:          cust_ports_v1.h
DESCRIPTION:       Header file for cust_ports_v1.cpp
USAGE:             Will be used as a template for Project 1
COMPILER:          Linux g++
NOTES:             This will be used for as a stepping stone for Proj1, so get this right

MODIFICATION HISTORY:

Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-27         Version 1.0 // Basic version to read/write
				      // Make new structures to match what's need
Brandon Lieng      2020-03-05	      Version 1.2 // Many changes were made with Prototypes					
----------------------------------------------------------------------------- */
#ifndef __CUST_PORTS_V_1
#define __CUST_PORTS_V_1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;


struct Acct_Info
{
	char acct_id[7];	//First structure to pull data, leave as char
	double balance;
	double growth_rate;
	int cpy;
};

struct Customer
{
	char cust_id[6];
	char fname[20];		// First name 
	char lname[20];		// Last name
	char mname[20];		// Middle name
	char tax_id[20];	// Will find the tax id
	char phone_num[20];	// The persons phone number
	Acct_Info accounts[5];	// Nested structure pulling the acc. info of each
};

// Function prototypes go here
void read_record(ifstream& fin, Customer* c);
void trim_front_spaces(char cstring[], int size);
bool read_account(ifstream& fin, Acct_Info* a);
char* find_first_nonspace(char cstring[]);
char* find_first_space(char cstring[]);
void output_info(ofstream& fout, Customer* data);
#endif		// _cust_ports_v1_


