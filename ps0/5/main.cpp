#include <cstring>
#include <cassert>
#include <cstdio>
#include <string.h>

char* mystrstr(char *s1, char *s2) {
    char *start;
    char *substring;

    while (start != NULL) {
        start = s1;
        substring = s2;
        while (substring != NULL && start != NULL) {
            if (*substring != *start) {
                break;
            }
            ++substring;
            ++start;
        }
        if (substring == NULL) {
            return s1;
        }
        ++s1;
    }

    return nullptr;
}

int main(int argc, char* argv[]) {
    assert(argc == 3);
    printf("strstr(\"%s\", \"%s\") = %p\n",
           argv[1], argv[2], strstr(argv[1], argv[2]));
    printf("mystrstr(\"%s\", \"%s\") = %p\n",
           argv[1], argv[2], mystrstr(argv[1], argv[2]));
    assert(strstr(argv[1], argv[2]) == mystrstr(argv[1], argv[2]));
}