void copy(char from[], char to[]);
void detab(char line[], int start_at, int tab_spaces_length, int max_line);
void entab(char line[], int start_at, int tab_spaces_length, int max_line);

void copy(char from[], char to[])
{
    int i;

    for (i = 0; from[i] != '\0'; ++i) {
        to[i] = from[i];
    }

    to[i] = '\0';
}

void entab(char line[], int start_at, int tab_spaces_length, int max_line) {
    int i, j = 0, k = 0, l = 0, tabs_length = 0, blanks_length = 0, start = -1, stop = -1;
    char entabed[max_line];

    for (i = start_at; i < max_line; ++i) {
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

void detab(char line[], int start_at, int tab_spaces_length, int max_line) {
    int i, j, pad = 0;
    char detabed[max_line];

    for (i = start_at; i < max_line && line[i] != '\0'; ++i) {
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
