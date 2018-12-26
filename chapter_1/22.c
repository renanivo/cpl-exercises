#include <stdio.h>
#define MAX_LINE 1000
#define TAB_SPACES_LENGTH 4
#define MAX_COLUMNS 80


void entab(char line[], int tab_spaces_length, int max_line);
void copy(char from[], char to[]);
int readline(char line[], int max_line);


int main(int argc, char *argv[])
{
    char line[MAX_LINE];
    int i;

    for (i = 0; readline(line, MAX_LINE) > 0; ++i) {
        entab(line, TAB_SPACES_LENGTH, MAX_LINE);
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


void entab(char line[], int tab_spaces_length, int max_line) {
    int i, j = 0, k = 0, l = 0, tabs_length = 0, blanks_length = 0, start = -1, stop = -1;
    char entabed[max_line];

    for (i = 0; i < max_line; ++i) {
        if (line[i] == ' ' && start < 0) {
            start = i;
        } else if (start >= 0 && line[i] != ' ') {
            stop = i;
            blanks_length = (stop - start);

            tabs_length = blanks_length / tab_spaces_length;
            blanks_length = blanks_length % tab_spaces_length;

            for (k = 0; k < tabs_length; ++j, ++k) {
                entabed[j] = '\t';
            }

            for (k = 0; k < blanks_length; ++j, ++k) {
                entabed[j] = ' ';
            }

            start = -1;
            stop = -1;
        }

        if (start < 0) {
            entabed[j] = line[i];
            ++j;
        }

        if (line[i] == '\0') {
            break;
        }
    }

    copy(entabed, line);
}
