#include<stdio.h>
#include<ctype.h>

#include "getch.c"


int getchnext();
int isfloat(char c);
int issign(char c);
float getfloat(float *pn);


int getchnext() {
    int c;
    while (isspace(c = getch()));
    return c;
}

int isfloat(char c)
{
    return isdigit(c) || c == '.';
}

int issign(char c)
{
    return c == '+' || c == '-';
}

/* getfloat: get next float from input into *pn */
float getfloat(float *pn)
{
    int c, sign, is_sign;
    float decimal_places = 0;

    c = getchnext();

    if (!isfloat(c) && c != EOF && !issign(c)) {
        printf("ERROR: %c it is not a number\n", c);
        return EOF;
    }

    sign = (c == '-') ? -1 : 1;
    if (issign(c))
        c = getchnext();

    for (*pn = 0; isfloat(c); c = getch()) {
        if (c == '.') {
            decimal_places = 0.1;
            continue;
        }
        if (!decimal_places) {
            *pn = 10 * *pn + (c - '0');
        } else {
            *pn = *pn + (c - '0') * decimal_places;
            decimal_places *= 0.1;
        }
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(int argc, char *argv[])
{
    float number;
    while (getfloat(&number) != EOF) {
        printf("%.2f\n", number);
    }
    return 0;
}
