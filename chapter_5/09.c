#include<stdio.h>

#include "day_pointers.c"

int main(int argc, char *argv[])
{
    int month, day;

    printf(
        "13/09/1987 is the %dth day of the year\n",
        day_of_year(1987, 9, 13)
    );

    month_day(1987, 256, &month, &day);
    printf(
        "The 256th day of 1987 is day %d of month %d\n",
        day,
        month
    );

    month_day(2019, -1, &month, &day);
    printf(
        "The -1th day of 2019 is day %d of month %d\n",
        day,
        month
    );

    month_day(-1, 37, &month, &day);
    printf(
        "The 37th day of -1 is day %d of month %d\n",
        day,
        month
    );

    return 0;
}
