#include <stdio.h>

#define APP1

#ifdef APP1
// Allignment, structure member allignment
// 
// In 32-bit systems the data stored in an
// alligned memory location (bank) is accessed
// slightly faster
// 
// padding is spaces left between the objects
// to achieve the allignment
// 
// Allignment is optional in 32-bit Intel processors.
// ARM processors cannot access un-alligned bojects
// When ARM processor attempts to acccess and un-alligned
// objects, processor throws and intepput and OS ends
// the process.
// 
// Alignment types:
// [1-byte] Byte Alignment,
// [2-byte] Word Alignment,
// [4-byte] DWord Alignment,
// [8-byte] QWord Alignment,
// [16-byte] DQWord Alignment
// 
// 1 byte object (char), 2 byte object (short), 4 byte obkect (int);
// 8 byte object (double) will be alligned with multiplitudes of 1,
// 2, 4, and 4 int 32-bit systems.
// 
// Setting the struct member alignment from,
// Compiler:	cl.exe ---> cl /Zp[1|2|4|8|16]
//				gcc ---> gcc -fpack-struct=[N]
// IDE: VS ---> Properties > Configuration Properties > C / C++ >
//						Code Generation > Struct Member Alignment
// 
// gcc -fpack-struct=1
// 
// #pragma pack(N) directive can be used to change the structure
// member allignment too and it is higher priority than the compiler
// option switches.
// pragma pack can be used to set the alignment irregularly within the code.
// 
// Stricter requirement
// _Alignas(N)		// C11 6.7.5
// _Alignof(type)	// C11
// 
// ...end...

//#pragma pack(1)

struct Sample
{				// memory layout:
	char a;		// a---
	int b;		// bbbb
	char c;		// c---
	int d;		// dddd
};

struct Sample_2
{				// memory layout:
	char a;		// ab--
	char b;		// cccc
	int c;		// dddd
	int d;		
};

struct Sample_3
{
	int a;		
	_Alignas(8) int b; // C11 standard
};

int main(void)
{
	struct Sample s;
	// expected 10 bytes but got 16
	// due to structure member allignment
	// compiler is alligning for 4 bytes
	printf("%zd\n", sizeof(s));		/* 16 */

	struct Sample_2 s2;
	printf("%zd\n", sizeof(s2));		/* 12 */

	struct Sample_3 s3;
	printf("%zd\n", sizeof(s3));		/* 16 */

	return 0;
}

#elif defined APP2
// typedef
// 
// typedef <statement>;
// typedef int A
// In C giving a type an place holder name is called typedef stement.
// In C syntax "typedef" is placed in the "storage class specifier"
// It converts a variable name to a type name
// typedef does not declere a variable
// a storage class specifier and type name can be swapped in syntax

// typedef unsigned int size_t;

typedef char* Str;			/* also valid: char* typedef Str; */
typedef int Int, * Pint;
typedef int arr_typeDef[5];

int main(void)
{
	Str s = "ankara";	/* char* s = "ankara"; */

	printf("%s\n", s);	/* ankara */

	Int num = 10;
	Pint pnum = &num;

	printf("Num is %d and %d is num.\n", num, *pnum);

	arr_typeDef a = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; ++i)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}

#elif defined APP3

int main(void)
{
	return 0;
}

#endif