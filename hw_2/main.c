/**
* @title	CSD C Programlama Kursu HW-2 Cevaplarý
* @author	Furkan Karagoz
* @date		27 / 8 / 2022
*
* @usage	"define" idafesini Q_1, Q_2, Q_3, Q_4 'den biri olarak degistirerek
*			farkli sorularýn cevaplarýný derleyip kosturabilirsiniz.
*
* @todo
*
*
* @structure
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

#define Q_1		// CHANGE THIS TO ACCESS TO THE OTHER ANSWERS @guide

#ifdef Q_1
// zig and zag with walls

int get_command(void);

void app_1(void);
int get_entry_1(int*);
void disp_pascal_triangle(int);

/*
void app_2(void);
int get_entry_2(int*, int*);
void app_3(void);
int get_entry_3(int*, int*);
void app_4(void);
int get_entry_4(int*, int*);
void app_5(void);
int get_entry_5(int*, int*);
void app_6(void);
int get_entry_6(int*, int*);
*/

void app_0(void);
int get_entry_0(int* foo, int* barr);
void app_2(void) {}
void app_3(void) {}
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
		case '0':
			app_0();
			/*
			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';
			*/
			break;
		case '1':
			app_1();
			break;
		case '2':
			app_2();
			break;
		case '3':
			app_2();
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
			printf("\nThis application draws zig zags with '*'s.\nJust enter width and height of the canvas.\n\nCommand list:\n\ta: Enters to the application.\n\tq: Quit from main application.\n\th: Calls help page.\n\n");
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

void app_0(void)
{
	int ch;

	printf("APPLICATION-0\nEnter 'h' for command help, 'q' to quit.\n\n");

	for (;;)
	{
		printf("APP-0>");

		ch = get_command();

		if (ch == '\n')	//only enter pressed. invalid entry.
			continue;

		switch (ch)
		{
		case 'r':
		{
			int width = -1, height = -1;
			get_entry_1(&width, &height);
			//void disp_pascal_triangle(width);
			// @attention is below still needed?
			while (getchar() != '\n')	// clear the plate
				;
			ch = '1';
			break;
		}
		case 'h':
			printf("\nThis application draws zig zags with '*'s.\nJust enter width and height of the canvas.\n\nCommand list:\n\tr: Runs the application.\n\tq: Quits to the main application.\n\th: Calls help page.\n\n");
			break;
		case 'q':
			printf("Aplication-0 closes...\n\n");
			goto APP_0_EXIT;
		default:
			printf("Invalid command!\n");
			break;
		}
	}

APP_0_EXIT:

	return;
}

int get_entry_0(int* width_, int* height_)
{
	printf("\nGet entry 0 called.\n");

	for (;;)
	{
		printf("Enter width : ");
		scanf_s("%d", width_);
		if (*width_ == -1)
		{
			printf("Invalid input.\n");
			break;
		}
		else if (*width_ < 1)
		{
			printf("Invalid number:%d\n", *width_);
			break;
		}
		else
		{
			printf("Enter height : ");
			scanf_s("%d", height_);
			if (*height_ == -1)
			{
				printf("Invalid input.\n");
				break;
			}
			else if (*height_ < 1)
			{
				printf("Invalid number:%d\n", *height_);
				break;
			}
			else
				return 1;
		}
	}
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

void disp_pascal_triangle(int n) // used by app-1
{
	putchar('\n');

	// code here
	printf("Drawing Pascal triangle for: %d\n", n);



	putchar('\n');
	return;
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
#endif