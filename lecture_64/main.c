#include <stdio.h>

#define APP4

#ifdef APP1
/* Volatile Pointers */

// volatile int* pi;				/* Pointed location is volatile */
// int* volatile pi;				/* Pointer is voltile */
// volatile int* volatile pi;	/* Both location and the pointer is volatile */

int main(void)
{
	int a = 1;
	volatile int b = 2;

	int* pi;
	volatile int* pii;

	pi = &a;		/* Good access */
	//pi = &b;		/* Bad access */
	pii = &a;		/* Good access */
	pii = &b;		/* Good access */

	return 0;
}

#elif defined APP2
/* ENUMERATION */

// They specify constant
// Handled in the compiler module, not preprocessor

enum Color
{
	red,
	green,
	blue
};

enum Color_
{
	red_ = 10,
	green_,
	blue_
};

enum { sunday, monday, tuesday, wednesday, thursday, friday, saturday };

int main(void)
{
	Color color = red;

	for (int i = 0; i < 3; ++i)
		if (color == i)
			printf("color is red.\n");
		else
			printf("color is not red.\n");

	Color_ color_ = red_;

	for (int i = 10; i < 13; ++i)
		if (color_ == i)
			printf("color_ is red_.\n");
		else
			printf("color_ is not red_.\n");

	return 0;
}

#elif defined APP3
// Value of enums are limited to the system's int types value limits

enum Command
{
	ADD = 1,
	DEL = 3,
	LIST = 5,
	QUIT = 7,
	RETURN = 1		/* Enums can also have the same numerical values */
};

enum Test
{
	TVAL1 = 2147483646,
	TVAL2,
//	TVAL3		// Invalid, enumaration value is higher than the limit
};

enum Test2
{
	TVALL1 = -1,
	TVALL2,			/* 0 */
	TVALL3			/* 1 */
};

int main(void)
{
	return 0;
}

#elif defined APP4
/* Pointers to pointers */

// Pointers are objects too
// Therefore their addresses can be gathered too

// Compiler should support up to level-32 pointers

int main(void)
{
	int a = 10;			/* int : int */
	int *pi = &a;		/* int * : pointer to int */
	int **ppi = &pi;	/* int ** : pointer to int pointer */
	int*** pppi = &ppi;	/* int *** : pointer to pointer to pointer to int */

	printf("Value of object pointed is : %d\n", ***pppi);

	// int******************************** ppppppppppppppppppppppppppppppppi;

	return 0;
}

#endif