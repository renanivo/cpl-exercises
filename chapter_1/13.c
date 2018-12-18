#include <stdio.h>

int main() {
    int character;

    while ((character = getchar()) != EOF) {
        if (
            character == ' '
            || character == '\t'
            || character == '\n'
        ) {
            printf("\n");
        } else if (
            character == '.'
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
            printf("|");
        }
    }
}
