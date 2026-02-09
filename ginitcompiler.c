#include <stdio.h>
#include <string.h>
#include "ginitcompiler.h"

int compile_ginit(const char *input_path, const char *output_path) {
    FILE *fptr;
    FILE *out;
    fptr = fopen(input_path, "r");
    out = fopen(output_path, "w");

    char myString[100];

    char newLine[105];

    char fileLine[1064];

    fprintf(out, "#!/bin/bash\n");

    int i;
    while (fgets(myString, 100, fptr)) {
        //myString[strcspn(myString, "\n")] = '\0';

        printf("%s", myString);
        snprintf(newLine, sizeof(newLine), "git %s", myString);
        printf("%s", newLine);

        fprintf(out, "%s", newLine);
    }

    fclose(fptr);
    fclose(out);

    return 0;
}