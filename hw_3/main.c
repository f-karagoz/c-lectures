/*
* title:		CSD C Programming Course HW-3
* instructor:	Kaan Arslan
* author:		Furkan Karagoz
* date:			28 / 9 / 2022
* 
* TASK 1:	N/A
* TASK 2:	DONE
* TASK 3:	N/A
* TASK 4:	DONE
* 
*/

#include "stdio.h"

// @usage: change this definion between APP_1, APP_2, APP_3, and APP_4
//			to compile for 4 different question answers
#define APP_2

#ifdef APP_1
// crown

int main(void)
{
	return 0;
}

#elif defined APP_2
// armstrong number
long double pow(long double x, int y);
int is_armstrong(int val);
void print_armstrongs(int n);

int main(void)
{
	int val;
	while (1)
	{
		printf("Enter 0 to printf Armstong numbers.\n");
		printf("Enter a number to check for Armstrong number : ");
		scanf_s("%d", &val);

		if (val == 0)
		{
			print_armstrongs(1000000);
		}
		else
		{
			if (is_armstrong(val))
				printf("Number %d is a Armstrong number.\n", val);
			else
				printf("Number %d is NOT a Armstrong number.\n", val);
		}
		//printf("test %f\n", pow(0,3));
	}
	return 0;
}

int is_armstrong(int val_)
{
	// highest int 2147483647 has 10 digits

	int val = val_;
	int armstrongComputedVal = 0;
	int totalDigits = 0;

	if (val == 0)
		return 0;

	int digits[10];

	for (int i = 0; i < 10; i++)
	{
		digits[i] = val % 10;
		//printf("Digit[%d]: %d\t", i, digits[i]);
		val /= 10;
	}

	for (int i = 10; i > 0; i--)
	{
		if (digits[i-1] != 0)
		{
			totalDigits = i;
			break;
		}
	}

	//printf("Total digits: %d\n", totalDigits);

	for (int i = 0; i < totalDigits; i++)
	{
		armstrongComputedVal += pow(digits[i], totalDigits);
	}

	if (armstrongComputedVal == val_)
		return 1;
	else
		return 0;
}

void print_armstrongs(int n)
{
	if (n < 1)
	{
		printf("Invalid input\n");
		return;
	}

	int number = 0;

	putchar('\n');

	while (1)
	{

		if ( is_armstrong(number) )
			printf("%d ", number);

		if (number == n)
		{
			putchar('\n');
			return;
		}

		number++;
		
	}
}

#elif defined APP_3
// diamond of chars

int main(void)
{
	return 0;
}

#elif defined APP_4
// 3 different pi number calculation formulas
long double pow(long double x, int y);
long double factorial(int x);
double newton_pi(int k); 
double somayaji_pi(int n);
double bailey_borwein_plouffe_pi(int k);

int main(void)
{
	for (int i = 0; i < 20; i++)
	{
		printf("For newton_pi with k = %d is %.20f\n", i, newton_pi(i));
	}

	putchar('\n');

	for (int i = 0; i < 20; i++)
	{
		printf("For somayaji_pi with n = %d is %.20f\n", i, somayaji_pi(i));
	}

	putchar('\n');

	for (int i = 0; i < 20; i++)
	{
		printf("For bailey_borwein_plouffe_pi with k = %d is %.20f\n", i, bailey_borwein_plouffe_pi(i));
	}

	putchar('\n');

	printf("Best pi is \t\t\t%.20f\n", 3.141592653589793238462643383279);
	printf("For newton_pi with k = 50 is \t%.20f\n", newton_pi(50));
	printf("For somayaji_pi with n = 50 is \t%.20f\n", somayaji_pi(50));
	printf("For bailey_borwein_plouffe_pi with n = 50 is \t%.20f\n", bailey_borwein_plouffe_pi(50));
	

	return 0;
}

double newton_pi(int k)
{
	double pi = 0;

	for (int n = 0; n < k; n++)
	{
		pi += ( ( pow(2,n+1) * pow(factorial(n),2) ) * 1.) / ( factorial(2*n+1) * 1.);
	}

	return pi;
}

double somayaji_pi(int n)
{
	double pi = 3;
	int sign = 1;

	for (int i = 1; i < n+1; i++)
	{
		pi = pi + ( sign * ( 4.0 / ( pow(2*i+1,3) - (2*i+1) ) ) );
		sign *= -1;
	}
}

double bailey_borwein_plouffe_pi(int k)
{
	long double pi = 0;

	for (int n = 0; n < k; n++)
	{
		pi += ( ( ( 4. / (8*n+1) ) - ( 2. / (8*n+4) ) - ( 1. / (8*n+5) ) - ( 1. / (8*n+6) ) ) / pow(16, n) );
	}
}
#endif

long double pow(long double x, int y)
{
	long double  result = 1;

	for (int i = 0; i < y; i++)
		result *= x;

	return result;
}

long double factorial(int x)
{
	long double result = 1;

	for (; x > 1; x--)
		result *= x;

	return result;
}