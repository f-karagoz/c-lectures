/*
* Title: C Programming Course - Lecture 51
* Author: Furkan Karagoz
* Instructor: Kaan Aslan
* Date: 8 / 12 / 2022
*/

#include "stdio.h"

/* STRUCTURES */
// Struct is a composite data type

#define APP_6

#ifdef APP_1

struct date
{
	int day, month, year;
	char* evnt;
	char* notes;
};

struct date d;

int main(void)
{
	d.day = 8;
	d.month = 12;
	d.year = 2022;

	printf("%d %d %d\n", d.day, d.month, d.year);

	printf("%p %p %p %p %p\n", &d.day, &d.month, &d.year, &d.evnt, &d.notes);

	return 0;
}

#elif defined APP_2

struct date
{
	int day, month, year;
	char* evnt;
	char* notes;
};


int main(void)
{
	struct date d;

	d.day = 8;
	d.month = 12;
	d.year = 2022;

	return 0;
}

/* ERROR: object is local, d is undefined in the out of scope */
void foo_print(void)
{
	printf("%d %d %d\n", d.day, d.month, d.year);

	printf("%p %p %p %p %p\n", &d.day, &d.month, &d.year, &d.evnt, &d.notes);
}

#elif defined APP_3

struct point
{
	int x, y, z;
};

struct point pt = { 10, 20 };

struct point pt_2 = { 1, .z = 2 };

int main(void)
{
	// z is 0. No value given to z, when instatiating the object.
	printf("%d %d %d\n", pt.x, pt.y, pt.z);
	printf("%d %d %d\n", pt_2.x, pt_2.y, pt_2.z);
	return 0;
}

#elif defined APP_4

struct sample
{
	int a, b;
};

struct sample s1;		// Member object have 0 value

int main(void)
{
	struct sample s1;	// Member object have garbage value
	return 0;
}

#elif defined APP_5

struct sample
{
	int a, b;
};

struct sample s1 = { 1, 2 };
struct sample s2;

int main(void)
{
	printf("s1: %d, %d\n", s1.a, s1.b);
	printf("s2: %d, %d\n", s2.a, s2.b);

	s2 = s1;

	printf("\nAfter assignment operation:\n");
	printf("s1: %d, %d\n", s1.a, s1.b);
	printf("s2: %d, %d\n", s2.a, s2.b);

	// If compiler left padding space between the member objects
	// there is no guarantee that these spaces will be copied
	
	return 0;
}

#elif defined APP_6

struct person
{
	char name[20];
	int no;
};

struct person p;

int main(void)
{
	char str[] = "furkan karagoz";

	int i = 0;
	while (str[i] != 0)
	{
		p.name[i] = str[i];
		i++;
	}
		
	p.name[i] = 0;

	p.no = 10;

	printf("Name: %s\nNo: %d\n", p.name, p.no);

	return 0;
}

#endif