#include "stdio.h"

#define APP_6
#ifdef APP_1 || defined APP_2
void clear_stdin(void)
{
	while (getchar() != '\n')
		;
}
#endif

#ifdef APP_1
int main(void)
{
	int ch;

	for (int i = 0; i < 10; ++i)
	{
		for (int k = 0; k < 10; ++k)
		{

		}
	}
	return 0;
}

#elif defined APP_2
int main(void)
{
	for (;;)
	{
		// Code...
	}
	return 0;
}

#elif defined APP_3

int get_command(void)
{
	int ch = 0;

	while ((ch = getchar()) == ' ' || ch == '\t')
		;
	if (ch != '\n')
		while (getchar() != '\n')
			;
	return ch;
}

int main(void)
{
	static int ch;

	for (;;)
	{
		printf("CSD>");
		
		ch = get_command();

		if (ch != '\n')
		{
			if (ch == 'q')
				break;
			else if (ch == 'r')
				printf("remove command executes...\n");
			else if (ch == 'c')
				printf("copy command executes...\n");
			else if (ch == 'd')
				printf("dir command executes...\n");
			else if (ch == 'm')
				printf("move command executes...\n");
			else
				printf("invalid command : %c\n",ch);
		}
	}

	return 0;
}

#elif defined APP_4
// continue
int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		if (i % 2 == 0)
			continue;
		printf("%d\n", i);
	}

	return 0;
}

#elif defined APP_5
int get_command(void)
{
	int ch = 0;

	while ((ch = getchar()) == ' ' || ch == '\t')
		;
	if (ch != '\n')
		while (getchar() != '\n')
			;
	return ch;
}

int main(void)
{
	static int ch;

	for (;;)
	{
		printf("CSD>");

		ch = get_command();

		if (ch == '\n')
			continue;

		if (ch == 'q')
			break;
		else if (ch == 'r')
			printf("remove command executes...\n");
		else if (ch == 'c')
			printf("copy command executes...\n");
		else if (ch == 'd')
			printf("dir command executes...\n");
		else if (ch == 'm')
			printf("move command executes...\n");
		else
			printf("invalid command : %c\n", ch);
	}

	return 0;
}
#elif defined APP_6
// constant expressions
// 3
// 3 + 5
// 2 + 5 * 3
// 1 + 2 + 3 + 4
// constant expressions' results can be calculated at the compiler. This is called "constant folding".
// 
// switch case

int main(void)
{

	int val = 0;

	printf("Bir deger giriniz : ");
	scanf_s("%d", &val);

	switch (val)
	{
	case 1:
		printf("bir\n");
		break;
	case 2:
		printf("iki\n");
		break;
	case 3:
		printf("uc\n");
		break;
	case 4:
		printf("dort\n");
		break;
	case 5:
		printf("bes\n");
		break;
	default:
		printf("hicbiri\n");
		break;
	}

	return 0;
}
#elif defined APP_7
// nesnelerin ömürleri konusunda stack ve heap konusulacak
int main(void)
{
	return 0;
}
#elif defined APP_8
int main(void)
{
	return 0;
}
#elif defined APP_9
int main(void)
{
	return 0;
}
#endif