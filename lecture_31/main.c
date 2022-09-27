#include "stdio.h"

#define APP_2

#ifdef APP_1
// Print the weekday of the given day
// Bir yýlýn 4 e bölünüp 100 e tam bölünmeyen yada 400 e tam bölünenleri artýktýr

#define ISLEAP(YEAR)		((YEAR) % 4 == 0 && (YEAR) % 100 != 0 || (YEAR) % 400 == 0 )

long total_days(int day, int month, int year)
{
	long tdays = 0;

	for (int i = 1900; i < year; i++)
		tdays += ISLEAP(i) ? 366 : 365;

	switch (month - 1)		// fallthrough property used
	{
	case 12:				/* UNREACHABLE */
		tdays += 31;
	case 11:
		tdays += 30;
	case 10:
		tdays += 31;
	case 9:
		tdays += 30;
	case 8:
		tdays += 31;
	case 7:
		tdays += 31;
	case 6:
		tdays += 30;
	case 5:
		tdays += 31;
	case 4:
		tdays += 30;
	case 3:
		tdays += 31;
	case 2:
		tdays += ISLEAP(year) ? 29 : 28;
	case 1:
		tdays += 31;
	}

	tdays += day;

	return tdays;
}

void disp_day(int day, int month, int year)
{
	long tdays;

	tdays = total_days(day, month, year);

	//printf("DEBUG: total days: %d\n", tdays);

	switch (tdays % 7)
	{
	case 0:
		printf("Pazar\n");
		break;
	case 1:
		printf("Pazartesi\n");
		break;
	case 2:
		printf("Sali\n");
		break;
	case 3:
		printf("Carsamba\n");
		break;
	case 4:
		printf("Persembe\n");
		break;
	case 5:
		printf("Cuma\n");
		break;
	case 6:
		printf("Cumartesi\n");
		break;
	}
}

int main(void)
{
	disp_day(23, 4, 1920);

	return 0;

}

#elif defined APP_2
// poniter
// program is loaded into RAM
// new systems utilize linear address rather than physical adresses #paging mechanism
// RAM has bytes but it is not a guarantee that one byte is 8-bit
// Starting from 0 every byte has one incremented address in the RAM
int main(void)
{
	return 0;
}

#elif defined APP_3
int main(void)
{
	return 0;
}

#elif defined APP_4
int main(void)
{
	return 0;
}
#endif