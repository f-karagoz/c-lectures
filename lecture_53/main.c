#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
* Why we use structs?
* 1) Correlated datas can be stored together in a meningful way.
* 2) Passing as parameters to many argument functions.
* 3) Returning more than one data from a function.
*/

#define APP_4

#ifdef APP_1

struct Date
{
	int day;
	int month;
	int year;
};

void disp_date(struct Date* p)
{
	printf("%d/%d/%d\n", p->day, p->month, p->year);
}

void get_date(struct Date* p)
{
	printf("Day: ");
	scanf("%d", &p->day);

	printf("Month: ");
	scanf("%d", &p->month);

	printf("Year: ");
	scanf("%d", &p->year);
}

int main(void)
{
	struct Date date;

	get_date(&date);
	disp_date(&date);

	return 0;
}

#elif defined APP_2

#include <stdlib.h>

struct Person
{
	char name[32];
	int no;
};



int main(void)
{
	struct Person * per;

	// Structs allocate consecutive memory. They can be instatiated with malloc, calloc
	if ( ( per = (struct Person *)malloc(sizeof(struct Person)) ) == NULL)
	{
		fprintf(stderr, "Cannot allocate memory!\n");
		exit(EXIT_FAILURE);
	}
	
	strcpy(per->name, "Furkan Karagoz");
	per->no = 123;

	printf("%s, %d\n", per->name, per->no);

	free(per);

	return 0;
}

#elif defined APP_3

#include <stdlib.h>

struct Person
{
	char name[32];
	int no;
};

struct Person* get_person(void)
{
	struct Person* per;

	if ((per = (struct Person*)malloc(sizeof(struct Person))) == NULL)
		return NULL;

	printf("Name surname: ");
	gets(per->name);		// Attention buffer needs to be clear before gets, care scanf
	printf("No: ");
	scanf("%d", &per->no);

	// Clear the input buffer
	while (getchar() != '\n')
		;

	return per;


}

int main(void)
{
	struct Person* per;

	if ((per = get_person()) == NULL)
	{
		fprintf(stderr, "Cannot allocate memory!\n");
		exit(EXIT_FAILURE);
	}

	printf("%s, %d\n", per->name, per->no);

	free(per);

	return 0;
}

#elif defined APP_4

#include <time.h>
// Checks local time and return seconds passed since "epoch"
// Time passed since 01 01 1970

int main(void)
{
	time_t t;

	// time(&t);
	t = time(NULL);		// NULL means that the function will return

	printf("%.0f\n", (double)t); // Normally 6 precision digit, but .0 prints 0 digits

	return 0;
}
#endif