#include<stdio.h>

int strend(char s[], char t[]);


int main(int argc, char *argv[])
{
    int result;
    char full_name[] = "john smith";
    char surname[] = "smith";

    result = strend(full_name, surname);
    printf(
        "Ends with \"%s\" ends with \"%s\": %d\n",
        full_name,
        surname,
        result
    );
    return 0;
}


int strend(char *s, char *t) {
    int size;

    for (; *s != '\0'; ++s);
    for (; *t != '\0'; ++t, ++size);

    while(size-- > 0) {
        if (*t != *s) {
            return 0;
        }
        t--;
        s--;
    }

    return 1;
}
