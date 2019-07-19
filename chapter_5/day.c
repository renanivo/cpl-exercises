static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap(int year);
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);


/* is_leap: returns whether a year is leap or not */
int is_leap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

/* day_of_year: get day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = is_leap(year);

    for(i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

/* month_day: set month day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = is_leap(year);

    for (
        i = 1;
        yearday > 0 && year > 0 && yearday > daytab[leap][i];
        i++
    ) {
        yearday -= daytab[leap][i];
    }
    *pday = yearday;

    if (yearday > 0 && year > 0) {
        *pmonth = i;
    } else {
        *pmonth = -1;
    }
}
