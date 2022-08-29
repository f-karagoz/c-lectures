/**
* @title	CSD C Programlama Kursu HW-2 Cevaplari
* @author	Furkan Karagoz
* @date		27 / 8 / 2022
*
* @usage	Run the code and follow the on screen guides.
*
* @todo		In App-1 n = 6+ is not perfect triangle due to double digit numbers
*				and larger values fail due to high numbers.
*			For App-4 package the prime dividor alogrith as a function. Then use it for gcd() and lcm()
*			bla
*			bla
*			bla
* 
*
*
* @code_structure
* 
*	MAIN
*	|
*	|-------------------------------|-------------------|-------------------|-------------------|-------------------|
*	app_1							app_2				app_3				app_4				app_5				app_6
*	- get_entry_1					- get_entry_2		- get_entry_3		- get_entry_4		- get_entry_5		- get_entry_6
*	-- display_pascal_triangle		-- disp_shape		- print_shape		-- sum_digit		-- gcd				-- intrew
*	-- factorial																				-- lcm
*	-- combination
*				
*/


#include "stdio.h"

int get_command(void);

void app_1(void);
int get_entry_1(int*);
void disp_pascal_triangle(int);

void app_2(void);
int get_entry_2(int*);
void disp_shape(int n);

void app_3(void);
int get_entry_3(int*);
void print_shape(int n);

void app_4(void);
int get_entry_4(unsigned long long*);
int sum_digit(unsigned long long val);

void app_5(void);
int get_entry_5(unsigned*, unsigned*);
unsigned gcd(unsigned a, unsigned b);
unsigned lcm(unsigned a, unsigned b);

void app_6(void);
int get_entry_6(int*);
int intrew(int val);

/****************************************************************
 *							MAIN								*
*****************************************************************/

