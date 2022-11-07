#include "stdio.h"

#define APP_4

#ifdef APP_1
int main(void)
{
	int a = 0x12345678;

	unsigned char* puc;

	puc = (unsigned char*)&a;

	printf("%02X %02X %02X %02X", puc[0], puc[1], puc[2], puc[3]);

	return 0;
}

#elif defined APP_2
int main(void)
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[10];
	double c[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10 };
	double d[10];

	memcpy(b, a, 40);		// int is 4-bytes

	for (int i = 0; i < 10; ++i)
		printf("%d ", b[i]);
	printf("\n");

	memcpy(d, c, 80);		// double is 8-bytes

	for (int i = 0; i < 10; ++i)
		printf("%f ", d[i]);
	printf("\n");

	return 0;
}

#elif defined APP_3
int main(void)
{
	char s[] = "ankara";
	char d[100];

	memcpy(d, s, strlen(s) + 1); // + 1 is for NULL termination

	puts(d);

	return 0;
}

#elif defined APP_4
int main(void)
{
	return 0;
}

#endif