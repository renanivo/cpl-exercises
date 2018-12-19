#include <stdio.h>

int main() {
    int blank_count = 0,
        tab_count = 0,
        new_line_count = 0,
        total_chars = 0,
        character;

    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            blank_count++;
        } else if (character == '\t') {
            tab_count++;
        } else if (character == '\n') {
            new_line_count++;
        }
        total_chars++;
    }

    printf("blanks: %d\n", blank_count);
    printf("tabs: %d\n", tab_count);
    printf("new lines: %d\n", new_line_count);
    printf("total_characters: %d\n", total_chars);
}
