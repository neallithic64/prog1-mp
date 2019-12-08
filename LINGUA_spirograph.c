/* 
*
*  Name   : LIM, MATTHEW
*  Section: S16B
*  Submission Date: 03/12/18
*
*  Implement the program for the hypotrochoid (also known as spirograph).
*
*/

#include <stdio.h>
#include "mp_math.h"

void Spiro(double a, double b, double h) {
	double theta = 0.0, x = 0.0, y = 0.0, z = 0.0;
	
	for (theta = 0.0; theta <= 360.0*a; theta++) {
		z = (a-b)/b * theta;
		if (z > 360) // checking for inputs at more than 1 revolution
			while (z > 360)
				z -= 360.0;
		if (z < -360) // checking for inputs at less than -1 revolution
			while (z < -360)
				z += 360.0;
		x = ( (a-b) * cosine(deg_to_rad(theta)) ) + ( h * cosine(deg_to_rad(z)) );
		y = ( (a-b) * sine(deg_to_rad(theta)) ) - ( h * sine(deg_to_rad(z)) );
		printf("%lf\t%lf\n", x, y);
	}
}

int main() {
	double a, b, h;
	
	scanf("%lf %lf %lf", &a, &b, &h);
	Spiro(a, b, h);
	return 0;
}
