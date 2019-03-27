#include <stdio.h>

#define  swap(t, x, y) \
    t x ## y = x; \
    x = y; \
    y = x ## y;

int main(int argc, char *argv[])
{
    int a = 1, b = 2;

    swap(int, a, b);

    printf("a: %d,  b: %d\n", a, b);

    char x = 'x', y = 'y';

    swap(char, x, y);

    printf("x: %c, y: %c\n", x, y);

    return 0;
}
