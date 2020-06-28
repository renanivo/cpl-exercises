#include<assert.h>
#include<stdio.h>
#include"getline.c"
#define MAXLINE 10000


int main(int argc, char *argv[])
{
    char input[MAXLINE];

    mygetline(input, MAXLINE);
    printf("%s", input);

    return 0;
}
