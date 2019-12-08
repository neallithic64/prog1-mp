/* 
*
*  Name   : LIM, MATTHEW
*  Section: S16B
*  Submission Date:
*
*/

#include <stdio.h>
#include "mp_math.h"


/* Implement the Circle() function.  It should compute and print the (x, y) coordinates of 
   which connected with line segments form the shape of a circle. */
void
Circle(double r)
{
	double theta = 0.0, x, y;
	for (theta = 0.0; theta <= 360.0; theta++) {
		x = r * cosine(deg_to_rad(theta));
		y = r * sine(deg_to_rad(theta));
		printf("%15.12lf\t%15.12lf\n", x, y);
	}
}


/* Do NOT modify the main() function. */
int
main()
{
   double r;      // radius of the circle 
   
   scanf("%lf", &r);
   Circle(r);
   return 0;
	
}
