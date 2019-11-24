int readline(char line[], int max_line);

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
