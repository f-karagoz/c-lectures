/**
* @author	Furkan Karagoz
* @date		21.8.2022
* 
* 
* 
*/

#include "stdio.h"
#include "math.h"

#define APP_7

#ifdef APP_1
int is_prime(int val)
{
	double val_sqrt;

	// Even numbers are not prime unles it is 2
	if (val % 2 == 0)
		return val == 2;

	val_sqrt = sqrt(val);
	for (int i = 3; i <= val_sqrt; i += 2)
		if (val % i == 0)
			return 0;

	return 1;
}

int main(void)
{
	for (int i = 2; i < 1000; i++)
		if (is_prime(i))
			printf("%d ", i);
	printf("\n");

	return 0;
}

#elif defined APP_2

/*

for (exp_1; exp_2; exp_3)
{
	statement;


is equivalent to below statement:

exp_1;
while(exp_2)
{
	statement;
	exp3;
}

*/

int main(void)
{
	// Infinite loop
	for (int i = 0; ; i++)
		printf("%d\n", i);

	return 0;
}

#elif defined APP_3
int main(void)
{
	double val = 0;

	for (;;)
	{
		printf("Enter a value: ");
		scanf("%lf", &val);
		printf("%f\n", val * val);

	}

	return 0;
}

#elif defined APP_4
int main(void)
{
	// Statements can be seperated with commas
	for (int i = 0, k = 100; i + k > 50; ++i, k -= 2)
		printf("%d %d\n", i, k);

	return 0;
}

#elif defined APP_5
int main(void)
{
	int i = 0;

	for (i = 0; getchar() != '\n'; ++i);

	printf("%d", i); // Prints out the entered chars

	return 0;
}

#elif defined APP_6

// Creating pyramid with stars / Nested for loops
int main(void)
{
	int n;

	printf("Bir sayi giriniz: ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k <= i; k++)
			putchar('*');
	putchar('\n');
	}

	return 0;
}

#elif defined APP_7
// Deyimler ve break
int main(void)
{
	int i;							// Deyim #1

	for (i = 0; i < 10; i++)		// Deyim #2
	{
		if (i == 5)
			break;					// Break, 2. deyimi sonlandirir
		printf("%d\n", i);
	}

	printf("ends...\n");		// Deyim #3

	return 0;						// Deyim #4
}

#elif defined APP_8
int main(void)
{
	return 0;
}
#endif