#include <stdio.h>

int main() {
    unsigned long length = 0;
    while (fgetc(stdin) != EOF) {
        length++;
    }
    fprintf(stdout, "%lu\n", length);
    return 0;
}