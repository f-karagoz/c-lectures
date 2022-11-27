#include <stdio.h>
#include <string.h>

#define APP_1

#ifdef APP_1
// Function that converts the given number to text
// Known bugs: "bir bin"

#define BUFFER_SIZE			100
char* num2text(unsigned long long number, char* buf, size_t bufsize);

int main(void)
{
	unsigned long long number = 0;
	char buffer[BUFFER_SIZE] = "";
	while (1)
	{
		printf("Enter a number: ");
		scanf("%llu", &number);

		num2text(number, buffer, BUFFER_SIZE);

		puts(buffer);
	}

	return 0;
}

char* num2text(unsigned long long number, char* buf, size_t bufsize)
{
	char* ones[] = { "", "bir", "iki", "uc", "dort", "bes", "alti", "yedi", "sekiz", "dokuz" };
	char* tens[] = { "", "on", "yirmi", "otuz", "kirk", "elli", "altmis", "yetmis", "seksen", "doksan" };
	char* thousends[] = { "", "bin", "milyon", "milyar", "trilyon", "kuantilyon", "kuintilyon" };

	if (number == 0)
		strcpy(buf, "sifir");
	else
	{
		char strNumber[20];
		int nDigit = sprintf(strNumber, "%llu", number);
		int indexBuf = 0;
		int indexDigit = 0;
		int offset = nDigit % 3;
		int switcher;
		int nThousends = offset == 0 ? nDigit / 3 - 1 : nDigit / 3;

		// loop
		for (; indexDigit < nDigit; ++indexDigit)
		{
			switcher = (indexDigit - offset) % 3;

			switch ( switcher < 0 ? switcher + 3 : switcher)
			{
			case 0:
				if (strNumber[indexDigit] != '1')
				{
					if (strNumber[indexDigit] != '0' && indexDigit != 0)
						indexBuf += sprintf(buf + indexBuf, " ");
					indexBuf += sprintf(buf + indexBuf, "%s", ones[strNumber[indexDigit] - '0']);
				}
					
				if (strNumber[indexDigit] != '0')
				{
					if (indexDigit != 0)
						indexBuf += sprintf(buf + indexBuf, " ");
					indexBuf += sprintf(buf + indexBuf, "%s", "yuz");
				}
					
				break;
				
			case 1:
				if (strNumber[indexDigit] != '0' && indexDigit != 0)
					indexBuf += sprintf(buf + indexBuf, " ");
				indexBuf += sprintf(buf + indexBuf, "%s", tens[strNumber[indexDigit] - '0']);
				break;

			case 2:
				if (strNumber[indexDigit] != '0' && indexDigit != 0)
					indexBuf += sprintf(buf + indexBuf, " ");
				indexBuf += sprintf(buf + indexBuf, "%s", ones[strNumber[indexDigit] - '0']);

				if (nThousends != 0)
				{
					int printThousends = 0;
					for (int j = 0; j < 3 && indexDigit - j >= 0; ++j)
						if (strNumber[indexDigit - j] != '0')
							printThousends = 1;

					if (printThousends)
						indexBuf += sprintf(buf + indexBuf, " %s", thousends[nThousends]);
					nThousends--;
				}
				break;

			default:
				indexBuf += sprintf(buf + indexBuf, "%s ", "ERROR");
				break;
			}
		}
		
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