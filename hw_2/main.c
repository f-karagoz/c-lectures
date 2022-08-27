/**
* @title	CSD C Programlama Kursu HW-2 Cevaplari
* @author	Furkan Karagoz
* @date		27 / 8 / 2022
*
* @usage	Run the code and follow the on screen guides.
*
* @todo		In App-1 n = 6+ is not perfect triangle due to double digit numbers
*				and larger values fail due to high numbers.
*			bla
*			bla
*			bla
* 
*
*
* @code_structure
*									MAIN
*									|
*	|-------------------------------|-------------------...------|
*	app_1							app_2				...		app_6
*	- get_entry_1					- get_entry_2		...		- get_entry_6
*	-- display_pascal_triangle		-- xxx				...		-- xxx
*				
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
/*
void app_4(void);
int get_entry_4(int*, int*);
int sum_digit(unsigned long long val);


void app_5(void);
int get_entry_5(int*, int*);
unsigned gcd(unsigned a, unsigned b);
unsigned lcm(unsigned a, unsigned b);

void app_6(void);
int get_entry_6(int*, int*);
int intrew(int val);
*/

void app_4(void) {}
void app_5(void) {}
void app_6(void) {}

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
			app_2();
			break;
		case '5':
			app_2();
			break;
		case '6':
			app_2();
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