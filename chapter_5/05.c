#include<stdio.h>

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);

int main(int argc, char *argv[])
{
    char greeting[]  = "Hello folk!";

    mystrncpy(greeting, "Howdy!", 5);
    printf("copy: %s\n", greeting);

    mystrncat(greeting, " Welcome. :)", 9);
    printf("cat: %s\n", greeting);

    int result = mystrncmp(greeting, "Howdy", 5);
    printf("cmp: %s\n", result ? "equal" : "not equal");

    return 0;
}

void mystrncpy(char *s, char *t, int n)
{
    while(n-- && *s != '\0' && *t != '\0') {
        *s++ = *t++;
    }
    if (n > 0) {
        *s = 0;
    }
}

void mystrncat(char *s, char *t, int n)
{
    while (*s != '\0') {
        s++;
    }
    while (n-- && *t != '\0') {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}

int mystrncmp(char *s, char *t, int n)
{
    while(n-- && *s != '\0' && *t != '\0') {
        if (*s != *t) {
            return 0;
        }
        s++;
        t++;
    }
    return 1;
}
