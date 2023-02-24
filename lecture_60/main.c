#include <stdio.h>

#define APP1

#ifdef APP1

int main(void)
{
	return 0;
}

#elif defined APP2

int main(void)
{
	return 0;
}

#elif defined APP3

int main(void)
{
	return 0;
}

#endif