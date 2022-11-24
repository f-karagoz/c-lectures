#include <stdio.h>
#include <string.h>

#define APP_1

#ifdef APP_1
#define BUFFER_SIZE			100
char* num2text(unsigned long long number, char* buf, size_t bufsize);

int main(void)
{
	printf("APP-1\n");

	char buffer[BUFFER_SIZE] = "";
	//strcpy_s(buffer, BUFFER_SIZE, "tested" );

	//strcat(buffer, "testt");

	num2text(123, buffer, BUFFER_SIZE);

	puts(buffer);

	char test[BUFFER_SIZE] = "";
	int test_char_count = sprintf(test, "%llu", 18446744073709551615);
	puts(test);
	printf("%d", test_char_count);

	return 0;
}

char* num2text(unsigned long long number, char* buf, size_t bufsize)
{
	char* ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char* tens[] = { "", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	char* larges[] = { "", "thousend", "million", "billion", "trillion", "quadrillion", "quintrillion" };

	if (number == 0)
		strcpy(buf, "zero");
	else
	{
		char strNumber[20];
		int nDigit = sprintf(strNumber, "%llu", number);
		printf("Entered n: %s\n", strNumber);				// debug
		printf("nDigit: %d\n", nDigit);						// debug

		int index = 0;
		int offset = nDigit % 3;
		int nThousends = nDigit / 3;

		// loop here
		for (int i = 0; i < nDigit; ++i)
		{
			int foo = i % 3; // impelement offste here
			switch (foo)
			{
			case 0:
				index += sprintf(buf + index, "%s", ones[strNumber[i] - '0']);
				index += sprintf(buf + index, " hundred");
				break;

			case 1:
				index += sprintf(buf + index, "%s", tens[strNumber[i] - '0']);
				break;

			case 2:
				index += sprintf(buf + index, "%s", ones[strNumber[i] - '0']);
				break;
			}

			nN
			index += sprintf(buf + index, "%s", larges[ ]);

			if (i + 1 != nDigit)
				index += sprintf(buf + index, " ");
			

			
			

		}
		
		/*
		while (number != 0)
		{

			if (number > 99)
			{
				strcat(buf, ones[number / 100]);
				strcat(buf, " hundred");
				number %= 100;
			}
			else if (number > 9)
			{
				strcat(buf, " ");
				strcat(buf, tens[number / 10]);
				number %= 10;
			}
			else
			{
				strcat(buf, " ");
				strcat(buf, ones[number]);
				number = 0;
			}

		}
		*/
	}

	return buf;
}

#elif defined APP_2

int main(void)
{
	printf("App - 2\n");
	return 0;
}

#elif defined APP_3

int main(void)
{
	printf("App - 3\n");
	return 0;
}

#endif