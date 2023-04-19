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

    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    char *dt = *daytab + leap; /* choose which table (since leap table is daytab[1]) */
    char *limit = dt + month; /* stop at dt + month*/

    /* we start from the second element so we start by dt += 1 */
    for (dt += 1; dt < limit; dt++)
        day += *dt;
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

    int leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
    char *dt = *daytab + leap; /* choose which table (since leap table is daytab[1]) */

    for (dt += 1; yearday > *dt; dt++) 
        yearday -= *dt; 
    *pmonth = dt - (*daytab + leap);  /* *daytab + leap is the original value of dt.
                                         We're just counting how many times we have
                                         incremented to find the month */
    *pday = yearday; 
} 
