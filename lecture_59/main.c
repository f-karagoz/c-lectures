#include <stdio.h>

#define APP2

#ifdef APP1
// Compiling and linking files, build tools, make

// include operation takes effect before compile in the preprocessor
// these files act as one module as result of preprocessor pasting the file
// in this demonstration with extern declerations purpose is to
// put the code into compiler as different modules
// 
// the build system of the IDE compares source file's date with
// object file's date to select the files to recompile
// therefore build system can fail if system clock changes
// in this situations programmer should run "rebuild" or "build all"
// 
// To compile and link (build) we can do:
// 
// 1) MANUALLY compile and link files (developer command promt of VS)
// 
// "cl" compiler and link.exe:
// 
// cl /c main.c
// cl /c file1.c
// link /OUT:test.exe main.obj file1.obj
// 
// OR we can do all of this by one command line
// cl /Fe:test.exe main.c file1.c
// 
// "gcc" and "clang" compilers:
// only compile is -o option
// "ld" does not inlude libraries or "start-up" files by deafult
// gcc can also link files (runs ld linker on the background)
// 
// gcc -c main.c
// gcc -c file1.c
// gcc -o test main.o file1.o
// 
// OR we can do all of this by one command line
// 
// gcc -o test main.c file1.c
// 
// 
// 2) Build automation tools
// In the Visual Studio when we press ctrl+F5 the IDE runs
// Microsoft's "msbuild" in the background
// Popular build tools are MS's "MSBuild" and GNU's "make"
// GNU's make is based on unix's "make"
// MS also has make-like tool called "nmake"
// Make based tools utilize "Makefile" directives to build the project
// These makes files are written with a language has syntax and sematics
// MSBuild reads XML based ".vcxproj" file to build the project
// 
// There are also high-level build tools
// These tools utilize low-level build tools
// and present user with easy to use interface
// CMake, QMake
// QTCreater uses QMake
// 
// make will process a file named "Makefile" if ow specified
// below is a make file example:
// ******** FILE START *******
// # Makefile
// 
// test: sample.o mample.o
//		gcc -o test sample.o mample.o
// 
// sample.o: sample.c
//		gcc -c sample.c
// mample.o: mample.c
//		gcc -c mample.c
// 
// clean:
//		rm -f *.o
//		rm -f test
// ******** FILE END *******
// 
// ...end

void foo(void);

extern int g_x;

int main(void)
{
	g_x = 20;

	foo();

	printf("%d\n", g_x);

	return 0;
}


#elif defined APP2
// static, storage type specifier
// static behaviour:
// static variables behave differently for global and local variables

// If a global variable is declared as "static"
// that file cannot be used by other modules
// even if that file is specified as "external" in other modules
// static global variables have internal linkage
// 
// Different modules can have static global variables with the same name
// 
// ...end

int main(void)
{
	return 0;
}

#endif