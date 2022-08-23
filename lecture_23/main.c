#include "stdio.h"

#define APP_3

#ifdef APP_1

// get char returns int. if fails return -1.
// If it was returning char we couldnt get a fail response out of it
int get_command(void)
{
	int ch;

	while ((ch = getchar()) == ' ' || ch == '\t')
		;

	if (ch != '\n')
		while (getchar() != '\n')
			;

	return ch;
}

int main()
{
	int ch;

	for (;;)
	{
		printf("CSD>");

		ch = get_command();

		if (ch == '\n')
			continue;
		if (ch == 'q')
			break;

		switch (ch)
		{
		case 'e':			// fallthrough
		case 'r':
			printf("Remove command executes...\n");
			break;
		case 'c':
			printf("Copy command executes...\n");
			break;
		case 'd':
			printf("Dir command executes...\n");
			break;
		case 'm':
			printf("Move command executes...\n");
			break;
		default:
			printf("Invalid command: %c\n", ch);
			break;
		}

	}

	return 0;
}

#elif defined APP_2

// cases can be nested in C, not in java
int main()
{
	int a, b;

	printf("Bir deger giriniz: ");
	scanf_s("%d", &a);

	switch (a)
	{
	case 1:
		printf("bir\n");
		printf("Bir deger daha giriniz: ");
		scanf_s("%d", &b);
		if (b > 0)
		{
			case 2:
				printf("Islemler devam ediyor...\n");
				break;
		}
		break;
	case 3:
		printf("uc\n");
		break;
	default:
		printf("deafult\n");
		break;
	}

	return 0;
}

#elif defined APP_3

// std-C11 6.8.4.2 6.8.1 case statement
// go to miti
// does not have any functionality flaw but code is harder to read with goto statements
// pg. 153 EXAMPLE 2

int main()
{
	int i = 0;

REPEAT:
	printf("%d \n", i);
	++i;
	if (i < 10)
		goto REPEAT;

	return 0;
}

#elif defined APP_4

int main()
{
	return 0;
}

#endif

