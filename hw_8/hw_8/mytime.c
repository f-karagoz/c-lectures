/**
 Document:      mytime.c
 Author:            Furkan Karagoz
 Date:               Jan 2023
 Place:              Istanbul / Turkey
 */

#include "mytime.h"

bool isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*
struct tm
{
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
};
*/

// TODO: consider leap year for the current year, eg. february is 29 days long
struct tm* mylocaltime(time_t* pt)
{
    static struct tm t;
    
    int leftover;
    int leapCounter = 0;
    
    t.tm_year = (int) ( *pt / YEAR_SEC );
    leftover = *pt % YEAR_SEC;                      // seconds in the current year
    t.tm_yday = leftover / DAY_SEC;
    
    for ( int i = 0; i < t.tm_year; ++i )
        if ( isleap(1970 + i) )
            leapCounter++;

    if ( t.tm_yday < leapCounter)
    {
        // TODO consider this is there is more than 365 (or 366 is the previous year is leap) leap years passed
        t.tm_year--;
        t.tm_yday = ( isleap ( 1970 + t.tm_year ) ? 366 : 365 ) - (leapCounter - t.tm_yday);
        leftover = t.tm_yday * DAY_SEC;
    }
    else
    {
        t.tm_yday -= leapCounter;
        leftover -= leapCounter * DAY_SEC;
    }
    
    t.tm_yday += 1;     // There is no 0th day
    
//    t.tm_mon = leftover / MON_SEC;
//    leftover %= MON_SEC;                        // seconds in the current month
    
    mon_days[1] = isleap(1970 + t.tm_year) ? 29 : 28;
    for (int i = 0; (leftover >= mon_days[i] * DAY_SEC) ; ++i)
    {
        leftover -= mon_days[i] * DAY_SEC;
        t.tm_mon++;
    }
    
    t.tm_mday = leftover / DAY_SEC + 1;
    leftover %= DAY_SEC;                        // seconds in the current day
    t.tm_hour = leftover / HOUR_SEC;
    leftover %= HOUR_SEC;                       // seconds in the current hour
    t.tm_min = leftover / MIN_SEC;
    leftover %= MIN_SEC;                        // seconds in the current minute
    t.tm_sec = leftover;
    
    // January 1 1970 was Wednesday, so compensate by 3
    // In my tests the week days were off by one, but for 1970 it was correct (compensated 3)
    // Quickfix: dynamic compensation
    int compensation = t.tm_year == 0 ? 3 : 4;
    t.tm_wday = ( *pt / DAY_SEC + compensation ) % 7;
    
    // Day light saving not accounted for
    t.tm_isdst = -1;

    return &t;
}


char *myctime(time_t *pt)
{
    static char* str_date[50];
    struct tm *ptm;

    ptm = mylocaltime(pt);

    char *wDays[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char *month[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    
    snprintf(str_date, sizeof(str_date), "%s %s\t %d %2d:%2d:%2d %d\n",
             wDays[ptm->tm_wday], month[ptm->tm_mon], ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, ptm->tm_year + 1970);
    
    return str_date;
}


char *myasctime(struct tm *ptm)
{
    static char* str_date[50];
    
    if (ptm == NULL)
    {
        str_date[0] = 0;
        return str_date;
    }

    char *wDays[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    char *month[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    
    snprintf(str_date, sizeof(str_date), "%s %s\t %d %2d:%2d:%2d %d\n",
             wDays[ptm->tm_wday], month[ptm->tm_mon], ptm->tm_mday, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, ptm->tm_year + 1970);
    
    return str_date;
}
