#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void cat(int argc, char *argv[]) {
    for (int x = 1; x < argc; x++) {
        FILE* file = fopen(argv[x], "r");
        if (file == NULL) {
            fprintf(stdout, "file not found, try again %s\n", argv[x]);
            return;
        }

        while (!feof(file) && !ferror(file) && ferror(stdout)) {
            char buf[BUFSIZ];
            size_t length = fread(buf, 1, BUFSIZ, file);
            (void) fwrite(buf, 1, length, stdout);
        }

        if (ferror(file) || ferror(stdout)) {
            fprintf(stderr, "%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (file != stdin) {
            fclose(file);
        }
    }
}

int main(int argc, char *argv[]) {
    cat(argc, argv);
}