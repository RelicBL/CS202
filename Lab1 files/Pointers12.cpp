/* -----------------------------------------------------------------------------
FILE NAME:         Pointers.cpp
DESCRIPTION:       Program that will be turned in for Lab1
USAGE:             Learn about pointers
COMPILER:          GNU g++ compiler on Linux
NOTES:             Pointer program demonstration

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-02         1.2 Version
Brandon Lieng	   2020-02-06	      1.2 Version
----------------------------------------------------------------------------- */
//This program storeas the address of a variable in a pointer
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

const char PROGRAMMER_NAME[] = "Brandon Lieng";

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say what this function does
RETURNS:           0
NOTES:             Optional notes on this function
[i] = *(____ + i)
------------------------------------------------------------------------------- */
int main()
{

	int x = 25;			//int variable
	int * ptr = nullptr;		// Pointer variable, can point to an int

	ptr = &x;			//Store the address of x in ptr
	cout << "The hex address of x is: " << ptr << endl;
	cout << "The dec address of x is: " << (long long)ptr << endl;
	cout << "The size of ptr is " << sizeof(ptr) << " bytes\n";
	cout << endl;

	char My_name[] = "Brandon Lieng";
	int length;
	length = strlen(My_name); //From the book, how to use strlen

	cout << "My  name  is " <<   My_name << endl;
	cout << "The size  of " <<   My_name  << " is " << sizeof(My_name) << endl;
	cout << "The lengh of " <<   My_name << " is " << length <<  endl; 
	cout << endl;

		for (int i= 0 ; i < length; i++)
		{
			 cout <<" Char " << i << " is " << (char)My_name[i] << "at address: " <<
		         [i]ptr << " with a value of: " << My_name[i] << endl;
					
			
		}		



	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;




	return 0;

}
