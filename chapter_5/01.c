#include<stdio.h>
#include<ctype.h>

#include "getch.c"


int issign(char c);
int getint(int *pn);
int getchnext();

int issign(char c)
{
    return c == '+' || c == '-';
}

int getchnext() {
    int c;
    while (isspace(c = getch()));
    return c;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign, is_sign;

    c = getchnext();

    if (!isdigit(c) && c != EOF && !issign(c)) {
        printf("ERROR: %c it is not a number\n", c);
        return EOF;
    }

    sign = (c == '-') ? -1 : 1;
    if (issign(c))
        c = getchnext();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(int argc, char *argv[])
{
    int number;
    while (getint(&number) != EOF) {
        printf("%d\n", number);
    }
    return 0;
}
