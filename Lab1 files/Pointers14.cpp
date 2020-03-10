/* -----------------------------------------------------------------------------
FILE NAME:         Pointers14.cpp
DESCRIPTION:       Program that will be turned in for Lab1
USAGE:             Learn about pointers
COMPILER:          GNU g++ compiler on Linux
NOTES:             Pointer program demonstration

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Brandon Lieng      2020-02-02         1.1 Version
Brandon Lieng	   2020-02-06	      1.2 Version
Brandon Lieng	   2020-02-11	      1.3 Version
Brandon Lieng	   2020-02-13	      1.4 Version
----------------------------------------------------------------------------- */
//This program storeas the address of a variable in a pointer
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>


using namespace std;

const char PROGRAMMER_NAME[] = "Brandon Lieng";
// Prototypes
void write_to_file(char *file_name);
void pointer_list(ostream &file_name);

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say what this function does
RETURNS:           0
NOTES:             Optional notes
[i] = *(____ + i)
------------------------------------------------------------------------------- */
int main()
{
	char file_name[] = "pointers.txt";

	pointer_list(cout);
	write_to_file(file_name);

	cout << endl;
        cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
        cout << __DATE__ << "  " __TIME__ << endl;
        cout << endl;

}

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Say what this function does
RETURNS:           0
NOTES:             Optional notes
[i] = *(____ + i)
------------------------------------------------------------------------------- */

void write_to_file(char *file_name)
{
	char command[50];
	ofstream fout(file_name);

	if (fout)
	{
		cout << "Writing to output file: " << file_name << endl;
		pointer_list(fout);
		fout.close();
		sprintf(command, "chmod 400 %s \n", file_name);
		system(command);
		cout << command << endl;
	}
	else
		cout << "\nCould not open output file: " << file_name << endl;

}



/* -----------------------------------------------------------------------------
FUNCTION:          ptr_list()
DESCRIPTION:       Pointer functions that has both array & ptr notation
		   Used a loop to run through the notations
RETURNS:           void
NOTES:             Optional notes
[i] = *(____ + i)
------------------------------------------------------------------------------- */
void pointer_list(ostream &file_name)
{

	int x = 25;			//int variable
	int * ptr = nullptr;		// Pointer variable, can point to an int


	char My_name[] = "Brandon Lieng";
	int length;
	length = strlen(My_name); //From the book, how to use strlen

	cout << "My  name  is " <<   My_name(fout) << endl;
	cout << "The size  of " <<   My_name  << " is " << sizeof(My_name) << endl;
	cout << "The lengh of " <<   My_name << " is " << length <<  endl; 
	cout << endl;

		for (int i= 0 ; i <= length; i++)
		{
		 cout <<" Char " << right << setw(3) << i << " is " << (char)My_name[i] <<
			 setw(1) << "  at address: " <<
		        (long long) &My_name[i] << " with a value of: " << right << setw(3) <<
			(int) My_name[i] << endl;
						
		}		
		
		 cout << endl;		

		for (int i= 0 ; i <= length; i++)
                {
                 cout <<" Char " << right << setw(3) << i << " is " << (char) *(My_name + i) <<
                         setw(1) << "  at address: " <<
                        (long long) (My_name + i) << " with a value of: " << right << setw(3) <<
                        (int) *(My_name + i) << endl;

                }
	cout << endl;
}
