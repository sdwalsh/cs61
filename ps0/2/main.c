#include <stdio.h>
#include <ctype.h>

int main() {
    unsigned long number_of_bytes = 0;
    unsigned int number_of_lines = 0;
    unsigned int number_of_words = 0;
    unsigned int current_word_length = 0;

    while (1) {
        int c = fgetc(stdin);
        if (c == EOF) {
            break;
        }
        number_of_bytes++;
        if (isspace(c)) {
            if (c == 10) {
                number_of_lines++;
            }
            if (current_word_length > 0) {
                number_of_words++;
                current_word_length = 0;
            }
        } else {
            current_word_length++;
        }
    }

    if (current_word_length > 0) {
        number_of_words++;
    }

    fprintf(stdout, "%u %u %lu\n", number_of_lines, number_of_words, number_of_bytes);
    return 0;
}