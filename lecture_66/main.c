#include <stdio.h>

#define APP5

#ifdef APP1
/* Multi-dimensional arrays */
// arr[][]
// first bracket declares the array, second bracket taken as element
// int a[3][4] is an integer array with 3 elements
// each element is an int array with 4 elements
// 
// Memory allocation of a[3][2]: (is sequential)
// 
// a[0][0]
// a[0][1]
// a[1][0]
// a[1][1]
// a[2][0]
// a[2][1]
// 
// ...end...


int main(void)
{
	int a[3][2];

	a[0][0] = 10;
	a[0][1] = 20;
	a[1][0] = 30;
	a[1][1] = 40;
	a[2][0] = 50;
	a[2][1] = 60;

	for (int i = 0; i < 3; ++i)
	{
		for (int k = 0; k < 2; ++k)
			printf("%d ", a[i][k]);
		printf("\n");
	}

	return 0;
}

#elif defined APP2
/* MDA initial value */

int main(void)
{
	int a[3][2] = { {10,20}, {30,40}, {50,60} };

	for (int i = 0; i < 3; ++i)
	{
		for (int k = 0; k < 2; ++k)
			printf("%d ", a[i][k]);
		printf("\n");
	}

	return 0;
}

#elif defined APP3

int main(void)
{
	int a[3][2][3] =
	{
		{ {1,2,3}, {4,5,6} },
		{ {7,8,9}, {10,11,12} },
		{ {13,14,15}, {16,17,18} }
	};

	printf("~~~~~~~~\n");
	for (int h = 0; h < 3; ++h)
	{
		for (int i = 0; i < 2; ++i)
		{
			for (int k = 0; k < 3; ++k)
				printf("%2d ", a[h][i][k]);
			printf("\n");
		}
		printf("~~~~~~~~\n");
	}
	return 0;
}

#elif defined APP4
/* pointer to array */

int main(void)
{
	int a[5];
	int(*pai)[5];
	int pi;

	pai = &a;		/* valid */
	//pi = a;			/* invalid */
	//pi = &a;		/* invalid */


	return 0;
}

#elif defined APP5
/* pointer to multi-dimensional arrays */

int main(void)
{
	int a[3][2] = { {1, 2}, { 3,4 }, { 5,6 }};
	int(*pai)[2];

	pai = a;

	printf("%d ", pai[0][0]);
	printf("%d ", pai[0][1]);

	/*
	for (int i = 0; i < 3; ++i)
	{
		for (int k = 0; k < 2; ++k)
			printf("%d ", pai[i][k]);
		printf("\n");
	}
	*/
	return 0;
}

#elif defined APP6

int main(void)
{
	return 0;
}

#endif