#include "stdio.h"

#define APP_3

#ifdef APP_2

// When target is unsigned
int main()
{
	int a = 0x12345678;

	unsigned short b;

	b = a;

	printf("%x\n",b);

	return 0;
}

#elif defined APP_3
int main()
{
	int a = -1; // 0x FF FF FF FF
	unsigned int b;

	b = a; // 4294967295

	printf("%u\n", b);

	return 0;
}

#elif defined APP_4
// islem oncesi otomatik tur donusumleri
// degiskenler farkli tuden se derleyici ayni ture donusturup islem yapar
int main()
{
	return 0;
}

#elif defined APP_5
int main()
{
	return 0;
}

#elif defined APP_6 
int main()
{
	return 0;
}
#endif