/*
	CCPROG1 Machine Problem Part 2 (main.c logic)                                         
	
	DESCRIPTION    : This program prints out a list of values for sine and cosine.
	
	NAME           : LIM_MATTHEW
	
	SECTION        : S16B
	
	DATE SUBMITTED : 27/11/18
	                                                                     
	NOTES:                                                                  
	 1. Change the word "CODENAME" in the filename to your CODENAME.       
	 2. DO NOT add other header files.
	 3. DO NOT add new codes other than the implementation of the body of the main() function.     
*/

#include <stdio.h>
#include "mp_math.h"

/* 
*   Fill-up the body of the main().  You have to call the functions cosine() and sine(). 
*  	You will need printf() here to output the results 
*
*   The actual result of your program should be the same with the contents of the file 
*   expected_output.txt. 
*
*/ 
int 
main()
{
	/* Declare your own local variables below this comment. */
	
	double n = -180.0;
	
	PrintCodeName();  /*DO NOT remove this PrintCodeName() function call. */
	
	/* Write your statements below this comment. */
	
	for (; n <= 180.0; n++) {
		printf("%5.2lf\t%15.12lf\t%15.12lf\t%15.12lf\n", n, deg_to_rad(n), cosine(deg_to_rad(n)), sine(deg_to_rad(n)));
	}
	
	return 0;
}

