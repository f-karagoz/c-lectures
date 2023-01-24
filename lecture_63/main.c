#include <stdio.h>

#define APP_3

#ifdef APP_1
/* constant pointer as parameter */

int foo(const int* par);	/* means that foo does not change the content pointed by param */

int main(void)
{
	return 0;
}

int foo(const int* par)
{
	if (par != NULL)
		return 1;
	else
		return 0;
}

#elif defined APP_2
/* constant pointer with structures */

typedef struct Person_t
{
	int a;
}Person, *PPerson;

typedef const struct Person* PCPerson;

int main(void)
{
	Person per;
	PPerson pper = &per;

	const Person cper = { 10 };
	PCPerson pcper = &cper;

	return 0;
}

#elif defined APP_3
/* VOLATILE */

/*
x = a + 10;
y = a + 20;

mov reg1, a
mov reg1, 10
add reg2, reg1
mov x, reg2
.....
add reg1,20
mov y, reg1

if value of a is changed between two lines of code the
second line of code will fail. This change can be sourced by
another theread, or interrupt routine (in embedded systems)
*/

int g_flag;

volatile int g_flag_2;

int main(void)
{
	// g_flag may be placed into register in the compiler time
	// optimization purposes. If g_flag is changed by outside sources
	// the effect of the chnage may nit be applied to the code below
	while (g_flag == 0)
	{
		/* ... */
	}

	while (g_flag_2)	/* corrent usage */
	{
		/* ... */
	}

	return 0;
}

#endif