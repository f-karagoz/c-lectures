#define EX3

#include <stdio.h>

#ifdef EX1

int foo()
{
	printf("foo called.\n");
	return 1;
}

int bar()
{
	printf("foo called.\n");
	return 0;
}

int tar()
{
	printf("foo called.\n");
	return 1;
}

int main(void)
{
	int result = foo() || bar() && tar();
	printf("Result: %d\n", result);
	return 0;
}

#elif defined EX2

int main()
{
	int a, b;

	a = b = 10 + 20;

	printf("a=%d\tb=%d\n", a, b);

	a = (b = 10) + 20;

	printf("a=%d\tb=%d\n", a, b);

	return 0;
}

#elif defined EX3

int main()
{
	int a = a;

	printf("Value of a is: %d\n",a);

	return 0;
}

#elif defined EX4

int main()
{
	return 0;
}

#elif defined EX5

int main()
{
	return 0;
}

#endif