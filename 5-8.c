#include <stdio.h>
static char daytab[2][13] = { 
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
}; 

int main(void)
{
    int day_of_year(int, int, int);
    void month_day(int, int, int*, int*);
    int doy = day_of_year(2022, 6, 1);
    int m, d;
    month_day(2022, doy, &m, &d);
    printf("day of year: %d\n", doy);
    printf("month: %d, day: %d\n", m, d);
    return 0;
}


/* day_of_year:  set day of year from month & day */ 
int day_of_year(int year, int month, int day) 
{ 
    if(year < 1 || month > 12 || month < 1)
        return -1;
    int i, leap; 
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    for (i = 1; i < month; i++) 
        day += daytab[leap][i]; 
    return day;
}

/* month_day:  set month, day from day of year */ 
void month_day(int year, int yearday, int *pmonth, int *pday) 
{ 
    if(year < 1 || yearday > 366) {
        *pmonth = -1; 
        *pday = -1; 
        return;
    }

    int i, leap; 
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    for (i = 1; yearday > daytab[leap][i]; i++) 
        yearday -= daytab[leap][i]; 
    *pmonth = i; 
    *pday = yearday; 
} 
