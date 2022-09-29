/*
* Lecture 33
* 29 / 9 / 2022
* Kaan Aslan
* 
* Sorting Algorihms
* 
*/

#include "stdio.h"

/*
* APP_1 : Buble sort
* APP_2 : Buble sort (optimized-1)
* APP_3 : Buble sort (optimized-2)
* APP_4 : Selection sort
*/

#define APP_1

#ifdef APP_1
// Buble Sort
#define SIZE		10

int main(void)
{
	int a[SIZE] = { 23, 12, 76, 45, 23, 65, 11, 98, 42, 81 };
	int temp;

	for (int i = 0; i < SIZE - 1; i++)
		for (int k = 0; k < SIZE - 1 - i; k++)
			if ( a[k + 1] < a[k])
			{
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}

	for (int i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

#elif defined APP_2
// Buble sort (optimized)
#define SIZE		10
#define TRUE		1
#define FALSE		0

int main(void)
{
	int a[SIZE] = { 23, 12, 76, 45, 23, 65, 11, 98, 42, 81 };
	int temp;
	int replaced_flag;

	for (int i = 0; i < SIZE - 1; i++)
	{
		replaced_flag = FALSE;
		for (int k = 0; k < SIZE - 1 - i; k++)
			if (a[k + 1] < a[k])
			{
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
				replaced_flag = TRUE;
			}
		if (!replaced_flag)
			break;
	}

	for (int i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

#elif defined APP_3
// Buble sort (optimized-2)
#define SIZE		10
#define TRUE		1
#define FALSE		0

int main(void)
{
	int a[SIZE] = { 23, 12, 76, 45, 23, 65, 11, 98, 42, 81 };
	int temp;
	int replaced_flag;
	int n = SIZE - 1;

	do
	{
		replaced_flag = FALSE;

		for (int i = 0; i < n; i++)
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				replaced_flag = TRUE;
			}
		n--;
	}
	while (replaced_flag);

	for (int i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}

#elif defined APP_4
// selection sort
#define SIZE		10

int main(void)
{
	int a[SIZE] = { 23, 12, 76, 45, 23, 65, 11, 98, 42, 81 };
	int min, min_index;

	for (int i = 0; i < SIZE - 1; i++)
	{
		min = a[i];
		min_index = i;
		for (int k = i + 1; k < SIZE; k++)
		{
			if (a[k] < min)
			{
				min = a[k];
				min_index = k;
			}
		}
		a[min_index] = a[i];
		a[i] = min;
	}

	for (int i = 0; i < SIZE; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

#elif defined APP_5
int main(void)
{
	return 0;
}
#endif