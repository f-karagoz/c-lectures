#include <stdio.h>

#define APP5

#ifdef APP1
// const type qualifier
// 
// Why use const?
// 1) To increase readability of the code.
// 2) Helps compiler to optimize the code better.
// 3) Prevent programmer to attempt to change constant instances.
// 
// const type qualifiers popularly used with pointers.
// 
//...end

const int a = 10;

struct Date
{
	int day, month, year;
};

int main(void)
{
	printf("My value : %d\n", a);
	
	// a = 20;			/* Cannot assign value to const qualified type */

	const struct Date d = { 17, 1, 2023 };

	// d.day = 18;		/* Invalid1 */

	return 0;
}

#elif defined APP2
// 3 cases for const with pointers;
// 
// 1) Ponter is not const the object it points to const
// 2) Pointer is const but the object ist points to is not
// 3) Both const

// Case 1
int main(void)
{
	// int *pi; /* pi is an pointer object and it points to an object */

	// const int *pi;
	// int const *pi;
	// are the same and they specify that the
	// pointer is not const but the object it points to is const

	int a = 10;
	int b = 20;

	/* type: const int*	*/
	const int* pi;

	pi = &a;
	pi = &b;

	// *pi = 100;	/* Invalid */
	// pi[10] = 100;	/* Invalid */
	// Acessing the object through the pointer acts as read-only access

	return 0;
}

#elif defined APP3
// when const specifier placed after the *
// 
// Case 2
int main(void)
{
	int a;
	int b;
	/* type: int* const	*/
	int* const pi = &a;	/* pi is a const object */

	*pi = 10;

	printf("%d\n", a);

	//pi = &b;			/* Invalid */

	return 0;
}

#elif defined APP4
// Case 3
int main(void)
{
	int a = 10;
	int b;

	/* type: const int* const	*/
	const int* const pi = &a;	/* Both the pointer and the object has read-only access */

	//pi = &b;		/* Invalid */
	//*pi = 20;		/* Invalid *2

	return 0;
}

#elif defined APP5
// There is no implicit type conversion for converting
// "cost T *" to "const * T"
int main(void)
{
	const a = 10;
	const b = 1;

	int* pi = &a;	/* Invalid but compiles */

	*pi = 20;		/* Against the C ISO standards but compiles */
	// We are chaging the const variable

	int* pii = (int*)&b;	/* Valid but undefined behaviour */

	*pi = 2;

	return 0;
}

#endif