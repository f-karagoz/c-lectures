/**
* @title	CSD C Programlama Kursu HW-1 Cevaplarý
* @author	Furkan Karagoz
* @date		22 / 8 / 2022
* 
* @usage	"define" idafesini Q_1, Q_2, Q_3, Q_4 'den biri olarak degistirerek
*			farkli sorularýn cevaplarýný derleyip kosturabilirsiniz.
* 
* @todo		1) Define continuos application for Q3 [DONE]
*			2) Move prime calculation into main question functions for Q2 and Q3
*			3) Add exit promnt for infinite programs [PARTIALLY] (not in the 4th, problematic in 3rd)
*/


#include "stdio.h"

#define Q_2		// CHANGE THIS TO ACCESS TO THE OTHER ANSWERS @guide

int get_command()
{
	int ch;

	while ((ch = getchar()) == ' ' || ch == '\t')	// discard spaces and tabs and store the first character
		;

	if (ch != '\n')
		while (getchar() != '\n')	// clear the plate
			;

	return ch;
}


#ifdef TEMPLATE
int main()
{
	int ch;

	printf("APPLICATION X\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP_1_1>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case '1':
			break;
		case '2':
			break;
		case 'h':
			printf("Lorem ipsum... fill me with help texts...\n");
			break;
		case 'q':
			printf("Aplication closes...\n\n");
			goto EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

EXIT:

	return 0;
}
#endif

#ifdef Q_1
// zig and zag with walls

void app_1(void);

int main()
{
	int ch;

	printf("APPLICATION 1\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP_1_1>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case 'a':
			app_1();
			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';
			break;
		case 'h':
			printf("\nThis application draws zig zags with '*'s.\nJust enter width and height of the canvas.\n\nCommand list:\n\ta: Enters to the application.\n\tq: Quit from main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Aplication closes...\n\n");
			goto EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

EXIT:

	return 0;
}

void app_1(void)
{
	int width = -1, height = -1;

	for (;;)
	{
		printf("Enter width : ");
		scanf_s("%d", &width);
		if (width == -1)
		{
			printf("Invalid input.\n");
			break;
		}
		else if (width < 1)
		{
			printf("Invalid number:%d\n", width);
			break;
		}
		printf("Enter height : ");
		scanf_s("%d", &height);
		if (height == -1)
		{
			printf("Invalid input.\n");
			break;
		}
		else if (height < 1)
		{
			printf("Invalid number:%d\n", height);
			break;
		}

		putchar('\n');

		for (int i = 0, tracer = 0, direction = 0; i < height; i++)
		{
			for (int k = 0; k < width + 2; k++)
			{
				if (k == 0)
				{
					putchar('|');
					if (tracer == k)
					{
						direction = !direction;
						if (i == 0)
							tracer++;
						else
							tracer += 2;
					}
				}
				else if (k == width + 1)
				{
					putchar('|');
					if (tracer == k - 1)
					{
						direction = !direction;
						//tracer--;
					}
				}
				else
				{
					if (k != tracer)
						putchar(' ');
					else
						putchar('*');
				}
			}
			if (direction)
				tracer++;
			else
				tracer--;
			putchar('\n');
		}
		putchar('\n');
		return;
	}
}

#elif defined Q_2
// goldbach theorem

#include "math.h"

#define MAX_PRIME_COUNT 200		// Max nummber of prime numbers to be included into the prime array
#define DUPLET_ARRAY_SIZE 100	// Size of the Goldbach duplet array

/**
 * @brief Checks whether the given number is prime or not
 * @param val Number to be checked
 * @return	0 NOT prime
 *			1 prime
*/
int is_prime(int val);

/**
 * @brief Fills the given array with prime numbers
 * @param arr Pointer to an int array
*/
void get_prime_array(int* arr);

/**
 * @brief Fills out 2D dupplet array with given input values Goldbach combinations.
 * @details		Find the highest index for prime checking
 *					as larger prime numbers than the user input does not need to be checked
 *					For each element of the shrunked prime array check the second number
 *				If matching number found return them
 *
 *
 * @param value					Number to be checked
 * @param prime_arr_			Pointer to a prime number array
 * @param prime_arr_size_		Prime number array size
 * @param return_duplet_arr_	Dupplet array to be filled with prime number summation combinations
 * @param dupletCount_			Pointer to int for counting found duplets
 * @return -1	Given number is less than 4 ERROR
 *			0	No combination found UNEXPECTED
 *			1	Success
 *			2	Succes but not all combinations gathered. Duplet array size is not enough
*/
int goldbach(int value, int* prime_arr_, int prime_arr_size_, int return_duplet_arr_[2][DUPLET_ARRAY_SIZE], int* dupletCount_);

int main(void)
{
	int userInput;
	int dupletCount = 0;

	int primeArray[MAX_PRIME_COUNT];
	int dupletArray[2][DUPLET_ARRAY_SIZE];

	get_prime_array(primeArray);

	// DEBUG: print prime array
	/*
	for (int i = 0; i < MAX_PRIME_COUNT; i++)
		printf("%d ", primeArray[i]);
	printf("\n\n");
	*/
	for (;;)
	{
		printf("Enter a number to Goldback'ed : ");
		scanf_s("%d", &userInput);
		//if (userInput == '1')
		if (userInput < 0) // used for quitting with q. may not be valid for all systems! @attention
			break;
		else if (userInput < 2)
		{
			printf("Number %d is too low...\n", userInput);
			continue;
		}
		else if (userInput % 2 != 0)
		{
			printf("The number %d is not odd...\n", userInput);
			continue;
		}

		int retVal = goldbach(userInput, primeArray, MAX_PRIME_COUNT, dupletArray, &dupletCount);

		//printf("Goldbach() : %d\n", retVal); // DEBUG

		switch (retVal)
		{
		case -1:
			printf("ERROR: Given number %d is less than 4. Enter again.\n", userInput);
			break;
		case 0:
			printf("ERROR: Goldbach failed.\n");
			break;
		case 1:
			printf("Success: All prime sum duplets found for %d.\n", userInput);

			for (int i = 0; i < dupletCount; i++)
				printf("[ %d\t%d ]\n", dupletArray[0][i], dupletArray[1][i]);

			break;
		case 2:
			printf("Success: Some of the prime sum duplets found for %d.\n", userInput);

			for (int i = 0; i < dupletCount; i++)
				printf("[ %d\t%d ]\n", dupletArray[0][i], dupletArray[1][i]);

			break;
		}
	}
	
	return 0;
}

void get_prime_array(int* arr)
{
	for (int i = 2, primeFound = 0; primeFound < MAX_PRIME_COUNT; i++)
	{
		if (is_prime(i))
		{
			arr[primeFound] = i;
			primeFound++;
		}
	}
}

int is_prime(int val)
{
	double val_sqrt;

	// Even numbers are not prime except 2
	if (val % 2 == 0)
		return val == 2; // returns 1 if number is 2

	val_sqrt = sqrt(val);
	for (int i = 3; i <= val_sqrt; i += 2)
		if (val % i == 0)
			return 0;

	return 1;
}

int goldbach(int value, int* prime_arr_, int prime_arr_size_, int return_duplet_arr_[2][DUPLET_ARRAY_SIZE], int* duplet_count)
{
	int min_arr_size = prime_arr_size_;
	*duplet_count = 0;

	if (value < 4)
		return -1;			// Value is too small

	// top index calculation, no need to check larger prime numbers
	for (int i = 0; i < prime_arr_size_; i++)
	{
		if (value < prime_arr_[i])
		{
			min_arr_size = i;
			break;
		}
	}

	for (int i = 0; i < min_arr_size; i++)
	{
		for (int j = 0; j < min_arr_size; j++)
		{
			if (prime_arr_[i] + prime_arr_[j] == value) // Found Goldbach
			{
				// record it
				return_duplet_arr_[0][*duplet_count] = prime_arr_[i];
				return_duplet_arr_[1][*duplet_count] = prime_arr_[j];

				(* duplet_count)++;

				if (*duplet_count == DUPLET_ARRAY_SIZE)
					return 2;
			}
		}
	}
	if (*duplet_count != 0)
		return 1;
	else
		return 0;
}



#elif defined Q_3
// prime dividors of a number
#include "math.h"

#define MAX_PRIME_COUNT 200		// Max nummber of prime numbers to be included into the prime array
#define MAX_P_D_ARRAY_SIZE 100	// Max size of prime dividor array

/**
 * @brief Checks whether the given number is prime or not
 * @param val Number to be checked
 * @return	0 NOT prime
 *			1 prime
*/
int is_prime(int val);

/**
 * @brief Fills the given array with prime numbers
 * @param arr Pointer to an int array
*/
void get_prime_array(int* arr);

int main(void)
{
	int inputVal = -1;
	int primeDividorIndex = 0;
	int primeArray[MAX_PRIME_COUNT];
	int primeDividors[MAX_P_D_ARRAY_SIZE];

	get_prime_array(primeArray);

	printf("PRIME DIVIDOR CALCULATOR!\n\n");

	for (;;)
	{
		printf("Enter a number: ");
		scanf_s("%d", &inputVal);
		if (inputVal < 2) // used for quitting with q. may not be valid for all systems! @attention
			break;
		printf("Prime dividors of %d are: ", inputVal);

		for (int i = 0; i < MAX_PRIME_COUNT && inputVal != 0; )
		{
			if (inputVal % primeArray[i] == 0)
			{
				inputVal /= primeArray[i];
				primeDividors[primeDividorIndex] = primeArray[i];
				primeDividorIndex++;
			}
			else
				i++;
		}

		for (int i = 0; i < primeDividorIndex; i++)
		{
			printf("%d ", primeDividors[i]);
		}
		printf("\n");
	}

	return 0;
}

void get_prime_array(int* arr)
{
	for (int i = 2, primeFound = 0; primeFound < MAX_PRIME_COUNT; i++)
	{
		if (is_prime(i))
		{
			arr[primeFound] = i;
			primeFound++;
		}
	}
}

int is_prime(int val)
{
	double val_sqrt;

	// Even numbers are not prime except 2
	if (val % 2 == 0)
		return val == 2; // returns 1 if number is 2

	val_sqrt = sqrt(val);
	for (int i = 3; i <= val_sqrt; i += 2)
		if (val % i == 0)
			return 0;

	return 1;
}

#elif defined Q_4
// diamond printer (n = 5)
//     *
//    ***
//   *****
//  *******
// *********
//  *******
//   *****
//    ***
//     *
//
// n = 3
//   *
//  ***
// *****
//  ***
//   *
// 
// n = 2
//  *
// ***
//  *
// 
// start at index 0
// ascend until n-1
// full line at n
// descend till 2*n-1

// N = 4
// spaces:	3	2	1	0	1	2	3
// stars:	1	3	5	7	5	3	1

int main(void)
{
	int n = -1;

	printf("DIAMOND DRAWER!\n\n");

	for (;;)
	{
		printf("Enter diamond apex number : ");
		scanf_s("%d", &n);
		if (n < 1)
		{
			printf("\nInvalid number %d!\n",n);
			n = -5;
			continue;
		}
		else
		{
			putchar('\n');

			for (int i = 0; i < 2 * n - 1; ++i)
			{

				if (i < n - 1)
				{
					for (int k = 0; k < n - i - 1; ++k)
						putchar(' ');
					for (int j = 0; j < 2 * i + 1; j++)
						putchar('*');
				}
				else if (i == n - 1)
				{
					for (int j = 0; j < 2 * n - 1; j++)
						putchar('*');
				}
				else
				{
					for (int k = 0; k < i - n + 1; ++k)
						putchar(' ');
					for (int j = 0; j < 4 * n - 1 - 2 * i - 2; j++)
						putchar('*');
				}

				putchar('\n');
			}
			n = 0; // reset the val
			putchar('\n');
		}
	}

	return 0;
}

#endif