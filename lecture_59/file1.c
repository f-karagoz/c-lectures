#include <stdio.h>

int g_x;

void foo(void)
{
	printf("foo\n");

	g_x = 10;
}