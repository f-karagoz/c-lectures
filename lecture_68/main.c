#include <stdio.h>

#define APP3

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

int main(void)
{
	return 0;
}

#elif defined APP5

int main(void)
{
	return 0;
}

#endif