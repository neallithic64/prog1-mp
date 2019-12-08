/*
	CCPROG1 Machine Problem Part 2 (math.c logic)                                         
	
	DESCRIPTION    : This source file contains the code to calculate sine and cosine of a number.
	
	NAME           : LIM_MATTHEW
	
	SECTION        : S16B               
	
	DATE SUBMITTED : 27/11/18
	
	NOTES:                                                                  
		1. Change the word "CODENAME" in the filename to your CODENAME.       
		2. Change the string constain in #define CODENAME line below with your own CODENAME.
		3. DO NOT remove or change the #include directives below.
		4. DO NOT add any other header file.
		5. DO NOT call printf() inside this file!
     
*/

#include <stdio.h>
#include "mp_math.h"

#define NUMBER_OF_TERMS 15

/* Change the string "SHAZAM" below to your own CODENAME */
#define CODENAME "LINGUA"


/* 
*  DO NOT remove or change the following PrintCodeName() function definition. 
*
*/
void 
PrintCodeName(void)
{
	fprintf(stdout, "%s\n\n", CODENAME);
}


/*  
*  1.  DEFINE the deg_to_rad() function.
*
*/

double deg_to_rad(double x) {
	return x*(PI/180);
}

/*  
*  2.  DEFINE a function that will compute and return the value of x (double) raised to n (int).
*
*/

double exponent(double x, int n) { // base and index
	int nCountExp;
	double newX = x;
	if (n == 0)
		return 1;
	if (n > 0) {
		for (nCountExp = 1; nCountExp+1 <= n; nCountExp++) {
			x *= newX;
		}
	}
		else if (n < 0) {
			for (nCountExp = 1; nCountExp-1 >= n; nCountExp--) {
				x /= newX;
			}
		}
	return x;
}

/*  
*  3.  DEFINE a function that will compute and return the value of the factorial of n (int).
*
*/

double factorial(int n) {
	double nCountFac = 1, nFact = nCountFac;
	if (n == 0)
		return 1;
	for ( ; nCountFac <= n; nCountFac++) {
		nFact *= nCountFac;
	}
	return nFact;
}

/*  
*  4.  DEFINE the cosine() function.  It should call the function that you defined
*      in numbers 2 and 3 above.
*
*/

double cosine(double x) {
	int nCol1 = 1, nCol2 = 2*(nCol1-1);
	double nCol3 = exponent(x, nCol2);
	double nCol4 = factorial(nCol2);
	double nCol5 = nCol3/nCol4;
	double nCol6 = 0.0;
		
	for ( ; nCol1 <= NUMBER_OF_TERMS; nCol1++) {
		nCol2 = 2*(nCol1-1);
		nCol3 = exponent(x, nCol2);
		nCol4 = factorial(nCol2);
		if (nCol1%2 == 0)
			nCol5 = -1 * nCol3/nCol4;
			else if (nCol1%2 == 1)
				nCol5 = nCol3/nCol4;
		nCol6 += nCol5;
	}
	return nCol6;
}

/*  
*  5.  DEFINE the sine() function. It should call the function that you defined
*      in numbers 2 and 3 above.
*
*/

double sine(double x) {
	int nCol1 = 1, nCol2 = 2*(nCol1+1);
	double nCol3 = exponent(x, nCol2);
	double nCol4 = factorial(nCol2);
	double nCol5 = nCol3/nCol4;
	double nCol6 = 0.0;
			
	for ( ; nCol1 <= NUMBER_OF_TERMS; nCol1++) {
		nCol2 = (2*nCol1)-1;
		nCol3 = exponent(x, nCol2);
		nCol4 = factorial(nCol2);
		if (nCol1%2 == 0)
			nCol5 = -1 * nCol3/nCol4;
			else if (nCol1%2 == 1)
				nCol5 = nCol3/nCol4;
		nCol6 += nCol5;
	}
	return nCol6;
}
