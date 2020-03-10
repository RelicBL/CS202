/* -----------------------------------------------------------------------------
FILE NAME:         Pointers.cpp
DESCRIPTION:       Program that will be turned in for Lab1
USAGE:             Learn about pointers
COMPILER:          GNU g++ compiler on Linux
NOTES:             Pointer program demonstration

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Brandon Lieng     2020-02-02         1.0  Original version
----------------------------------------------------------------------------- */
//This program storeas the address of a variable in a pointer
#include <iostream>

using namespace std;

const char PROGRAMMER_NAME[] = "Brandon Lieng";

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say what this function does
RETURNS:           0
NOTES:             Optional notes on this function
------------------------------------------------------------------------------- */
int main()
{
	int x = 25;			//int variable
	int * ptr = nullptr;		// Pointer variable, can pointto an int

	ptr = &x;			//Store the address of x in ptr
	cout << "The hex address of x is: " << ptr << endl;
	cout << "The dec address of x is: " << (long long) ptr << endl;
	cout << "The size of ptr is " << sizeof (ptr) << " bytes\n";
	cout << endl;

	cout << endl;
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
	cout << __DATE__ << "  " __TIME__ << endl;
	cout << endl;

	return 0;

}