int main()
{
	int ch;

	printf("HW-2\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("HW-2>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case '1':
			app_1();
			break;
		case '2':
			app_2();
			break;
		case '3':
			app_3();
			break;
		case '4':
			app_4();
			break;
		case '5':
			app_5();
			break;
		case '6':
			app_6();
			break;
		case 'h':
			printf("\nThis application is the interface for HW-2 applications.\n\nCommand list:\n\t1: Enters to the application-1.\n\t1: Enters to the application-2.\n\t1: Enters to the application-2.\n\t3: Enters to the application-3.\n\t4: Enters to the application-4.\n\t5: Enters to the application-5.\n\t6: Enters to the application-6.\n\tq: Quit from main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Program closes...\n\n");
			goto MAIN_EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

MAIN_EXIT:

	return 0;
}

/****************************************************************
 *							APP - 1								*
*****************************************************************/

void app_1(void)
{
	int ch;

	printf("APPLICATION-1\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP-1>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case 'r':
		{
			int n = -1;
			if ( get_entry_1(&n) )
				disp_pascal_triangle(n);

			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';

			break;
		}
		case 'h':
			printf("\nThis application draws Pascal triangle '*'s.\nEnter number of the Pascal triangle you wish to be drawed.\n\nCommand list:\n\tr: Runs the application.\n\tq: Quits to the main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Aplication-1 closes...\n\n");
			goto APP_1_EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

APP_1_EXIT:

	return;
}

int get_entry_1(int* n_)
{
	//printf("\nGet entry called.\n");

	for (;;)
	{
		printf("Enter n : ");
		scanf_s("%d", n_);
		if (*n_ == -1)
		{
			printf("Invalid input.\n");
			return 0;
		}
		else if (*n_ < 1)
		{
			printf("Invalid number:%d\n", *n_);
			return 0;
		}
		else
			return 1;
	}
}


/*
*  n=5
*     1
*    1 1
*   1 2 1
*  1 3 3 1
* 1 4 6 4 1
* 
* 
*/

long long int factorial(int x_)
{
	//printf("Factorial of %d is", x_);
	int result = 1;

	for (; x_ > 1; x_--)
		result *= x_;
	//printf(" %d\n", result);
	return result;
}

int combination(int n_, int r_)
{
	return (factorial(n_) / (factorial(r_) * factorial(n_ - r_)));
}

void disp_pascal_triangle(int n) // used by app-1
{
	putchar('\n');

	// code here
	printf("Drawing Pascal triangle for: %d\n\n", n);

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
			putchar(' ');

		for (int j = 0; j < i + 1; j++)
			printf(" %d", combination(i, j));
		putchar('\n');
	}

	putchar('\n');
	return;
}

/****************************************************************
 *							APP - 2								*
*****************************************************************/

void app_2(void)
{
	int ch;

	printf("APPLICATION-2\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP-2>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case 'r':
		{
			int n = -1;
			if (get_entry_2(&n))
				disp_shape(n);

			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';

			break;
		}
		case 'h':
			printf("\nThis application draws an hourglass with numbers '*'s.\nEnter the height of the one part of the hourglass.\n\nCommand list:\n\tr: Runs the application.\n\tq: Quits to the main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Aplication-2 closes...\n\n");
			goto APP_2_EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

APP_2_EXIT:

	return;
}

int get_entry_2(int* n_)
{
	//printf("\nGet entry called.\n");

	for (;;)
	{
		printf("Enter n : ");
		scanf_s("%d", n_);
		if (*n_ == -1)
		{
			printf("Invalid input.\n");
			return 0;
		}
		else if (*n_ < 0)
		{
			printf("Invalid number:%d\n", *n_);
			return 0;
		}
		else
			return 1;
	}
}

/*
* 1 2 3 4 5
*  2 3 4 5
*   3 4 5
*    4 5
*     5
*    4 5
*   3 4 5
*  2 3 4 5
* 1 2 3 4 5
* 
*/

void disp_shape(int n)
{
	putchar('\n');

	for (int i = 0; i < n; i++) // first part
	{
		for (int j = 0; j < i; j++) // initial spaces
			putchar(' ');

		for (int j = i; j < n; j++)
			printf("%d ", j + 1);
		putchar('\n');
	}
	
	for (int i = 1; i < n; i++) // second part
	{
		for (int j = i; j < n-1; j++) // initial spaces
			putchar(' ');

		for (int j = n-i; j < n+1; j++)
			printf("%d ", j);
		putchar('\n');
	}

	putchar('\n');
}

/****************************************************************
 *							APP - 3								*
*****************************************************************/

void app_3(void)
{
	int ch;

	printf("APPLICATION-3\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP-3>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case 'r':
		{
			int n = -1;
			if (get_entry_3(&n))
				print_shape(n);

			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';

			break;
		}
		case 'h':
			printf("\nThis application draws a reverse diamond shape with '*'s.\nEnter the height of the one part of the diamond.\n\nCommand list:\n\tr: Runs the application.\n\tq: Quits to the main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Aplication-3 closes...\n\n");
			goto APP_3_EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

APP_3_EXIT:

	return;
}

int get_entry_3(int* n_)
{
	//printf("\nGet entry called.\n");

	for (;;)
	{
		printf("Enter n : ");
		scanf_s("%d", n_);
		if (*n_ == -1)
		{
			printf("Invalid input.\n");
			return 0;
		}
		else if (*n_ < 0)
		{
			printf("Invalid number:%d\n", *n_);
			return 0;
		}
		else
			return 1;
	}
}

void print_shape(int n)
{
	putchar('\n');

	for (int i = 0; i < 2 * n; ++i)
	{
		if (i < n) // first half
		{
			for (int j = 0; j < n - i; j++)
				putchar('*');
			for (int j = 0; j < 2*i; j++)
				putchar(' ');
			for (int j = 0; j < n - i; j++)
				putchar('*');
		}
		else
		{
			for (int j = 0; j < i - n + 1; j++)
				putchar('*');
			for (int j = 0; j < (n-1)*2 - 2*(i-n); j++)
				putchar(' ');
			for (int j = 0; j < i - n + 1; j++)
				putchar('*');
		}

		putchar('\n'); // line ended
	}

	n = 0; // reset the val
	putchar('\n');
}

/****************************************************************
 *							APP - 4								*
*****************************************************************/

void app_4(void)
{
	int ch;

	printf("APPLICATION-4\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP-4>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case 'r':
		{
			long long unsigned val = -1;
			if (get_entry_4(&val))
				printf("Sum of digits is: % d\n", sum_digit(val) );

			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';

			break;
		}
		case 'h':
			printf("\nThis application calculates the sum of the digits of the numbered entered.\nEnter a number to be calculated.\n\nCommand list:\n\tr: Runs the application.\n\tq: Quits to the main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Aplication-4 closes...\n\n");
			goto APP_4_EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

APP_4_EXIT:

	return;
}

int get_entry_4(unsigned long long* val_)
{
	//printf("\nGet entry called.\n");

	for (;;)
	{
		printf("Enter a number : ");
		scanf_s("%llu", val_);
		if (*val_ == -1)
		{
			printf("Invalid input.\n");
			return 0;
		}
		else if (*val_ < 0)
		{
			printf("Invalid number:%llu\n", *val_);
			return 0;
		}
		else
			return 1;
	}
}

int sum_digit(unsigned long long val)
{
	//printf("Sum digit called for %llu\n", val);

	int retVal = 0;

	while ((val / 10) > 0) // check if we are on the last digit
	{
		retVal += (val % 10);
		val /= 10;
	}


	retVal += (val % 10); // also sum the last digit


	return retVal; // will be removed
}

/****************************************************************
 *							APP - 5								*
*****************************************************************/

void app_5(void)
{
	int ch;

	printf("APPLICATION-5\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP-5>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case 'r':
		{
			unsigned a = -1, b = -1;
			if (get_entry_5(&a, &b))
			{
				printf("GCD of %u and %u is: %d\n", a, b, gcd(a, b));
				printf("LCM of %u and %u is: %d\n", a, b, lcm(a, b));
			}
			else
				__noop;

			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';

			break;
		}
		case 'h':
			printf("\nThis application calculates the GCD and LCM of the entered numbers.\nEnter a numbers to be calculated.\n\nCommand list:\n\tr: Runs the application.\n\tq: Quits to the main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Aplication-5 closes...\n\n");
			goto APP_5_EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

APP_5_EXIT:

	return;
}
int get_entry_5(unsigned* a_, unsigned* b_)
{
	//printf("\nGet entry called.\n");

	for (;;)
	{
		printf("Enter first number : ");
		scanf_s("%u", a_);
		if (*a_ == -1)
		{
			printf("Invalid input.\n");
			return 0;
		}
		else if (*a_ < 2)
		{
			printf("Invalid number:%u\n", *a_);
			return 0;
		}
		else
		{
			printf("Enter second number : ");
			scanf_s("%u", b_);
			if (*b_ == -1)
			{
				printf("Invalid input.\n");
				return 0;
			}
			else if (*b_ < 2)
			{
				printf("Invalid number:%u\n", *b_);
				return 0;
			}
			else
				return 1;
		}	
	}
}

unsigned gcd(unsigned a, unsigned b)
{
	int R;
	while ((a % b) > 0) {
		R = a % b;
		a = b;
		b = R;
	}
	return b;
}
unsigned lcm(unsigned a, unsigned b)
{
	return ( a * b / gcd(a, b) );
}

/****************************************************************
 *							APP - 6								*
*****************************************************************/

void app_6(void)
{
	int ch;

	printf("APPLICATION-6\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP-6>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case 'r':
		{
			int n = -1;
			if (get_entry_6(&n))
				printf("Reversed: %d\n", intrew(n));

			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';

			break;
		}
		case 'h':
			printf("\nThis application reverses the digits of the entered number\nwhile preserving the sign of the number.\n\nCommand list:\n\tr: Runs the application.\n\tq: Quits to the main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Aplication-6 closes...\n\n");
			goto APP_6_EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

APP_6_EXIT:

	return;
}

int get_entry_6(int* n_)
{
	//printf("\nGet entry called.\n");

	for (;;)
	{
		printf("Enter a number : ");
		scanf_s("%d", n_);
		/*
		if (*n_ == -1)
		{
			printf("Invalid input.\n");
			return 0;
		}
		else if (*n_ < 0)
		{
			printf("Invalid number:%d\n", *n_);
			return 0;
		}
		else
			return 1;
			*/
		return 1;
	}
}

int intrew(int val)
{
	int sign = 0;
	int reversed[100];
	int result = 0;

	(val < 0) ? (sign = -1) : (sign = 1);

	val *= sign;	// makes val positive

	/*
	* 1234
	* reversed[] = {4,3,2}
	* 
	*/
	int i = 0;
	for (; (val / 10) != 0; i++)	// will fail if only one digit left
	{
		reversed[i] = (val % 10);
		val /= 10;
	}
	reversed[i] = (val % 10); // reversed[] = {4,3,2,1}

	for (int j = 0; j < i; j++)
	{
		result += reversed[j];
		result *= 10;
	}
	result += reversed[i];

	result *= sign;

	return result; // will be changed
}


int get_command(void) // used by all
{
	int ch;

	while ((ch = getchar()) == ' ' || ch == '\t')	// discard spaces and tabs and store the first character
		;

	if (ch != '\n')
		while (getchar() != '\n')	// clear the plate
			;

	return ch;
}