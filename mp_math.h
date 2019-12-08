/*
* mp_math.h
*
* This is the header file for Part 2 of the Machine Problem. 
*
* YOU ARE NOT ALLOWED TO MODIFY THIS FILE!!!
*
*/


#ifndef PI

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//
//  Use macro definition PI for converting an angle from degrees to radians units
//
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#define PI (3.1415926535897932384626433832795)

#endif


/* 
* Prints the CODENAME. 
*
*/

void
PrintCodeName(void);


/* 
* Convertsangle x degrees to radians. 
*
*/
double 
deg_to_rad(double x);


/* 
*
*  Computes and returns the value of the cosine of angle x 
*  Note that x is the angle measured in radians                   
*
*/
double 
cosine(double x);


/*  
*  Computes and returns the value of the sine of angle x 
*  Note that x is the angle measured in radians 
*
*/
double 
sine(double x);



