/**
 Document:      main.c
 Author:            Furkan Karagoz
 Date:               Jan 2023
 Place:              Istanbul / Turkey
 */

#include <stdlib.h>
#include <stdio.h>
#include "mytime.h"

// Usage: In order to compile for different tasks use the correct task define

//#define TASK1
//#define TASK2
#define TASK3
//#define TEST1
//#define TEST2

#ifdef TASK1

int main(void)
{
    time_t t;
    struct tm* pt;
    char* days[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    t = time(NULL);
//    t = 2 * YEAR_SEC + 31 * DAY_SEC + 28 * DAY_SEC;       // 29/02/1972 correct
//    t = 3 * YEAR_SEC;                                     // 31/12/1972 correct
    pt = mylocaltime(&t);

    printf("%02d/%02d/%04d %02d:%02d:%02d - %s\n", pt->tm_mday, pt->tm_mon + 1,
        pt->tm_year + 1970, pt->tm_hour, pt->tm_min, pt->tm_sec, days[pt->tm_wday]);
    printf("%d\n", pt->tm_yday);
    
    

    return 0;
}

#elif defined TASK2

int main(void)
{
    time_t t = time(NULL);
    char *str;
    
    str = myctime(&t);
    
    printf ("%s", str);
    
    return 0;
}

#elif defined TASK3

int main(void)
{
    char* asc;
    struct tm *ptm;
    time_t t;
    
    t = time(NULL);
    
    ptm = mylocaltime(&t);
    
    asc = myasctime( ptm );

    printf("%s", asc);
    
    return 0;
}

#elif defined TEST1

#include <time.h>

int main()
{
    time_t seconds;

    seconds = time(NULL);
    printf("Seconds since January 1, 1970 = %ld\n", seconds);

    return(0);
}

#elif defined TEST2

#include <time.h>

#define STR_SIZE 100

int main (void)
{
    time_t t = time(NULL);
    char *str = (char*) malloc( STR_SIZE * sizeof(char));
    
    str = ctime(&t);
    
    printf ("Time is : %s", str);
    
}

#endif
