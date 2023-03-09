#include <stdio.h>

#define APP3
/* Path Expressions */
// 
// There are two types of path expressions: absolute, relative.
// In path expressions, directory changes are expressed with '/' in Unix/Linux, '\' in Windows systems.
// However, Windows also supports the Unix/Linux format.
// /a/b/c.txt	/* Unix,Linux,MacOS (Windows supports) */ 
// \a\b\c.txt	/* Windows */
// 
// If the first character of a path is '/' or '\' it is an absolute path.
// In absolute path the path is expressed starting from the root.
// Relative path is expressed depending on the current workin directory.
// The operating programs are called process. Every process has a working directory.
// Process's working directory is predefined when it starts, however it can be changed
// during the runtime of the process.
// When a process calls another process the caller is a parent process, and the called is a child process.
// ...end...

#ifdef APP1
/* Get current working directory in MacOS */
#include <unistd.h>

int main(void)
{
	char buf[100];

	getcwd(buf, 100);	/* Gets the current working directory */
	puts(buf);

	chdir("/bin");		/* Changes the working directory */

	getcwd(buf, 100);
	puts(buf);

	return 0;
}

#elif defined APP2
/* Get current working directory in Windows */
#include <windows.h>

int main(void)
{
	char buf[256];

	GetCurrentDirectory(256, buf);

	puts(buf);

	return 0;
}

// In Windows operation systems process's working directory also
// includes the disc information. 
// The path consisting of the disc information is called 'full path'.
// Windows directories are case insensitive, unix systems are case sensitive.
// 

#elif defined APP3
/* File operations in C */

// fopen, fclose, fread, fwrite, fgets, ...
// File operations are hadled by the OS specific functions under the hood.
// The file operations are kind of wrapper functions.

// To do any operation over a file, the file needs to be opened first.
// Opening a file is an abstraction. The OS does some opearations over the file.
// 
// FILE *fopen(const char *path, const char *mode);
// 
// typedef struct {
//     ...
// } FILE;
// 
// The first parameter of fopen() is absolute (or relative) path of a file.
// Second paramter is the 'open mode'.
// The open mode parameter is OS specific.
// 
// Open Mode	| Meaning
// ------------------------------------
// r			| Open existing file, only read operation allowed
// r+			| Open existing file, read and write operation allowed
// w			| If file exist clear the file (truncate) if not create the file,
//				| only write operation allowed
// w+			| Same as above, also read allowed
// a			| If file exists opens without clearing if not creates it (append),
//				| only read allowed (written content if added to the end)
// a+			| Same as obove, also read allowed
// 
// A file maybe unable to open. In this situation fopen() fails.
// The name of the file may be incorret.
// In operating systems there is a limited number files that a process can open.
// Furthermore, there may be access control applied over a file.
// These might as well cause fopen() to fail.
// 
// When fopen() succeeds it return a pointer to a FILE type. The content of the type 
// is not specified by the C standard and it not a concern for the programmer.
// The FILE address is also called 'stream'.
// The FILE object can be used by other file operation functions later on.
// 
// An open file needs to be closed. Files are also closed when a process ends (on the exit event).
// Open files also consumes resources.
// So, it is a good practice to close files if not handled currently.
// Also, remeber that there is a limit on number of files can be opened by a single process.
// 
// ...end...

#include <stdlib.h>

int main(void)
{
	// To build:
	// Project Settings > C/C++ > SDL cheks > No

	FILE* f;

	if (f = fopen("test.txt", "r") == NULL)
	{
		fprintf(stderr, "Cannot open file!...\n");
		exit(EXIT_FAILURE);
	}

	printf("Ok\n");

	return 0;
}

#endif