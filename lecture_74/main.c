#include <stdio.h>
#include <stdlib.h>

#define APP6

#ifdef APP1
/* File opearations in C (continued) */

// int fclose(FILE *f);
// success: 0, fail: EOF
// #define EOF (-1)

int main(void)
{
	FILE* f;

	if ((f = fopen("test.txt", "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file!\n");
		exit(EXIT_FAILURE);
	}

	fclose(f);

	return 0;
}

#elif defined APP2
/* File Pointer */

// Acts like a cursor
// The file consists of series of chars (bytes)
// File pointer points to index of chars in a file
// When a file opens Operating System gives each byte an
// offset number starting from 0
// This offset is called file pointer

// 0 1 2 3 4 5 6 7
// x x x x x x x _
//               ^ end of file (EOF)

// We cannot read in EOF situation, we can only write
// When we write the files legth will be extended

// File pointer is not for a unique file
// If file is opened mutiple times it has mutiple file pointers

int main(void)
{
	FILE* f1, * f2;

	if ((f1 = fopen("test.txt", "r") == NULL))
	{
		fprintf(stderr, "cannot open file!\n");
		exit(EXIT_FAILURE);
	}
	if ((f2 = fopen("test.txt", "r") == NULL))
	{
		fprintf(stderr, "cannot open file!\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}

#elif defined APP3

// int fgetc(FILE *f);
// unsigned char fget(FILE *f);
// Difference between return types of fgetc and fget is to
// catch the EOF situation (-1)
// Catching EOF is ambiguous with fget

// fgetc can fail due to two reasons:
// File pointer is at EOF situation, file could not be read
// Pathalogic error in the disc

int main(void)
{
	FILE* f;
	int ch;

	if ((f = fopen("test.txt", "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file!\n");
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(f)) != EOF)
		putchar(ch);					/* testttt */

	fclose(f);

	return 0;
}

#elif defined APP4

// There are two functions to get feedback about the last unsuccesful event
// int ferror(FILE *f);
// int feof(FILE *f);

// ferror returns to a non-zero value if the last operation is failed due to IO error
//			returns to zero when fail reason is not IO error.

// feof returns to non-zero value if the last operation is failed due to EOF situation
//		returns to zero when fail reason is not EOF.

int main(void)
{
	FILE* f;
	char ch;

	// Bad-Method:
	// Prints EOF (-1) as character
	/*
	while(!feof(f))
	{
		ch = fgetc();
		putchar(ch);
	}
	*/

	// METHOD-1
	for (;;)
	{
		ch = fgetc(f);
		if (feof(f))
			break;
		putchar(ch);
	}
	
	// METHOD-2
	while ((ch = fgetc(f)) != EOF)
		putchar(ch); 

	if (ferror(f))
	{
		fprintf(stderr, "Unexpected IO error...\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}

#elif defined APP5
/* fputc */

// int fputc(int ch, FILE *f);

// Returns to the written byte value when succeeded. If fails returns to EOF value.

int main(void)
{
	FILE* f;
	int ch;
	char s[] = "ankara";

	if ((f = fopen("test.txt", "r+")) == NULL)
	{
		fprintf(stderr, "Cannot open file!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; s[i] != '\0'; ++i)
		if (fputc(s[i], f) == EOF)						/* ankarat */
		{
			fprintf(stderr, "Unexpected IO error!\n");
			exit(EXIT_FAILURE);
		}

	fclose(f);

	return 0;
}

#elif defined APP6
/* File types */

// Text file and binary file.
// In the perspective of OS, a file is consist of bytes.
// However, in C files are seperated as "text" and "binary" to ease the operations.

int main(void)
{
	return 0;
}
#endif