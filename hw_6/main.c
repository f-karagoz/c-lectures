#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

#define APP_1

#ifdef APP_1
#include <string.h>
#define BUFFER_SIZE			100

char* num2text(unsigned long long number, char* buf, size_t bufsize);

int main(void)
{
	printf("APP-1\n");

	char buffer[BUFFER_SIZE] = "";
	//strcpy_s(buffer, BUFFER_SIZE, "tested" );

	//strcat(buffer, "testt");

	num2text(999, buffer, BUFFER_SIZE );

	puts(buffer);

	return 0;
}

char* num2text(unsigned long long number, char* buf, size_t bufsize)
{
	char* ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char* tens[] = { "", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	char* hundreds[] = { "", "hundred", "thousend", "million", "billion", "trillion", "quadrillion", "quintrillion" };

	if (number == 0)
		strcpy_s(buf, bufsize, "zero");
	else
	{
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
	}

	return buf;
}

#elif defined APP_2
int main(void)
{
	printf("APP-2\n");
	return 0;
}

#elif defined APP_3
int main(void)
{
	printf("APP-3\n");
	return 0;
}

#endif