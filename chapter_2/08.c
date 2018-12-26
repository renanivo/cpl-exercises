#include <stdio.h>

int htoi(char input_hex[]);
int get_hex_value(char hex_digit);


int main() {
    printf("7:\t%d\n", htoi("7"));
    printf("f:\t%d\n", htoi("f"));
    printf("B:\t%d\n", htoi("B"));
    printf("X:\t%d\n", htoi("X"));
    printf("F9:\t%d\n", htoi("F9"));
    printf("F00:\t%d\n", htoi("F00"));
    printf("0x90F:\t%d\n", htoi("0x90F"));

    return 0;
}

int htoi(char input_hex[]) {
    int i, digit, result = 0;

    for (i = 0; i < input_hex[i] != '\0'; ++i) {
        result = result * 16;
        result = result + get_hex_value(input_hex[i]);
    }

    return result;
}

int get_hex_value(char hex_digit) {
    if (hex_digit >= '0' && hex_digit <= '9') {
        return hex_digit - '0';
    }
    if (hex_digit >= 'a' && hex_digit <= 'f') {
        return hex_digit - 'a' + 10;
    }
    if (hex_digit >= 'A' && hex_digit <= 'F') {
        return hex_digit - 'A' + 10;
    }
    return 0;
}
