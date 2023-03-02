#include <stdio.h>
#include <stdint.h>

#define APP8

#ifdef APP1
/* get the status of nth bit */

int main(void)
{
	uint32_t a = 0x12345678;
	int n;

	printf("Bit no : ");
	scanf_s("%d", &n);

	if (a >> n & 1)
		printf("1\n");
	else
		printf("0\n");

	return 0;
}

#elif defined APP2
/* nibble swap */

int main(void)
{
	uint8_t a = 0xAF;
	uint8_t result;;
	
	result = a >> 4 | a << 4;
	printf("0x%02X\n", result);		/* 0xFA */

	return 0;
}


#elif defined APP3
/* macro function for low and high bytes of a word */

#define LOBYTE(w)	((w) & 0xFF)
#define HIBYTE(w)	((w) >> 8 & 0xFF)

int main(void)
{
	uint16_t w = 0x1234;
	uint8_t high, low;

	high = HIBYTE(w);
	low = LOBYTE(w);

	printf("0x%02X\n", high);	/* 0x12 */
	printf("0x%02X\n", low);	/* 0x34 */

	return 0;
}


#elif defined APP4
/* Bitwise NOT operator */

int main(void)
{
	int a = 0;
	a = ~a;
	printf("%d\n", a);	/* -1 */

	return 0;
}

#elif defined APP5
/* challenge: n-bits of 1 rest is 0 */

void disp_bits32(uint32_t val)
{
	for (int i = 31; i >= 0; --i)
		putchar((val >> i & 1) + '0');
	putchar('\n');
}

int main(void)
{
	uint32_t result = 0;
	int n;
	
	printf("Enter n : ");
	scanf_s("%d", &n);

	// result = ~0 >> (32 - n);
	result = ~(~0u << n);

	disp_bits32(result);	/* 00000000000000000000000000000111 */

	return 0;
}

#elif defined APP6
/* challenge: bitfield reset */

void disp_bits32(uint32_t val)
{
	for (int i = 31; i >= 0; --i)
		putchar((val >> i & 1) + '0');
	putchar('\n');
}
// Reset kth bit to (m+k)th bit
int main(void)
{
	uint32_t result = ~0u;
	int k, m;

	printf("Enter k : ");
	scanf_s("%d", &k);
	printf("Enter m : ");
	scanf_s("%d", &m);

	//result &= (~((~0u << m) << k));	// broken
	result &= ~((~0u >> (32 - (m - k + 1))) << k);

	disp_bits32(result);
	/*
		Enter k : 3
		Enter m : 5
		11111111111111111111111111000111
	*/

	return 0;
}

#elif defined APP7
/* bitwise opearations along adderesses */

int main(void)
{
	int a;
	int* pi;

	pi = (int *)((uintptr_t)&a << 4);	/* bitshift address by 4 */

	pi = (int *)((uintptr_t)&a & (~(uintptr_t)0 << 4));	/* reset LSB 4 bits of an address */

	return 0;
}

#elif defined APP8
/* bitfields*/

int main(void)
{
	struct Sample
	{
		double a;
		int b;
		int c : 3;	/* bitfiled */
		int d : 5;	/* bitfiled */
	};
	return 0;
}

#endif