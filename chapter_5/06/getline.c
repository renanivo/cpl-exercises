#include<stdio.h>

int mygetline(char *source, int max)
{
    int c, i;

    i = 0;
    while (--max > 0 && (c = getchar()) != EOF && c != '\0') {
        *(source++) = c;
    }

    if (c == '\n') {
        *(source++) = c;
    }
    *source = '\0';

    return i;
}
