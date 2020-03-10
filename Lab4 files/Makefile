#-------------------------------------------------------------------------------------
#
# FILE NAME:	Makefile
#
# DESCRIPTION:	Makefile for a C++ program
#		
# PURPOSE:	Build a program executable on Linux
#
# MODIFICATION HISTORY:
#
# Author	Date		Modification(s)
# ---------	------ 		---------------
# Brandon Lieng 2020-02-13	Version 1
# Brandon Lieng 2020-02-20	Version 2 // Added new code to original makefile
#_____________________________________________________________________________________

#

#	This is our original generic makefile command that will build
#	any stand alone ".cpp" souce file.
#	Usage: e.g., make hello

.cpp :
	g++ -o $* $*.cpp -std=c++11

#	This will build the executables that ahve dependencies on .h files
#	Usage: e.g., make cust_ports

%: %.cpp %.h
	g++ -o $* $*.cpp -std=c++11
