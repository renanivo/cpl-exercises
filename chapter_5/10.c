#include <stdlib.h>
#include <stdio.h>
#define MAX_ARGUMENTS 1000

int arguments[MAX_ARGUMENTS], arguments_index = 0;


int pop()
{
    return arguments[--arguments_index];
}

void push(int value)
{
    arguments[arguments_index++] = value;
}

int main(int argc, char *argv[])
{
    int i, a, b;

    for (i = 1; i < argc; ++i) {
        if (argv[i][0] >= '0' && argv[i][0] <= '9') {
            push(atoi(&argv[i][0]));
        } else {
            switch (argv[i][0]) {
                case '+':
                    a = pop();
                    b = pop();
                    push(a + b);
                    break;
                case '*':
                    a = pop();
                    b = pop();
                    push(a * b);
                    break;
                case '-':
                    a = pop();
                    b = pop();
                    push(a - b);
                    break;
                case '/':
                    a = pop();
                    b = pop();
                    push(a / b);
                    break;
            }
        }
    }

    printf("%d", pop());

    return 0;
}
