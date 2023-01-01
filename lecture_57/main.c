#include <stdio.h>
#include <stddef.h>
#include <stdint.h>		// since c99
#include <stdbool.h>	// since c99

#define APP2

#ifdef APP1

int main(void)
{
	wchar_t wc;		/* stddef.h */
	int8_t i8;		/* stdint.h */
	int32_t i32 = 10;
	uint32_t u32 = 20;
	
	printf("int32 value is: %d, and uint32 value is: %d\n", i32, u32);

	intmax_t maxint = 12345;

	printf("printing a max int type: %jd\n", maxint);

	int16_t a;		/* defined as short */
	int_fast16_t b;	/* defined as int */

	bool foo;		/* this is not a type it is a define to _Bool */

	return 0;
}

#elif defined APP2
// Bildirim islerinde yer belirleyicileri ve tur netileyicileri
// storage class specifiers and type qualifiers in decleration operations


int main(void)
{
	// in below code:
	// int is "type specifier"
	// a, *pa, and aa[5] is "declerator"
	// initial values are not declerators
	// <type_specifier> <declerator> [ = iniital_value], <declerator> [ = initial_value], ...
	int a, * pa, aa[5];
	// <type_specifier> [storage_class_specifier] [type_qualifier] <declerator> [ = initial_vlue] ...
	// type specifier, storage class spefier, and type qualifiers can be placed in any order
	// generally:
	// 1- type qualifier, 2- storage class specifier, 3- type specifier 
	const static int b;
	// aggregate types such as: structure, unions, and arrays
	// get initial value by squcicly paranthese {}
	// non-affregate types can be given inital value this way too
	int c = { 9 };
	
	// storage class specifiers:
	// auto, register, static, extern
	// type qualifiers:
	// const, volatile
	// 
	// two storage class specifiers cannot be used together
	// type qualifiers can be used
	static const volatile d = 10;

	// "auto" is meaningless in the moden versions of C
	// auto key word changed to a type specifier in c++11

	// "register" is also meaningles in the current version of C
	// Traditional Intel CPUs (CICK arhitecture) have 14 registers
	// RISK architecture systems have more registers
	// Registers' bit-lenght also defines how big proccesses can CPU handle
	// World's firs microprocessor is accepted as Intel 8080 released in 1974.
	// 8080 was 8-bit processor. Then; 16-bit 8086, 32-bit 80386, and 64-bit Pentium followed.
	// Intel's 32-bit is called x32, and 64-bit processors called x64.
	// ARM processors first designed as 32-bit, then they got upgraded to 54-bit as well.
	// As there is no popular need for 128-bit processes, 128-bit processors are not common. (except GPUs)
	// 
	// c = a + b
	// 
	// MOV reg1, a
	// MOV reg2, b
	// ADD reg1, reg2
	// MOV c, reg1

	return 0;
}

#endif