/* -----------------------------------------------------------------------------
FILENAME:          cust_ports_v1.cpp
DESCRIPTION:       Grabs data and will output the information asked for
USAGE:             Code will be used as a foundation for Project 1
COMPILER:          Linux g++
NOTES:             Will be copied over as the start for Porject 1

MODIFICATION HISTORY:

Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-03-03         Version 1.0 Start of code, creating space finders
Brandon Lieng	   2020-03-05	      Vervion 1.1 Fixing and making program take info 
						  from file					
Brandon Lieng	   2020-03-05	      Version 1.2 Outputs to file					
----------------------------------------------------------------------------- */
#include "cust_ports_v1.h"

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
	Customer data[20];		// Need to give data to customer
	ifstream fin ("TestDB.dat");	// Have access to file data, but need a holder
	ofstream fout ("testout.dat");

	read_record(fin, &data[0]);   //&data[] can swap out data with own data if needed
 	output_info(fout, data);
 
	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;
	
	return 0;
}
/* -----------------------------------------------------------------------------
FUNCTION:          output_info()
DESCRIPTION:       This will output the the data into labeling
RETURNS:           0
NOTES:             int argc,    // Number of parameters on the command line
                   char *argv[] // An array of pointers to C-strings
------------------------------------------------------------------------------- */
void output_info(ofstream& fout, Customer* data)
{
	 cout <<"CUSTOMER   ID: "  << data[0].cust_id << endl; 	//Need for loop to look for multiple users
	 cout <<"FIRST    NAME: "  << data[0].fname << endl;
	 cout <<"LAST     NAME: "  << data[0].lname << endl;
	 cout <<"MIDDLE   NAME: "  << data[0].mname << endl;
	 cout <<"TAX_ID NUMBER: "  << data[0].tax_id << endl;
	 cout <<"PHONE  NUMBER: "  << data[0].phone_num << endl;
	 cout <<"Num.    Accts: "  << "2" << endl;    //Pulling random data, need to change
	 cout << endl;
	
	 cout <<"Acct Num: " << "2"
	      <<"  Acct ID: "  << data[0].accounts[0].acct_id  //formatting needs to be changed
	      <<"  Balance: "  << data[0].accounts[0].balance 
	      <<"  Rate: "  << data[0].accounts[0].growth_rate
	      <<"  C/Y: " << "12" << endl;// << data[0].accounts.cpy << endl;
}
/* -----------------------------------------------------------------------------
FUNCTION:          read_record()
DESCRIPTION:       This will read the information of file
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void read_record(ifstream& fin, Customer* c)
{
	fin.getline(c->cust_id, 6);
	trim_front_spaces(c->cust_id, 6);

	
	fin.getline(c->lname, 20, ',');		//Grabbing info of customers from file
	trim_front_spaces(c->lname, 20);	//There is a check for the ','after names
	fin.getline(c->fname, 20, ',');
	trim_front_spaces(c->fname, 20);
	fin.getline(c->mname, 20);
	trim_front_spaces(c->mname, 20);

	fin.getline(c->tax_id, 20);
	trim_front_spaces(c->tax_id, 20);
	fin.getline(c->phone_num, 20);
	trim_front_spaces(c->phone_num, 20);
	
	for(int i = 0; i < 5; i++)				//Reading the acc. data of individual
		if(read_account(fin, &c->accounts[i])) break;	//Accounting for multiple account 
								//a person has
}
/* -----------------------------------------------------------------------------
FUNCTION:          trim_front_spaces()
DESCRIPTION:       
RETURNS:           0
NOTES:             int argc, 	// Number of parameters on the command line
		   char *argv[] // An array of pointers to C-strings operator"
------------------------------------------------------------------------------- */
void trim_front_spaces(char cstring[], int size)
{
	char* temp = new char[size];
	char* p = find_first_nonspace(cstring);
	if(p > cstring + size) return;

	strcpy(temp, p);		//Will copy temporarily so that code doesn't 
	strcpy(cstring, temp);		//copy over itself
}

/* -----------------------------------------------------------------------------
FUNCTION:          find_first_space()
DESCRIPTION:       Finds the first space when looking for acc info
RETURNS:           p
NOTES:		   cstring[]
------------------------------------------------------------------------------- */
char* find_first_space(char cstring[])
{
	char* p = cstring;
	while(!isspace(*p)) p++;
	return p;
}

/* -----------------------------------------------------------------------------
FUNCTION:          find_first_nonspace()
DESCRIPTION:       Finds the first nonspace when looking for acc info
RETURNS:           p
NOTES:             cstring[]
------------------------------------------------------------------------------- */
char* find_first_nonspace(char cstring[])
{
	char* p = cstring;
	while(isspace(*p)) p++;
	return p;
}

/* -----------------------------------------------------------------------------
FUNCTION:          read_account()
DESCRIPTION:       Reading in info with a buffer. Will look for space and 
		   place whats needed for outputs
RETURNS:           false
NOTES:             cstring[]
------------------------------------------------------------------------------- */
bool read_account(ifstream& fin, Acct_Info* a)
{
	char buffer[200];
	fin.getline(buffer, 200);
	int j = 0;

	for(; j < 200; j++) if(!isspace(buffer[j])) break;
	if(j >= 199) return true;

	trim_front_spaces(buffer, 200);

	char* end = find_first_space(buffer);
	char* start = buffer;
	strncpy(a->acct_id, start, end - start); 	//strncpy ;Lets me create a cap, won't copy any more caracters than needed

	start = find_first_nonspace(end);
	end = find_first_space(start);
	a->balance = atof(start);	//changes balance to number

	start = find_first_nonspace(end);
	end = find_first_space(start);
	a->growth_rate = atof(start);//changes to number	

	start = find_first_nonspace(end);
	end = find_first_space(start);
	a->cpy = atof(start);	//changes to number

	return false;
}
