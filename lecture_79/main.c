#include <stdio.h>
// Last lecture on C
// Date: 12 May 2023
/**********************************************/
#define APP6
/**********************************************/
/******************** APP1 ********************/
#ifdef APP1

#define SIZE		10
#define COUNT		20

int main(void)
{
#if defined(SIZE) && defined(COUNT)
	printf("YES.\n");
#else
	printf("NO.\n");
#endif
	return 0;
}

/******************** APP2 ********************/
#elif defined APP2

#define MSG(msg)	puts(#msg)	//# symbol puts the expression into ""

int main(void)
{
	MSG(this is a test);
	return 0;
}

/******************** APP3 ********************/
#elif defined APP3

#define WSTR(msg)	L##msg

int main(void)
{
	wprintf(L"%s\n", WSTR("test"));
	return 0;
}

/******************** APP4 ********************/
#elif defined APP4

#ifdef UNICODE
	#define STR(str)		L##str
	#define _tprintf		wprintf
#elif
	#define STR(str)		str
	#define _tprintf		printf
#endif

int main(void)
{
	_tprintf(STR("%s\n"), STR("this is a test\n"));
	return 0;
}

/******************** APP5 ********************/
#elif defined APP5

#define PREFIXED_NAME(name) sys_##name

int main(void)
{
	int PREFIXED_NAME(info);

	sys_info = 10;

	printf("%d\n", sys_info);	/* 10 */

	return 0;
}

/******************** APP6 ********************/
#elif defined APP6
// inline function specifier
// Supported after C99, natively by C++
// C and C++ usage differ
// Prevents function call, injects the content of the function
// where its called
// Fixes some disadvantages of macro functions (undefined behaviours)
// In many compliers, inline expansion is related with the optimization switches.
// To inline to be expanded compile with optimization switches:
// cl /O2 sample.c			(Microsoft)
// gcc -O2 sample sample.c	(gcc)

// 1. inline
// 2. static inline
// 3. extern inline

// Below the function is declared as 'inline' without 'static' or 'extern'
// In which case if the program is compiled without optimation switches we get an linker error
// When 'inline' is used as it is the function is not placed in the object file.

// When 'static inline' is used the function is stored in the object file.
// In which case the compiler calls the function with CALL command.
// This is the most popular usage of inline specifier.

// Functions have external linkage if otherwise specified
// However when functions are 'extern inline' specified this has unique meaning
// 'extern inline' functions are always put into the onject file whether they are expanded or not
// If such functions is used in many modules and the function is not inline expanded there will
// be more than one extern definitons.

//1. inline: If compiler inline expands there will be no problem.
//				If fails there will be linker error

//2. static inline: There will be no problem whether the compiler inline expandes or not.
//					If compiler cannot expands

inline int square(int a)
{
	return a * a;
} 
int main(void)
{
	int foo;
	foo = square(10);
	printf("%d", foo);	/* 100 */
	return 0;
}

/******************** APP7 ********************/
#elif defined APP7
// Pointer aliasing

int main(void)
{
	return 0;
}

/******************** APP8 ********************/
#elif defined APP8
// restrict
// Prevents pointers from coinciding
// C++ does not have 'restrict'

// void *memcpy (void * restrict s1, const void * restrict s2, size_t n);

int main(void)
{
	return 0;
}

/******************** APP9 ********************/
#elif defined APP9

int main(void)
{
	return 0;
}

/******************** APP10 ********************/
#elif defined APP10

int main(void)
{
	return 0;
}

#endif