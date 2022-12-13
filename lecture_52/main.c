#include <stdio.h>

#define APP_6

#ifdef APP_1

struct Sample
{
	int a[5];
	double b;
};

void print_sample(struct Sample* s_i)
{
	for (int i = 0; i < 5; ++i)
		printf("%d ", s_i->a[i]);
	printf("%f\n", s_i->b);
}

int main(void)
{
	struct Sample s1 = { 1,2,3,4,5,3.14 };
	print_sample(&s1);

	struct Sample s2 = { { 1,2,3,4,5 }, 3.14 };		// same outcome as previous
	print_sample(&s2);

	// no compiler error thown, behaviour is not intended though
	struct Sample s3 = { 1, 2, 3, 4, 3.14 };
	print_sample(&s3);
	
	return 0;
}

#elif defined APP_2

struct Person
{
	char name[32];
	int no;
};

int main(void)
{
	struct Person p = { "Furkan Karagoz", 5 };

	printf("%s, %d\n", p.name, p.no);

	struct Person p2;

	// p2.name = "Furkan K";	// invalid

	strcpy(p2.name, "Furkan K");

	printf("%s, %d\n", p2.name, p2.no);

	return 0;
}

#elif defined APP_3

struct Person
{
	char* name;
	int no;
};



int main(void)
{
	struct Person p;

	// If object is local name gets random address
	// If object is global name gets NULL address
	// strcpy(p.name, "Furkan K");			// String is placed inside random memory address, undefined behaviour
	p.name = "Furkan K";					// Now name points to the "Furkan K" sting literals address
	// "Furkan K" is placed into secure memory location by compiler
	p.no = 123;

	printf("%s, %d\n", p.name, p.no);

	return 0;
}

#elif defined APP_4

struct Complex
{
	double real;
	double imag;
};

int main(void)
{
	struct Complex z = { 3, 2 };
	struct Complex* pz;

	pz = &z;

	printf("%f + %fi\n", (*pz).real, (*pz).imag);
	return 0;
}

#elif defined APP_5

struct City
{
	char name[32];
	int plate;
};

int main(void)
{
	struct City c = { "Ankara", 6 };
	struct City* pc = &c;

	// Due to opeator precence groups left-to-right associativity
	// arrow op. operates first. Than square bracket operates
	putchar(pc->name[2]);	/* k */

	return 0;
}

#elif defined APP_6

struct City
{
	char name[32];
	int plate;
};

int main(void)
{
	// Below is valid but bad technique.
	// struct City cities[5] = { "Ankara", 6, "Istanbul", 34, "Bolu", 14, "Izmir", 35,"Bursa", 16 };

	struct City cities[5] =
	{
		{"Ankara", 6},
		{"Istanbul", 34},
		{"Bolu", 14},
		{"Izmir", 35},
		{"Bursa", 16}
	};

	for (int i = 0; i < 5; ++i)
		printf("%s, %d\n", cities[i].name, cities[i].plate);

	return 0;
}

#endif;