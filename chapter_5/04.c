#include<stdio.h>
#define MAX_SIZE 100

int strend(char s[], char t[]);


int main(int argc, char *argv[])
{
    int result;
    char full_name[MAX_SIZE]= "john smith";
    char surname[MAX_SIZE]= "smith";

    result = strend(full_name, surname);
    printf(
        "Ends with \"%s\" ends with \"%s\": %d\n",
        full_name,
        surname,
        result
    );
    return 0;
}


int strend(char s[], char t[]) {
    int i, j;

    for (i = 0; s[i] != '\0'; ++i);
    for (j = 0; t[j] != '\0'; ++j);



    return 1;
}
