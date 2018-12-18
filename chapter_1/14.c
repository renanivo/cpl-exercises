#include <stdio.h>

int main() {
    int character,
        character_frequencies[57],
        i, j;

    for (i = 0; i <= 57; ++i) {
        character_frequencies[i] = 0;
    }

    while ((character = getchar()) != EOF) {
        if (
            character == ' '
            || character == '\t'
            || character == '\n'
            || character == '.'
            || character == ','
            || character == '\''
            || character == '('
            || character == ')'
            || character == '['
            || character == ']'
            || character == '?'
            || character == '!'
        ) {
            continue;
        } else {
            character_frequencies[character - 'A']++;
        }
    }

    for (i = 0; i <= 57; ++i) {
        if (character_frequencies[i] == 0) {
            continue;
        }
        printf("%c: ", i + 'A');

        for (j = 0; j < character_frequencies[i]; ++j) {
            printf("|");
        }

        printf("\n");
    }
}
