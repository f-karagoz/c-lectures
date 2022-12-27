#include <stdio.h>

#define APP2

#ifdef APP1
// Allignment, structure member allignment
// In 32-bit systems the data stored in an
// alligned memory location (bank) is accessed
// slightly faster

int main(void)
{
	printf("hi\n");
	return 0;
}

#elif defined APP2
// typedef
// 
// typedef <statement>;
// typedef int A
// In C giving a type an place holder name is called typedef stement.
// In C syntax "typedef" is placed in the "storage class specifier"
// It converts a variable name to a type name
// typedef does not declere a variable
// a storage class specifier and type name can be swapped in syntax

// typedef unsigned int size_t;

typedef char* Str;			/* also valid: char* typedef Str; */
typedef int Int, * Pint;
typedef int arr_typeDef[5];

int main(void)
{
	Str s = "ankara";	/* char* s = "ankara"; */

	printf("%s\n", s);	/* ankara */

	Int num = 10;
	Pint pnum = &num;

	printf("Num is %d and %d is num.\n", num, *pnum);

	arr_typeDef a = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

#elif defined APP3

int main(void)
{
	return 0;
}

#endif