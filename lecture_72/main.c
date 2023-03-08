#include <stdio.h>

#define APP1

#ifdef APP1
/* Bitfileds */
// According to the standards bitfilds can be 'int', 'unsigned int', or '_Bool'.
// However wherher other typees can be used as bitfields is implementation defined.
// It is meaningles to get the address of bitefiled data structure members.
// Memory organization of the bitfields is vaugly bounded in the C standard. Mostly implementation defined.
// If there is an another birfiled adjacent to a bitfield, and if the birfiled's size is enough to fit in the same byte
// they are stored in the same byte.

struct Test
{
	int a : 3;
	int b : 5;	/* Placed in the same byte in the adjacent bitfiled's byte */
	int c : 3;
	int d : 7;	/* Placement is implementation defied */
	// Whether:
	// c|c|c|_|_|_|_|_
	// d|d|d|d|d|d|d|_
	// Or:
	// c|c|c|d|d|d|d|d
	// d|d|_|_|_|_|_|_
};

struct Sample
{
	int a;
	long b;
	int c : 3;		// Can store {-4,-3,-2,-1,0,1,2,3}
	unsigned int d : 5;
	//float : 2;	/* Invalid */
	//double : 7;	/* Invalid */
};

int main(void)
{
	struct Sample s;
	int* pi;

	s.a = 2;
	
	//pi = &s.c;	/* Taking the address of bitfield is not allowed */

	return 0;
}

#elif defined APP2

int main(void)
{
	return 0;
}

#elif defined APP3

int main(void)
{
	return 0;
}

#elif defined APP4

int main(void)
{
	return 0;
}

#endif