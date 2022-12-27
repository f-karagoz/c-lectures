/*
* Title:		C and System Programmer Associatiion
*				C Programming Language Course - HW-7
* Instructor:	Kaan Aslan
* Author:		Furkan Karagoz
* Date:			27 / 12 / 2022
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

// To access the solution for the seconf question
// change the define below to "Q_2" and compile again
#define Q_1

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
	struct Complex cplx1;
	struct Complex cplx2;
	struct Complex cplx_res;

	printf("This program collects real numbers from screen\nand does addition, substraction, and multiplication operation over them.\n\n");

	printf("Enter first complex number: ");
	get_complex(&cplx1);
	disp_complex(&cplx1);

	printf("Enter second complex number: ");
	get_complex(&cplx2);
	disp_complex(&cplx2);

	printf("Result of addition is: \n");
	add_complex(&cplx1, &cplx2, &cplx_res);
	disp_complex(&cplx_res);

	printf("Result of substraction is: \n");
	sub_complex(&cplx1, &cplx2, &cplx_res);
	disp_complex(&cplx_res);

	printf("Result of multiplication is: \n");
	mul_complex(&cplx1, &cplx2, &cplx_res);
	disp_complex(&cplx_res);

	return 0;
}

// CHECK THE DISP AND GET FUNCTIONS. MIGHT BE BROKEN.
void disp_complex(struct Complex* pz)
{
	printf("%.2f, %.2fi\n", pz->real, pz->imag);
}

void get_complex(struct Complex* pz)
{
	char c = 0;
	scanf("%lf%lf", &pz->real, &pz->imag);
	// clear the stdin file
	while (c != '\n')
		 c = getchar();
}

void add_complex(struct Complex* pz1, struct Complex* pz2, struct Complex* pz3)
{
	pz3->real = pz1->real + pz2->real;
	pz3->imag = pz1->imag + pz2->imag;
}

void sub_complex(struct Complex* pz1, struct Complex* pz2, struct Complex* pz3)
{
	pz3->real = pz1->real - pz2->real;
	pz3->imag = pz1->imag - pz2->imag;
}

void mul_complex(struct Complex* pz1, struct Complex* pz2, struct Complex* pz3)
{
	pz3->real = pz1->real * pz2->real - pz1->imag * pz2->imag;
	pz3->imag = pz1->real * pz2->imag + pz1->imag * pz2->real;
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
bool intersect_rect(struct Rect* r1, struct Rect* r2, struct Rect* r3);

int main(void)
{
	struct Point p1 = {3,4};
	struct Rect r1 = {0,0,10,5};
	struct Rect r2 = {3,2,13,7};
	struct Rect r3;

	printf("Point p1 has coordinates: %d, %d\n", p1.x, p1.y);
	printf("Rectangle r1 has coordintes: %d, %d, and %d, %d\n", r1.x1, r1.y1, r1.x2, r1.y2);
	printf("Rectangle r2 has coordintes: %d, %d, and %d, %d\n", r2.x1, r2.y1, r2.x2, r2.y2);

	printf("Is p1 inside the r1? : %s\n", is_inside(&r1, &p1) ? "true" : "false");
	printf("Does r1 and r2 rectangles have intersected area? : %s\n", intersect_rect(&r1, &r2, &r3) ? "true" : "false");

	return 0;
}

bool is_inside(struct Rect* r, struct Point* p)
{
	if (p->x > r->x1 && p->x < r->x2 && p->y > r->y1 && p->y < r->y2)
        return true;
    else
        return false;
}

// this is only a partial solution
// condition needs to be satisfied for intersection:
// r1 is located upper left of the r2
// the algorithm will not produce correct result if the r2 is
// located left of the r1 etc.
bool intersect_rect(struct Rect* r1, struct Rect* r2, struct Rect* r3)
{
    /*
     if common x axis part
        if common y axis part
            intersect true
     o.w.
        intersect false
     */
    
    if (r2->x1 > r1->x1 && r2->x1 < r1->x2)
        if (r2->y1 > r1->y1 && r2->y1 < r1->y2)
        {
            r3->x1 = r2->x1;
            r3->x2 = r2->x2 < r1->x2 ? r2->x2 : r1->x2;
            r3->y1 = r2->y1;
            r3->y2 = r2->y2 < r1->y2 ? r2->y2 : r1->y2;
            return true;
        }
    
    r3->x1 = 0;
    r3->x2 = 0;
    r3->y1 = 0;
    r3->y2 = 0;
	return false;
}
#endif
