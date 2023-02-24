#include <stdio.h>

#define APP9

#ifdef APP1
// typedef
// 
// int a;		--> type of a is int
// int a[5];	--> type of a is int[5]
// int * a[5]	--> type of a is int* [5]

typedef int I, * PI, * API[3];

int main(void)
{
	I a = 12;
	PI pi = &a;
	API api = {&a};

	return 0;
}

#elif defined APP2

// typedef can be used for funtion prototypes
typedef void F(void);
F f;	/* void f(void); */

int main(void)
{ 
	return 0;
}

#elif defined APP3

struct Date
{
	int day, month, year;
};

typedef struct Date date_t;

int main(void)
{
	date_t d = {10, 12, 1990};

	printf("%d/%d/%d\n", d.day, d.month, d.year);

	return 0;
}

#elif defined APP4

typedef struct Date
{
	int day, month, year;
}date_t;

int main(void)
{
	date_t d = { 10, 12, 1990 };

	printf("%d/%d/%d\n", d.day, d.month, d.year);

	return 0;
}

#elif defined APP5

typedef struct Date
{
	int day, month, year;
}Date;

int main(void)
{
	Date d = { 10, 12, 1990 };

	printf("%d/%d/%d\n", d.day, d.month, d.year);

	return 0;
}

#elif defined APP6

/*
* This is valid in C:
* Type name will be given uniquly by the compiler
* As there is no known type name it is not possible
* to declera new variables other than "date1" and "date2"

struct
{
	int day, month, year;
}date1, date2;

*/

// this is valid and commonly used as well
// the struct does not have a name but its
// unique struct name is typedefed as "Date"
typedef struct
{
	int day, month, year;
}Date;

typedef Date* pDate;	/* pDate's type is struct Date* */

int main(void)
{
	Date d = { 10, 12, 1990 };
	pDate pd = &d;

	printf("%d/%d/%d\n", d.day, d.month, d.year);
	printf("%d/%d/%d\n", pd->day, pd->month, pd->year);

	return 0;
}

#elif defined APP7

typedef struct
{
	int day, month, year;
}Date, *pDate;


int main(void)
{
	Date d = { 10, 12, 1990 };
	pDate pd = &d;

	printf("%d/%d/%d\n", d.day, d.month, d.year);
	printf("%d/%d/%d\n", pd->day, pd->month, pd->year);

	return 0;
}

// What is the benefit of using typedef?
// 1) Shorten the type names
// 2) Increase the portability of the code
// 3) Increase the readability of the codeyuh

#elif defined APP8
#include <stdlib.h>

typedef int I, * PI;

int main(void)
{
	PI pi;

	pi = (PI)malloc(sizeof(I) * 10);

	return 0;
}

#elif defined APP9
// Important typedefs of C
// size_t: is related with the theorotical memory size
//			of the system. E.g. lenght of array is given with
//			this type. It is an any "unsigned" type.
//			size_t strlen(const char *str);
//			void *malloc(size_t size);
// 
// ptrdiff_t: Same type addresses can be substracted.
//			After the addresses substracted the resulting
//			value if divided into size of the single address
//			Thus giving a size of array
// ...end
#include <stddef.h>

int main(void)
{
	size_t s;
	s = sizeof(int);
	// %zd format is used for printing size_t
	printf("Size of int is: %zd\n", s);

	int a[5];
	ptrdiff_t diff = &a[5] - &a[0];
	// %td format is used for printing ptrdiff_t
	printf("Dif. of addr. of a[5] and a[0] is %td\n", diff);

	return 0;
}

#endif