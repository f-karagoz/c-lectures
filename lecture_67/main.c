#include <stdio.h>

#define APP7

/* Function Pointers */

// When a function is created it's machine codes are
// consequent in the memory just like data types.
// 
// When function is called:
// CALL <address>
// CALL foo			/* foo is the start address of function foo() */
// 
// foo()
// ...
// ret
// 
// <return_type> (* <pointer_name>) ([parameter_decleration])
// void (*pf1)(void);
// int (*pf2)(int, int);
// double (*pf3)(double, double);
// 
// Function pointers cannot represent every functions
// It represernts functions with defined return and paramters
// 
// Also parameters names can be specified but not used by the compiler
// int (*pf)(int a, int b)
// 
// In C when we define the foo() function and denote 'foo'
// it will get the address of the foo function
// when we denote 'foo()' it will call the foo function
// 
// To assign the address of a function to a function pointer
// their signatures must match.
// 
// to call the function through the function pointer
// use 'pf()' or '(*pf)()'
// 
// int (*pf[5])(int, int);		// stores 5 function address
// 
// ...end

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int dvd(int a, int b)
{
	return a / b;
}

#ifdef APP1

int main(void)
{
	int (*pf)(int, int);
	
	pf = add;
	printf("Result: %d\n", pf(20, 10));		/* 30 */

	pf = sub;
	printf("Result: %d\n", pf(20, 10));		/* 10 */

	pf = mul;
	printf("Result: %d\n", pf(20, 10));		/* 2000 */

	pf = dvd;
	printf("Result: %d\n", pf(20, 10));		/* 2 */

	return 0;
}

#elif defined APP2
/* function pointer array */

int main(void)
{
	int (*pf2[4])(int, int) = { add, sub, mul, dvd };

	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", pf2[i](20, 10));
	}

	return 0;
}

#elif defined APP3
/* Function Pointer Typedef */

// int (*pf1)(int, int);
// void (*pf2)(void);
// 
// pf1 has type "int (*)(int, int)"
// pf2 has type "void (*)()void"
// 
// typedef void (*PF)(void);	/* PF specifies void (*)(void) */
// PF pf;						/* Now pf is same as 'void (*pf)(void)' */
// 
// 
// 
// ... end

int main(void)
{
	typedef int (*PF)(int, int);

	PF pfs[4] = {add, sub, mul, dvd};

	for (int i = 0; i < 4; ++i)
	{
		printf("%d\n", pfs[i](20, 10));
	}

	return 0;
}

#elif defined APP4
/* Passing a function pointer to a function */

void foo(void (*pf)(void))
{
	pf();
}

void bar(void)
{
	printf("bar\n");
}

void tar(void)
{
	printf("tar\n");
}

void zar(void)
{
	printf("zar\n");
}

int main(void)
{
	foo(bar);		/* bar */
	foo(tar);		/* tar */
	foo(zar);		/* zar */

	return 0;
}

#elif defined APP5
// When an event happens and it calls a function : callback function
#include <time.h>

void set_alarm(time_t target, void (*pf)(void))
{
	time_t t;

	for (;;)
	{
		t = time(NULL);
		if (t == target)
		{
			pf();
			break;
		}
	}
}

void foo(void)
{
	printf("Ok.\n");
}

int main(void)
{
	time_t t;

	t = time(NULL) + 10;

	printf("A callback function will run in 10 secs.\n");

	set_alarm(t, foo);					/* Ok. */

	printf("continues...\n");

	return 0;
}

#elif defined APP6
enum EVENTS
{
	FOREACH_PROGRESS, FOREACH_END
};

void for_each(int* pi, size_t size, void(*pf)(int*, int status))
{
	size_t i;

	for (i = 0; i < size - 1; ++i)
		pf(&pi[i], FOREACH_PROGRESS);

	pf(&pi[i], FOREACH_END);
}

void disp(int* pi, int status)
{
	printf("%d ", *pi);

	putchar(status == FOREACH_PROGRESS ? '\t' : '\n');
}

void square(int* pi)
{
	*pi = *pi * *pi;
}

int main(void)
{
	int a[5] = { 1,2,3,4,5 };

	for_each(a, 5, disp);
	for_each(a, 5, square);
	for_each(a, 5, disp);

	return 0;
}

#elif defined APP7
/* Use case of function pointer */
// stdlib.h: atexit
// atexit() calls the given functions in the reverse order, LIFO.
// Can be used for cleanup operations.
// In C++ destructors called in reverse order too.

#include <stdlib.h>

void foo(void)
{
	printf("foo\n");
}

void bar(void)
{
	printf("bar\n");
}

int main(void)
{
	/* void atexit(*function(void)); */

	atexit(foo);		/* Call the functions given when program exits */
	atexit(bar);

	printf("main ends...\n");

	return 0;
}

#endif