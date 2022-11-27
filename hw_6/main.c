#include <stdio.h>
#include <string.h>

// To compile for different HW tasks
// Chanage between APP-1, APP-2 and APP-3 and compile again
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

void disp_ratio(int num, int denom);
int gcd(int a, int b);


int main(void)
{
	printf("App - 2\n");
	int a, b;

	while (1)
	{
		printf("Numerator: ");
		scanf("%d", &a);
		printf("Denumerator: ");
		scanf("%d", &b);

		disp_ratio(a, b);
		puts("\n");
	}
	return 0;
}

void disp_ratio(int num, int denom)
{
	if (num == 0)
	{
		if (denom == 0)
		{
			printf("Undefined");
			return;
		}
		printf("0");
		return;
	}
	else if (denom == 0)
	{
		printf("Inifinite");
		return;
	}
	else
	{
		int sign = 1;

		if (num < 0)
		{
			sign *= -1;
			num *= -1;
		}

		if (denom < 0)
		{
			sign *= -1;
			denom *= -1;
		}

		if (num % denom == 0)
		{
			num /= denom;
			printf("%s%d", sign == -1 ? "-" : "", num);
			return;
		}
		else
		{
			int divGcd = gcd(num, denom);
			num /= divGcd;
			denom /= divGcd;
			printf("%s%d / %d", sign == -1 ? "-" : "", num, denom);
		}
	}
	return;
}

int gcd(int a, int b)
{
	int R;
	while ((a % b) > 0) {
		R = a % b;
		a = b;
		b = R;
	}
	return b;
}

#elif defined APP_3
void disp_complex(int real, int imag);

int main(void)
{
	printf("App - 3\n");

	int a, b;

	while (1)
	{
		printf("Real: ");
		scanf("%d", &a);
		printf("Imaginary: ");
		scanf("%d", &b);

		disp_complex(a, b);
		puts("\n");
	}

	return 0;
}

void disp_complex(int real, int imag)
{
	if (real == 0 && imag == 0)
	{
		printf("0");
		return;
	}
	else
	{
		if (real == 0)
		{
			printf("%di", imag);
		}
		else if (imag == 0)
		{
			printf("%d", real);
		}
		else
		{
			printf("%d %s %di", real, imag < 0 ? "-" : "+", imag < 0 ? imag * -1 : imag);
		}
			
	}
	return;
}

#endif