/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v1.cpp
DESCRIPTION:       Program that will be turned in for Lab2
USAGE:             Test programs for reading command_line parameters
COMPILER:          GNU g++ compiler on Linux
NOTES:             Command_line program demonstration

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-11         1.0  Original version
----------------------------------------------------------------------------- */
#include <iostream>
using namespace std;

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       The program's entry point
RETURNS:           0
NOTES:             int argc  // Number of parameters on the command line
		   char *argv[] // An array of pointer to C-strings
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
	cout << endl;

	for (int i = 0; i < argc; ++i)
	{
//		cout << "Command line parameter " << i << " = " << argv[i] << endl;
		printf("Command line parameter %d = %s \n",i, argv[i]);
	}

	cout << endl;
	
	return 0;	// 0=success
}
