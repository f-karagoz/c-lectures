#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

// struct tm *localtime(const time_t *pt);

int main(void)
{
	time_t t;
	struct tm* pt;
	char* str;

	char* days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

	t = time(NULL);
	pt = localtime(&t);

	printf("%02d/%02d/%04d %02d:%02d:%02d - %s\n",
		pt->tm_mday, pt->tm_mon + 1, pt->tm_year + 1900, pt->tm_hour, pt->tm_min, pt->tm_sec, days[pt->tm_wday]);
	// 12/01/2023 20:06:17 - Thursday

	str = ctime(&t);

	printf("%s\n", str);
	// Thu Jan 12 20:33:23 2023

	return 0;
}