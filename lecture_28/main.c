/*
* Title:		CSD, C Programming
* Date:			13 / 9 / 2022
* Instructor:	Kaan Aslan
* Author:		Furkan Karagoz
*/

#include "stdio.h"

#define APP_4

#ifdef APP_1
int main(void)
{

	int type_int = 0;
	long type_long = 0;
	long long type_long_long = 0;

	printf("Size of int is : %d bytes\n", sizeof(type_int));				// 4 bytes
	printf("Size of long is : %d bytes\n", sizeof(type_long));				// 4 bytes
	printf("Size of long long is : %d bytes\n", sizeof(type_long_long));	// 8 bytes

	return 0;
}

#elif defined APP_2

#define tam			int
#define ana			main
#define bos			void
#define eger		if
#define degilse		else
#define yazf		printf
#define don			return

tam ana(bos)
{
	tam i = 0; 

	eger(i >= 0)
		yazf("pozitif\n");
	degilse
		yazf("negatif\n");

	don 0;
}

#elif defined APP_3
// Space Definitions
#define IN

void foo (int arg_)
{
	printf("I am foo with input %d\n", arg_);
}

int main(void) IN
{
	IN
	foo(IN 10);
	return 0; 
}

#elif defined APP_4
// Function-like Macros
// rule 1: paranthese all parameters
// rule 2: paranthese the right hand of the macro function definition
#define SQUARE(a)			((a) * (a))
#define AVERAGE(a, b, c)	( ( (a) + (b) + (c) ) / 3)
#define MAX(a, b)			( (a) > (b) ? (a) : (b) )

int main(void)
{
	int square = SQUARE(4);
	int average = AVERAGE(3, 5, 7);
	int max = MAX(1, 2);

	printf("Square is : %d\n", square);		// 16
	printf("Average is : %d\n", average);	// 5
	printf("Max is : %d\n", max);			// 2

	return 0;
}

#endif