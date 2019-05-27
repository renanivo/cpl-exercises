#include<stdio.h>

void mystrcat(char *s, char *t);


void mystrcat(char *s, char *t) {
    while (*s != '\0') {
        s++;
    }
    while (*t != '\0') {
        *s = *t;
        s++;
        t++;
    }

    *s = '\0';
}

int main(int argc, char *argv[])
{
    char greeting[] = "hello";
    mystrcat(greeting, " folk");
    printf("%s\n", greeting);
    return 0;
}
