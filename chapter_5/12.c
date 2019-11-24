#include <stdio.h>
#include "lines.c"
#include "tabs.c"
#define MAX_LINE 1000
#define MAX_INPUT_STR 1000

void parse_arguments(char *argv[], int argc, int *start_at, int *tab_spaces_length);
int str_to_int(char input[], int max_input_str);

int main(int argc, char *argv[])
{
    int size, start_at = 0, tab_spaces_length = 4;
    char line[MAX_LINE];

    parse_arguments(argv, argc, &start_at, &tab_spaces_length);
    printf("start at: %d\ntab spaces: %d\n", start_at, tab_spaces_length);

    while ((size = readline(line, MAX_LINE)) > 0) {
        entab(line, start_at, tab_spaces_length, MAX_LINE);
        printf("%s", line);
    }

    return 0;
}

int str_to_int(char input[], int max_input_str) {
    int i, number = 0;
    for (i = 0; i < max_input_str && input[i] != '\0'; ++i) {
        number = 10 * number + (input[i] - '0');
    }
    return number;
}

void parse_arguments(char *argv[], int argc, int *start_at, int *tab_spaces_length) {
    int i;

    for (i = 0; i < argc; ++i) {
        if (argv[1][0] == '-') {
            switch (argv[i][1]) {
                case 'm':
                    *start_at = str_to_int(argv[++i], MAX_INPUT_STR);
                    break;
                case 'n':
                    *tab_spaces_length = str_to_int(argv[++i], MAX_INPUT_STR);
                    break;
            }
        }
    }
}
