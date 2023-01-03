#include <stdio.h>
#include "other.h"

// ARM architecture uses RISC command system
// RISK command are 4-byte long
// CISC commands vary in length
// 3- Commands are primitive
// Commands are few but fast

// RISC processors always work with register
//		commands have 3 operands
// CISC processors can work with register memory
//		commands generally have 2 operands

#define APP2
// extern type specifier

// Writing a program in large source file:
// Makes it harder to edit the code
// Increases compile time
// 
// If files are seperated changed files can be compiled individually
// And all of them linked again
// Linker is generally faster than compiler
// 
// All the files that make up to a project called translation unit,
// also called module
// 
// How to call one module's function or global variable?
// via external linkage
// 
// a global variable by deafult has external linkage
// to make a global variable internal linkage we can use "static"
// storage class specifier
// 
// external linkage record of compiler:
// when there is global object usage in translation units
// there are blank spaces in the places of global object calls
// in the object files
// linker fills the blank spaces
// 
// function prototype decleration is considered external linkage
// 
// in one translation unit if there is function call but not declared?
// 
// for functions we do not need the extern keyword
// when there is a function decleration (prototype)
// compiler will assume that definition is in another file
// if there is not a definition for that function there will be
// a linker error
// compiler notes down missing address parts of functions and variables
// in a part of an object file
// elf : portable executable
// 
// ...end

#ifdef APP1

int g_x;			// external linkage: other modules can use it
static g_y;			// internal linkage: other modules can not use it

void foo(void) {}			// external linkage
static void bar(void) {}	// internal linkage
// How to use a global variable declared in another translation unit?
// there is a global object in other module
// to use in other modules we need to specifically specify
// it as external variable in every other file
// if linker cannot find this call there will be a linker error
extern int g_z;			// decleration
int g_v;				// decleration and definition
extern int g_w = 10;	// decleration and definition, initial value given


int main(void)
{
	g_z = 10;
	return 0;
}

#elif defined APP2
// tentative definition:
// when a variable is defined multiple times in a translation unit
// only one initial value is allowed


int g_x;
int g_x = 10;
int g_x;
//int g_x = 20;		// invalid

int main(void)
{
	printf("Tentatively defined g_x is : %d\n", g_x);
	return 0;
}

#endif