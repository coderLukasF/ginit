#include <stdio.h>
#include <string.h>
#include "returnnewtext.h"
#include <unistd.h>

const char* expand(const char *input_text) {
    if (strcmp(input_text, "e-fn") == 0) {

        static char cwd[100];

        if (getcwd(cwd, sizeof(cwd)) != NULL) {}

        char *shortPathBuffer = strrchr(cwd, '/');
        static char shortPath[100];

        snprintf(shortPath, sizeof(shortPath), "%s", shortPathBuffer + 1);

        return shortPath;
    }
    return input_text;
}
