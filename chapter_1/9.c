#include <stdio.h>

int main() {
    int character,
        blank_quantity;

    while ((character = getchar()) != EOF) {
        if (character == ' ') {
            blank_quantity++;

            if (blank_quantity == 1) {
                printf("%c", character);
            }
        } else {
            blank_quantity = 0;
            printf("%c", character);
        }
    }
}
