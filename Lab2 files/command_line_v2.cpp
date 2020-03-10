/* -----------------------------------------------------------------------------
FILE NAME:         command_line_v2.cpp
DESCRIPTION:       Program that will be turned in for Lab2
USAGE:             Test programs for reading command_line parameters
COMPILER:          GNU g++ compiler on Linux
NOTES:             Command_line program demonstration

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-11         1.0  Original version
Brandon Lieng	   2020-02-11	      1.2  Version1.2 of command_line
----------------------------------------------------------------------------- */
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

//prototypes
void check_arg(char[]);

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
//		cout << "Argument " << i << ": " << left << setw(16) << argv[i] << endl;
		printf("Argument %d = %-16s \n",i, argv[i]);
		if (i)  check_arg(argv[i]);
		else    cout << endl;
	}

	cout << endl;
	
	return 0;	// 0=success
}

void check_arg(char arg[])
{
	char buf[100];
	const char DASH = '-';
	char valid_options[] = "?hifap";
	char *p = valid_options;

	bool first_char = arg[0] == DASH;	// Test 1st arg's 1st char

	bool second_char = false;
	for (; *p != 0; ++p)
	{
		second_char = arg[1] == *p;
		if (second_char == true) break;
	}

	if (!first_char || !second_char)
	    printf("Invalid argument\n");

	else
	{
		printf("Option: %c", *p);
		if (arg[2] != 0)		// Look for a string
		{
			strcpy(buf, arg+2);	// Save string to buffer
			printf(" Value: %s", buf);
		}

		cout << endl;
		}

	
	
}
