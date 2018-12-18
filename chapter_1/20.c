#include <stdio.h>
#define MAX_LINE 1000
#define TAB_SPACES_LENGTH 4

void detab(char line[], int tab_spaces_length, int max_line);
void copy(char from[], char to[]);
int readline(char line[], int max_line);


int main(int argc, char *argv[])
{
    char line[MAX_LINE];
    int i;

    for (i = 0; readline(line, MAX_LINE) > 0; ++i) {
        detab(line, TAB_SPACES_LENGTH, MAX_LINE);
        printf("%s", line);
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


void copy(char from[], char to[])
{
    int i;

    for (i = 0; from[i] != '\0'; ++i) {
        to[i] = from[i];
    }

    to[i] = '\0';
}


void detab(char line[], int tab_spaces_length, int max_line) {
    int i, j, pad = 0;
    char detabed[max_line];

    for (i = 0; i < max_line && line[i] != '\0'; ++i) {
        if (line[i] == '\t') {
            for (j = 0; j < tab_spaces_length; ++pad, ++j) {
                detabed[i + pad] = ' ';
            }
            --pad;
        } else {
            detabed[i+pad] = line[i];
        }
    }

    copy(detabed, line);
}
