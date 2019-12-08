/*
	CCPROG1 Machine Problem Part 1                                          
	DESCRIPTION		: Calculating the sine and cosine of an angle in degree form without using pre-set functions from the math.h library.
	NAME			: Lim, Matthew Neal
	SECTION			: S16B
	DATE SUBMITTED	: 15th of November, 2018
*/

#include <stdio.h>
#define PI 3.1415926535897932384626433832795
#define NUMBER_OF_TERMS 15

double deg_to_rad(double x) {
	return x*(PI/180);
}

double exponent(double x, int n) { // base and index
	if (n == 0) // x^0 == 1 always, so this checking is done first
		return 1;
	int nCountExp;
	double newX = x; // copy the value of x into another var
	if (n > 0) { // if positive index
		for (nCountExp = 1; nCountExp+1 <= n; nCountExp++) {
			x *= newX; // repeatedly multiply the value of x (from newX) to itself, for as many times as indicated by the exponent
		}
	}
		else if (n < 0) { // if negative index
			for (nCountExp = 1; nCountExp-1 >= n; nCountExp--) {
				x /= newX; // repeatedly divide the value of x (from newX) to itself, for as many times as indicated by the exponent
			}
		}
	return x;
}

double factorial(int n) {
	if (n == 0) // 0! == 1 always
		return 1;
	double nCountFac = 1, nFact = nCountFac;
	for ( ; nCountFac <= n; nCountFac++) { // starting from 1, multiply an increasing positive integer to it
		nFact *= nCountFac;
	}
	return nFact;
}

void trace_cosine(double x, double true_cos_x) {
	int nCol1 = 1, nCol2 = 2*(nCol1-1); // term number and n
	double nCol3 = exponent(x, nCol2); // numerator [x^n == x^nCol2]
	double nCol4 = factorial(nCol2); // denominator [n! == nCol2!]
	double nCol5 = nCol3/nCol4; // numer/denom and the sign
	double nCol6; // cos(x) in interation nCol1
	double nCol7; // true_cos_x - approx cos(x) [nCol6]
	
	printf("**trace_cosine() output**\n");
	
	for ( ; nCol1 <= NUMBER_OF_TERMS; nCol1++) {
		nCol2 = 2*(nCol1-1);
		nCol3 = exponent(x, nCol2);
		nCol4 = factorial(nCol2);
		if (nCol1%2 == 0) // if the term is even, negative nCol5
			nCol5 = -1 * nCol3/nCol4;
			else if (nCol1%2 == 1) // if the term is odd, positive nCol5
				nCol5 = nCol3/nCol4;
				// author's note: there has to be a shorter way to do it,
				// but i can't get it to work. this'll have to do.
				// something about multiplying -1 repeatedly to change the sign.
		nCol6 += nCol5;
		nCol7 = true_cos_x - nCol6;
		printf("%2d\t%2d\t%17.12E\t%16.12E\t%16.12lf\t%16.12lf\t%16.12lf\n", nCol1, nCol2, nCol3, nCol4, nCol5, nCol6, nCol7);
	}
}

// i basically copied everything from trace_cosine(), but changing how nCol2 is calculated.
void trace_sine(double x, double true_sin_x) {
	int nCol1 = 1, nCol2 = 2*(nCol1+1);
	double nCol3 = exponent(x, nCol2);
	double nCol4 = factorial(nCol2);
	double nCol5 = nCol3/nCol4;
	double nCol6;
	double nCol7;
	
	printf("**trace_sine() output**\n");
	
	for ( ; nCol1 <= NUMBER_OF_TERMS; nCol1++) {
		nCol2 = (2*nCol1)-1;
		nCol3 = exponent(x, nCol2);
		nCol4 = factorial(nCol2);
		if (nCol1%2 == 0)
			nCol5 = -1 * nCol3/nCol4;
			else if (nCol1%2 == 1)
				nCol5 = nCol3/nCol4;
		nCol6 += nCol5;
		nCol7 = true_sin_x - nCol6;
		printf("%2d\t%2d\t%17.12E\t%16.12E\t%16.12lf\t%16.12lf\t%16.12lf\n", nCol1, nCol2, nCol3, nCol4, nCol5, nCol6, nCol7);
	}
}

int main() {

#if 0   // change #if 0 to #if 1 if you want to input values via scanf()

	double x;  // x is the angle in degrees
	double true_cos_x;
	double true_sin_x;
	
	scanf("%lf", &x);
	scanf("%lf", &true_cos_x);
	scanf("%lf", &true_sin_x);	
	
	trace_cosine(deg_to_rad(x), true_cos_x);
	printf("\n");
	trace_sine(deg_to_rad(x), true_sin_x);

#else

	// Test Case: angle is 139 degrees 
	trace_cosine(deg_to_rad(139), -0.754709580223);
	
	printf("\n");
	
	trace_sine(deg_to_rad(139), 0.656059028991);

#endif	
	
	return 0;
}
