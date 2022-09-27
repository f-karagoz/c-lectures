#include "stdio.h"

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