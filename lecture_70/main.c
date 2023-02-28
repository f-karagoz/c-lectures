#include <stdio.h>

#define APP10

#ifdef APP1
/* Bitwise operators and logic operators */

int foo(void)
{
	printf("foo\n");
	return 0;
}

int bar(void)
{
	printf("bar\n");
	return 0x3F;
}

int tar(void)
{
	printf("tar\n");
	return 0x7A;
}

int main(void)
{
	int result;

	result = foo() & bar() & tar();

	printf("Result : %d\n", result);

	result = foo() && bar() && tar();

	printf("Result : %d\n", result);

	return 0;
}

#elif defined APP2
/* Bitwise-OR Operator */

int main(void)
{
	unsigned char a = 0xA2; /* 1010 0010 */
	unsigned char b = 0x34; /* 0011 0100 */
	unsigned char c;

	c = a | b;				/* 1011 0110 */

	printf("%02X\n", c);	/* B6 */

	return 0;
}

#elif defined APP3
// Bitwise-AND operator has higher priority then bit-OR operator
// Even and odd check is faster with bitwise method

int main(void)
{
	int a;

	printf("Bir sayi giriniz: ");
	scanf_s("%d", &a);
	
	printf(a & 1 ? "tek\n" : "cift\n");
	
	return 0;
}

#elif defined APP4

int main(void)
{
	int a;

	printf("Bir sayi giriniz: ");
	scanf_s("%d", &a);

	//if (a & 1 == 0)			/* == operator has higher precedence than & operator */
	if ( (a & 1) == 0 )
		printf("cift\n");
	else
		printf("tek\n");

	return 0;
}

#elif defined APP5
/* Bitwise-XOR operator */
// 
// 0101 1011
// 0111 1101
// ---------
// 0010 0110
// 
// 0 is neutral element, 1 inverses the bit
// 
// XOR can be used to inverse a portion of a bitfield
// ...end

int main(void)
{
	unsigned char a = 0x5B;	/* 0101 1011 */
	unsigned char b = 0x7D;	/* 0111 1101 */
	unsigned char c;

	c = a ^ b;				/* 0010 0110 */

	printf("%02X\n", c);	/* 26 */

	a = a ^ 0x10;			/* 0100 1011 = 0x4B */

	printf("%02X\n", a);	/* 4B */

	return 0;
}

#elif defined APP6
/* XOR's reversable feature */
// This feature can be used to encrypt data
// We can XOR a data with a key to encrypt it
// Then XOR the encrypted data to gather the original data

int main(void)
{
	unsigned char a = 0x6D;	/* 0110 1101 = 0x6D */
	unsigned char b = 0xB2;	/* 1011 0010 = 0xB2 */
	unsigned char c;
	unsigned char rev1;
	unsigned char rev2;

	c = a ^ b;				/* 1101 1111 = 0xDF */
	rev1 = c ^ a;			/* 1011 0010 = 0x6D = b */
	rev2 = c ^ b;			/* 0110 1101 = 0xB2 = a */

	printf("c:    0x%02X\n", c);		/* 0xDF */
	printf("rev1: 0x%02X\n", rev1);		/* 0x6D */
	printf("rev2: 0x%02X\n", rev2);		/* 0xB2 */

	return 0;
}

#elif defined APP7
/* XOR data encryptiion */

int main(void)
{
	unsigned char data[] = "hello";
	unsigned char key[5] = { 0x12,0x34,0x56,0x78,0x9A };
	unsigned char encrypted[5];
	unsigned char test[5];

	printf("Original data: \n");
	for (int i = 0; i < 5; ++i)
	{
		printf("0x%02X ", data[i]);			/* 0x68 0x65 0x6C 0x6C 0x6F */
	}

	printf("\n\nEncrypted data: \n");
	for (int i = 0; i < 5; ++i)
	{
		encrypted[i] = data[i] ^ key[i];
		printf("0x%02X ", encrypted[i]);	/* 0x7A 0x51 0x3A 0x14 0xF5 */
	}

	printf("\n\nTest: \n");
	for (int i = 0; i < 5; ++i)
	{
		test[i] = encrypted[i] ^ key[i];
		printf("0x%02X ", test[i]);			/* 0x68 0x65 0x6C 0x6C 0x6F */
	}
	printf("\n\n");

	return 0;
}

#elif defined APP8
/* Bitshift operators */
// Shifting left is equivalent to multiplying by 2
// Sifting right is equivalent to division by 2

int main(void)
{
	unsigned char a = 0x6D;	/* 0110 1101 = 0x6D */
	unsigned char b;

	b = a << 1;				/* 1101 1010 = 0xDA */
	printf("0x%02X\n", b);	/* 0xDA */

	b = a >> 1;				/* 0011 0110 = 0x36 */
	printf("0x%02X\n", b);	/* 0x36 */

	return 0;
}

#elif defined APP9
// In bitshift operations types are upgraded to int

int main(void)
{
	int a = 0x7FFFFFFF;		/* largest int number */
	int b = a << 1;

	printf("a: %d\n", a);	/* a: 2147483647 */
	printf("b: %d\n", b);	/* b: -2 */

	return 0;
}

#elif defined APP10
// In C standards:
// 1. If left operand is unsigned type all the bits are 
// shift to left and and left bits are destroyed in left shift
// 2. If left operand is unsigned type all the bits are 
// shift to right and and right bits are destroyed in right shift
// 3. If left operand is signed type, positive, and if the number is still representable
// after the multiplication (2^n) the result is valid in the left shift,
// otherwise undefined beahviour (out of bounds OR negative initial value cases)
// 4. In right shift opearation if the signed type is shifted right and number is postive
// the right shift is performed as usual. If the value is negative, whether the sign bit is
// preserved or not is implementation depended.
// 5. In right shift operation if the right operand is negative or right operand exceeds 
// the bit width of the left operand the result is undefined

int main(void)
{
	/* Case-1 */
	unsigned int a = 0xFFFFFFFF;
	unsigned int b;
	b = a << 1;
	printf("0x%08X\n", b);		/* 0xFFFFFFFE */

	/* Case-2 */
	unsigned int c = 0xFFFFFFFF;
	unsigned int d;
	d = c >> 1;
	printf("0x%08X\n", d);		/* 0x7FFFFFFF */

	/* Case-3 */
	int e = 0x3FFFFFFF;
	int f;
	f = e << 1;
	printf("0x%08X\n", f);		/* 0x7FFFFFFE */

	/* Case-4 */
	int g = 0x7FFFFFFF;
	int h;
	h = g >> 1;
	printf("0x%08X\n", h);		/* 0x3FFFFFFF */

	/* Case-5 */
	int i = 0x7FFFFFFF;
	int j;
	j = i >> -1;
	printf("0x%08X\n", j);		/* 0x00000000 */

	return 0;
}

#endif