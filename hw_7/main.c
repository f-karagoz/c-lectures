#include <stdio.h>
#include <stdbool.h>

#define Q_2

#ifdef Q_1


struct Complex
{
	double real;
	double imag;
};

// Task1: write a function that prints out to screen (to stdout file)
void disp_complex(struct Complex* pz);
// Task2: read from keyboard to put into Complex object
void get_complex(struct Complex* pz);
// Task3: add complex numbers *pz1 *pz2 = *pz3
void add_complex(struct Complex* pz1, struct Complex* pz2, struct Complex* pz3);
// Task4: substract two complex numbers
void sub_complex(struct Complex* pz1, struct Complex* pz2, struct Complex* pz3);
// Task5: multiply two complex numbers
void mul_complex(struct Complex* pz1, struct Complex* pz2, struct Complex* pz3);

int main(void)
{
	return 0;
}

#elif defined Q_2

struct Point
{
	int x;
	int y;
};

// Upper left corner (x1,y1), lower right corner (x2,y2)
struct Rect
{
	int x1;
	int y1;
	int x2;
	int y2;
};

// Task1: if the point is inside the rectangle return true, false o.w.
// i: bool type is typdef'd in the stdbool.h as _Bool
bool is_inside(struct Rect* r, struct Point* p);

// Task2: Represent an intersected rectanglular object
// intersect r1 and r2 and return to r3
bool intersect_rect(struct rect* r1, struct rect* r2, struct rect* r3);

int main(void)
{
	return 0;
}

#endif