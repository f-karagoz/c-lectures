#include <stdio.h>
#define APP_3

#ifdef APP_1
// sizeof operator
int main(void)
{
	int a[10];
	int* pi;
	char* pc;
	size_t result;

	result = sizeof 100 + 2;
	printf("%zd\n", result);

	result = sizeof (100 + 2);
	printf("%zd\n", result);

	result = sizeof (pi);
	printf("%zd\n", result);

	result = sizeof (pc);
	printf("%zd\n", result);

	result = sizeof (a);
	printf("%zd\n", result);

	return 0;
}

#elif defined APP_2
// designated initializer
int main(void)
{
	int a[100] = {1,2,3,[50]=100,[75]=200,[99]=300};

	for (int i = 0; i < 100; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

#elif defined APP_3
// designated initializer
int main(void)
{
	int a[] = { 1,2,3,[50] = 100, 101, 102, [75] = 200,[99] = 300 };

	for (int i = 0; i < 100; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

#endif