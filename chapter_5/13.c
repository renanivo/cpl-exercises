#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lines.c"
#define MAX_COLUMNS 1000
#define MAX_LINES 10000

int main(int argc, char *argv[])
{
    char line[MAX_COLUMNS], *lines_read[MAX_LINES], *buf_line;
    int i, size, lines_length, line_amount = 10;

    for (i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-n") == 0 && atoi(argv[++i]) > 0) {
            line_amount = atoi(argv[i]);
        }
    }

    for (i = 0; (size = readline(line, MAX_COLUMNS)) > 0; ++i) {
        buf_line = malloc(size);
        strcpy(buf_line, line);
        lines_read[i] = buf_line;
    }

    lines_length = i;
    if (line_amount > lines_length) {
        line_amount = lines_length;
    }
    for (i = lines_length - line_amount; i < lines_length; ++i) {
        printf("%02d: %s", i + 1, lines_read[i]);
    }

    return 0;
}
