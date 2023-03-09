#include <stdio.h>

#define APP2

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
/* Bitfileds Memory Optimization */
// Multiple elements of a single structure with bitfileds
// can be structured together to optimize the memory storage.

struct Sample
{
	int a1 : 5;
	int b1 : 6;
	int c1 : 7;
	int a2 : 5;
	int b2 : 6;
	int c2 : 7;
};

int main(void)
{
	struct Sample s[1000000];
	return 0;
}

#elif defined APP3
/* Padding Bits */

struct Sample
{
	int a : 3;		/* Bitfield */
	int : 5;		/* Padding */
	int b : 3;		/* Bitfield */
	int : 5;		/* Padding */
};

int main(void)
{
	return 0;
}

#elif defined APP4
/* Alignment Bitfield */
// 0 length bit field means that the next bitfield will be aligned.

struct Sample
{
	int a : 5;		/* Bitfield */
	int : 0;		/* Alignment */
	int b : 7;		/* Bitfield */
};

int main(void)
{
	return 0;
}

#elif defined APP5
/* File Operations */
//
// Users access the files via names. The organization of the files
// is handled by the OS. Files can be stored under directories, the path is the exact
// location of a file.
// 
// In Windows every disk has its own root. When a flash disc is inserted it has its own 'root'.
// This units are called 'drive' in Windows. Unix/Linux systems do not use the drive system.
// In Unix when a disk is inserted it is 'mount'ed under a directory.
// ...end...

int main(void)
{
	return 0;
}

#endif