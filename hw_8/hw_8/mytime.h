/**
 Document:      mytime.h
 Author:            Furkan Karagoz
 Date:               Jan 2023
 Place:              Istanbul / Turkey
 */

#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#define MIN_SEC         60
#define HOUR_SEC        ( MIN_SEC * 60 )
#define DAY_SEC         ( HOUR_SEC * 24 )
#define WEEK_SEC        ( DAY_SEC * 7 )
//#define MON_SEC         ( DAY_SEC * 30 )    // Not correct for every month
#define YEAR_SEC        ( DAY_SEC * 365 )

static int mon_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Handle Feb leap year situation

static bool isleap(int year);

extern struct tm* mylocaltime(time_t* pt);  // TASK-1 (also TASK-2)

extern char *myctime(time_t *pt);           // TASK-2 (also TASK-3)

extern char *myasctime(struct tm *ptm);     // TASK-3
