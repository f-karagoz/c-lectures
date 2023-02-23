#include <stdio.h>

#define APP_8
/* Compound Literals */

// Added to C in C99
// Allows instatiation of structures and arrays within an expression.
// 
// C++ does not encoprate this feature (instead constructors)
// 
// We cannot utilize type conversion over structure types.
// Whereas type conversion is possible via compound literals.
// 
// If compound literals instantiated globally they have static lifetime.
// If tthey are instantiated within a fucntion block their lifetime is limited to
// the scope of the function.
// 
// C standards state that each compound literal creates only a single object in a given scope
// 
// (<type>) {<member_list>}
// ...end


#ifdef APP_1
/* Compound Literals */

struct Point
{
	int x;
	int y;
};

void draw_line(struct Point pt1, struct Point pt2)
{
	printf("Draw line : %d,%d - %d,%d\n", pt1.x, pt1.y, pt2.x, pt2.y);
}

int main(void)
{
	struct Point pt1 = { 3,4 }, pt2 = { 5,6 };

	draw_line(pt1, pt2);						/* Draw line : 3,4 - 5,6 */

	draw_line((struct Point) { 1, 2 }, (struct Point) { 3, 4 });		/* Draw line : 1,2 - 3,4 */

	return 0;
}

#elif defined APP_2
/* Object instantiation within function call */
// Object lifetime is same as the instantiated block lifetime

struct Date
{
	int day, month, year;
};

void disp_date(struct Date* pdate)
{
	printf("%02d/%02d/%02d\n", pdate->day, pdate->month, pdate->year);
}

int main(void)
{
	struct Date d;

	disp_date(&(struct Date) {10,12,2020});		/* 10/12/2020 */

	d = (struct Date){ 21,12,2008 };
	disp_date(&d);								/* 21/12/2008 */

	return 0;
}


#elif defined APP_3
/* Array instatiation with compound literals */

void disp(const int* pi, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		printf("%d ", pi[i]);
	printf("\n");
}

int main(void)
{
	disp((int[5]) { 10, 20, 30, 40, 50 }, 5);	/* 10 20 30 40 50 */
	return 0;
}


#elif defined APP_4
// Creates l-value instances. Therefore the value can be changed.

int main(void)
{
	int* pi;

	pi = (int[]){ 10,20,30 };

	*pi = 100;									/* Valid */

	for (int i = 0; i < 3; ++i)
		printf("%d ", pi[i]);					/* 100 20 30 */
	printf("\n");

	return 0;
}

#elif defined APP_5
/* Lifetime of compound literals */

// In today's compilers even the local variable is defined in an inner block the variable is instatiated from the start of the block.
// Even though there is an expression in C standards agains that the object is not created multiple times.
// This is due to the cost of creating and killing an object.
// In the below example notice that we get the same address every cycle of the loop.

int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		int a = 10;

		printf("%d\n", &a);
	}

	return 0;
}


#elif defined APP_6

int main(void)
{
	int* pi;

	pi = (int[10]){ [5] = 10,[7] = 200,300 };

	for (int i = 0; i < 10; ++i)
		printf("%d \n", pi[i]);
	printf("\n");

	return 0;
}

#elif defined APP_7

// Compound literals can be utilized for normal types other tham structures.

int main(void)
{
	int* pi;

	pi = &(int) { 10 };						/* Valid */

	/* Above is equivalent to:
	int *pi;
	int temp = 10;
	pi = &temp;
	*/

	return 0;
}

#elif defined APP_8
/* Bitwise operators */

// ~ (bit NOT)
// & (bit AND)
// & (bit EXOR)
// | (bit OR)
// << (shift left)
// >> (shift right)
// 
// ...end

int main(void)
{
	// TBC 21:44
	return 0;
}

#elif defined APP_9

int main(void)
{
	return 0;
}

#elif defined APP_10

int main(void)
{
	return 0;
}

#elif defined APP_11

int main(void)
{
	return 0;
}
#endif