#include <stdio.h>
#define MAX_LINE 1000
#define TARGET_LENGTH 80

int readline(char line[], int max_line);


int main(int argc, char *argv[])
{
    char line[MAX_LINE];
    int line_length, i;

    for (i = 0; (line_length = readline(line, MAX_LINE)) > 0; ++i) {
        if (line_length > TARGET_LENGTH) {
            printf("%d: %s", i, line);
        }
    }

    return 0;
}

int readline(char line[], int max_line)
{
    int current_char, i = 0;

    for (
        i = 0;
        i < max_line - 1
            && (current_char = getchar()) != EOF
            && current_char != '\n';
        ++i
    ) {
       line[i] = current_char;
    }

    if (current_char == '\n') {
        line[i] = current_char;
        ++i;
    }

    line[i] = '\0';

    return i;
}
