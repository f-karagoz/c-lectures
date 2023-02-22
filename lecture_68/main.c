#include <stdio.h>

#define APP7

#ifdef APP1
/* Function Pointers - continued */

// In C we can assign any data address to a void pointer
// but we cannot assign function's address to a void pointer
// 
// The is no void function pointer that supports all function pointer assignment operations
// But we can utilize type conversion to change a function pointers type
// to another function pointer type
// 
// There is a work around way to put a function pointers address tp void pointer
// we can get its address with & operator

void (*fp)(void);
void foo(void)
{
	printf("foo\n");
}

int main(void)
{
	void (*fp)(void);

	void* pv;

	fp = foo;

	fp();			/* foo */

	pv = foo;		/* Invalid */

	pv = &foo;		/* Valid. pv contains address of pointer to function pointer*/

	fp = (void (*)(void)) (void (**)(void))pv;	/* method to get back the function address to fp */

	fp();			/* foo */

	return 0;
}

#elif defined APP2
/* void parameter functions */

void foo(void)
{
	printf("foo\n");
}

void bar(int a)
{
	printf("bar\n");
}

void tar(char c)
{
	printf("tar\n");
}

int main(void)
{
	void (*pf1)(void);
	void (*pf2)();

	pf1 = foo;	/* Valid */
	pf1 = bar;	/* Invalid */
	pf1 = tar;	/* Invalid */

	pf2 = foo;	/* Valid */
	pf2 = bar;	/* Valid */
	pf2 = tar;	/* Valid */

	return 0;
}

#elif defined APP3
/* Alignment of objects larger than 1-byte */

// Depending on the processor LSB can be on the lower
// address in the memory or MSB can be on the lower
// address in the memory

// LSB on the lower address (Little Endian) : 
// Intel, ARM processors
// MSB on the lower address (Big Endian) :
// Power PC, SPAC, Alpha processors 

// ARM processor support Little Endian and Big Endian

// To store 0x12345678 data:
// Little endian :
// 78
// 56
// 34
// 12
// 
// Big endian :
// 12
// 34
// 56
// 78
// 
// In endianness there is no difference differece between bits of individual bytes
// Placement of the bytes differ

int main(void)
{
	int a = 0x12345678;

	unsigned char* pc;

	pc = (unsigned char*)&a;

	// Intel processor, Little Endian
	for (int i = 0; i < 4; ++i)
		printf("%02X\n", pc[i]);

	// 78
	// 56
	// 34
	// 12

	return 0;
}

#elif defined APP4
/* Unions */

// Data structures similar to the structures but they differ within the construction
// Structures allocate memory for all of its data contents (reagrding allignment).
// Unions allocate memory for the largest data member of its members.
// 
// union Sample
// {
//	...
// }
// 
// struct Sample	/* Invalid */
// {
//	...
// }
// 
// int Sammple;		/* Valid */
// 
// union Sample s = {1,2,3}; /* Invalid */
// 
// union Sample k = {.b = 2} /* Valid */
// 
// ...end

union Sample
{
	int a;
	long b;
	double c;
};

union Sample s;
union Sample* ps;

int main(void)
{ 
	s.a = 1;
	s.b = 10;
	s.c = 1.75;

	printf("a: %d, b: %ld, c: %f\n", s.a, s.b, s.c);	/* a: 0, b: 0, c: 1.750000 */

	printf("size is : %zd\n", sizeof(s));				/* 8 */

	return 0;
}

#elif defined APP5
/* utilzing unions */
// unions are used in situations only one of the data is required from a group of data
// How to determine which data is utilized in an union?
// There is no standard way. We need to log that info.

enum {CINFO_TELLNO, CINFO_TCID, CINFO_EMAIL};

struct Person
{
	char name[64];
	int no;
	int cinfo_flag;
	union
	{
		char tellno[11];
		char tcid[12];
		char email[64];
	} cinfo;
};

struct Person per = { "Alir Serce", 123, CINFO_EMAIL, {.email="bob@gmail.com"}};

int main(void)
{

	return 0;
}

#elif defined APP6
/* Complete Data From Parts - Unions */
#include <stdint.h>

// Parts can be changed depending on the system's endiannnes

union DWORD
{
	uint32_t dword;
	uint8_t bytes[4];
};

union DWORD dw;

int main(void)
{
	dw.dword = 0x12345678;

	printf("%02X %02X %02X %02X\n", dw.bytes[0], dw.bytes[1], dw.bytes[2], dw.bytes[3]);
	/* 78 56 34 12 */
	printf("%08lX\n", (unsigned long)dw.dword);
	/* 12345678 */

	return 0;
}

#elif defined APP7
/* struct part of a union */
#include <stdint.h>

struct Bytes
{
	uint8_t b0;
	uint8_t b1;
	uint8_t b2;
	uint8_t b3;
};

union DWORD
{
	uint32_t dword;
	struct Bytes bytes;
};

union DWORD dw;

int main(void)
{
	dw.dword = 0x12345678;

	printf("%02X %02X %02X %02X\n", dw.bytes.b0, dw.bytes.b1, dw.bytes.b2, dw.bytes.b3);
	/* 78 56 34 12 */

	dw.bytes.b0 = 0x10;
	dw.bytes.b1 = 0x20;
	dw.bytes.b2 = 0x30;
	dw.bytes.b3 = 0x40;

	printf("%08lX\n", (unsigned long)dw.dword);
	/* 40302010 */

	return 0;
}

#endif