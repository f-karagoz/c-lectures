#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define APP_4

#ifdef APP_1
// COIN FLIP - PROBABILITY
#define TRYNUM			100000000

int main(void)
{
	unsigned long long head, tail;
	int val;
	double head_ratio, tail_ratio;

	srand(time(NULL));
	
	head = tail = 0;

	for (unsigned long long i = 0; i < TRYNUM; ++i)
	{
		val = rand() % 2;
		if (val == 0)
			++head;
		else
			++tail;
	}

	head_ratio = (double)head / TRYNUM;
	tail_ratio = (double)tail / TRYNUM;

	printf("head: %.8f, tail: %.8f\n", head_ratio, tail_ratio);

	return 0;
}

// notes: ansii terminal escape codes
// excape codes terminal cursor
// 0x1B

#elif defined APP_2

#define TRYNUM			100000000

int main(void)
{
	double result;

	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		result = (double)rand() / RAND_MAX;
		printf("%f\n", result);
	}
	return 0;
}

#elif defined APP_3

#include <math.h>
#include <time.h>

#define N			100000000
int main(void)
{
	double x, y;
	unsigned long long k;
	double pi;

	srand(time(NULL));

	k = 0;

	for (unsigned long long i = 0; i < N; ++i)
	{
		x = (double)rand() / RAND_MAX;
		y = (double)rand() / RAND_MAX;
		if (sqrt(pow(x, 2) + pow(y, 2)) < 1)
			++k;
	}

	pi = 4. * k / N;
	printf("%f\n", pi);

	return 0;
}
// WIN32 API functions
// possix 3rd party...
#elif defined APP_4
// Setting: Properties > Advanced > Character set > Not set

#include <Windows.h>
#include <conio.h>

#define UP			0
#define RIGHT		1
#define DOWN		2
#define LEFT		3

void get_console_size(int* height, int* width)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	*width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	*height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void hide_cursor(void)
{
	CONSOLE_CURSOR_INFO cinfo;

	cinfo.dwSize = 100;
	cinfo.bVisible = FALSE;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cinfo);
}

void writec(int row, int col, char ch)
{
	COORD coord = { col, row };
	DWORD dw;

	WriteConsoleOutputCharacterA(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, coord, &dw);
}

int main(void)
{
	int rowsize, colsize;
	int row, col;
	int direction;
	int ch;

	get_console_size(&rowsize, &colsize);
	hide_cursor();

	row = 10, col = 10;
	direction = RIGHT;

	for (;;) {
		writec(row, col, '*');

		Sleep(100);


		if (_kbhit()) {
			ch = _getch();
			switch (ch) {
			case 'w':
				direction = UP;
				break;
			case 's':
				direction = RIGHT;
				break;
			case 'z':
				direction = DOWN;
				break;
			case 'a':
				direction = LEFT;
				break;
			case 'p':
				_getch();
				break;
			case 'q':
				goto EXIT;
			}
		}

		writec(row, col, ' ');

		switch (direction) {
		case UP:
			if (row == 0)
				row = rowsize - 1;
			else
				--row;
			break;
		case RIGHT:
			if (col == colsize - 1)
				col = 0;
			else
				++col;
			break;
		case DOWN:
			if (row == rowsize - 1)
				row = 0;
			else
				++row;
			break;
		case LEFT:
			if (col == 0)
				col = colsize - 1;
			else
				--col;
			break;
		}
	}
EXIT:

	return 0;
}
// _kbhit
#endif