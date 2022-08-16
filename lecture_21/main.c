/**
* @author	Furkan Karagoz
* @date		21.8.2022
* 
* 
* 
*/

#include "stdio.h"
#include "math.h"

#define APP_1

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
int main(void)
{
	return 0;
}

#elif defined APP_3
int main(void)
{
	return 0;
}

#elif defined APP_4
int main(void)
{
	return 0;
}
#endif