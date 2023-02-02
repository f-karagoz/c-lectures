#include <stdio.h>

#define APP2

#ifdef APP1

void disp_names(char **names)
{
	for (size_t i = 0; names[i] != NULL; ++i)
		puts(names[i]);
	//printf("%s\n", names[i]);
}

int main(void)
{

	char* names[] = {"ali", "veli", "selami", "ayse", "fatma", NULL};

	disp_names(names);

	return 0;
}

#elif defined APP2
#include <stdlib.h>

void* alloc_intarray(size_t size)
{
	int* pi;

	if ( (pi = (int*)malloc(size * sizeof(int))) == NULL)
	{
		fprintf(stderr, "cannot allocate array!\n");
		exit(EXIT_FAILURE);
	}

	return pi;
}

int main(void)
{
	int* pi;

	pi = alloc_intarray(10);

	for (int i = 0; i < 10; ++i)
		pi[i] = i;

	for (int i = 0; i < 10; ++i)
		printf("%d\n", pi[i]);
	puts("\n");

	free(pi);

	return 0;
}

#elif defined APP3

int main(void)
{
	char* names[] = {"ali","veli","osman"};
	void* pv;
	char** ppnames;

	pv = names;				// Valid, no need fpr type conversion

	ppnames = pv;			// Valid in C, invalid in C++

	ppnames = (int**)pv;	// Valid

	return 0;
}

// Tip:
// main functioon needs to have parameter as either "void" or "int, char**"

#elif defined TEST1
#include <stdint.h>


int main(void)
{
	uint8_t a1[10] = { 1,2,3 };
	uint16_t a2[10] = { 1,2,3 };
	uint32_t a3[10] = { 1,2,3 };
	int a4[10] = { 1,2,3 };

	printf("Size of a1 is : %zu\n", sizeof(a1));
	printf("Size of a2 is : %zu\n", sizeof(a2));
	printf("Size of a3 is : %zu\n", sizeof(a3));
	printf("Size of a4 is : %zu\n", sizeof(a4));


	return 0;
}

#endif