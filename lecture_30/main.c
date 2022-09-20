#include "stdio.h"

#define APP_4

#ifdef APP_1
int main(void)
{
	int val = 10;

	// using ternary (conditional) operator
	// it is a bas technique to use the operator without returning a value
	// makes the code hard to read

	if (val % 2 == 0)									// This is OK
	{
		printf("even\n");
	}
	else
	{
		printf("odd\n");
	}

	printf(val % 2 == 0 ? "even\n" : "odd\n");			// GOOD technique

	val % 2 == 0 ? printf("even\n") : printf("odd\n");	// BAD technique

	return 0;
}

/*
* Recommended usages:
* 
* 1) result = val % 2 == 0 ? 100 : 200;
* 
* *)	if ( val % 2 == 0 )
*			result = 100;
*		else
*			result = 200;
* 
* 2) foo ( val % 2 == 0 ? 100 : 200 );
* 
* *)	if ( val % 2 == 0 )
*			foo ( 100 );
*		else
*			foo ( 200 );
* 
* 3) return val % 2 == 0 ? 100 : 200;
* 
* *)	if ( val % 2 == 0 )
*			foo ( 100 );
*		else
*			foo ( 200 );
* 
*/

#elif defined APP_2
// print out numbers from 1 to 100 in 5 element rows
int main(void)
{
	for (int i = 1; i <= 100; i++)
	{
		printf("%d", i);
		putchar(i % 5 == 0 ? '\n': ' ');
	}

	// More compact, same result
	for (int i = 1; i <= 100; i++)
		printf("%d%c", i, i % 5 == 0 ? '\n' : ' ');

	return 0;
}

#elif defined APP_3
// usage in macro functions

#define MAX(a,b)		((a)>(b)?(a):(b))

int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int result1;
	int result2;

	result1 = max(5, 10);
	printf("Max is: %d\n", result1 );
	result2 = MAX(5, 10);
	printf("Max is: %d\n", result2 );

	return 0;
}

#elif defined APP_4
// nested usage

int main(void)
{
	int result, a, b, c;

	printf("a: ");
	scanf_s("%d", &a);
	printf("b: ");
	scanf_s("%d", &b);
	printf("c: ");
	scanf_s("%d", &c);

	result = a > b ? ( a > c ? a : ( b > c ? b : c) ) : ( b > c ? b : c );
	printf("result: %d", result);



	return 0;
}

#elif defined APP_5
int main(void)
{
	return 0;
}

#endif