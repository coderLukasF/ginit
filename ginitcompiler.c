#include <stdio.h>
#include <string.h>
#include "ginitcompiler.h"
#include "returnnewtext.h"

int compile_ginit(const char *input_path, const char *output_path) {
    FILE *fptr;
    FILE *out;
    fptr = fopen(input_path, "r");
    out = fopen(output_path, "w");

    char myString[100];

    char newLine[105];

    char fileLine[1064];

    char bufferLine[105];

    fprintf(out, "#!/bin/bash\n");

    int i;

    int j = 0;
    int isEmbeddable = 0;

    int startI;
    int endI;

    char buffer1[64];
    char buffer2[100];
    char buffer3[100];

    while (fgets(myString, sizeof(myString), fptr)) {
        //myString[strcspn(myString, "\n")] = '\0';

        snprintf(bufferLine, sizeof(bufferLine), "git %s", myString);

        for (int i = 0; i < sizeof(bufferLine); i++) {
            if (bufferLine[i] == '*') {

                if (j == 0) {
                    startI = i;
                }
                else if (j == 1) {
                    endI = i;
                    isEmbeddable = 1;
                    strncpy(buffer1, bufferLine, startI);
                    buffer1[startI] = '\0';

                    strcpy(buffer2, bufferLine);

                    char contentsBuffer[64];
                    int pos = 0;

                    for (int i = startI + 1; i < endI; i++) {
                        if (pos < (int)sizeof(contentsBuffer) - 1) {
                            contentsBuffer[pos++] = bufferLine[i];
                        }
                    }

                    contentsBuffer[pos] = '\0';
                    
                    char contentsFull[64];

                    snprintf(contentsFull, sizeof(contentsFull) + 2, "e-%s", contentsBuffer);

                    const char *finalText = expand(contentsFull);

                    snprintf(buffer3, sizeof(buffer3), "%s%s%s", buffer1, finalText, buffer2 + endI + 1);
                    snprintf(bufferLine, sizeof(bufferLine), "%s", buffer3);

                    // hard reset
                    isEmbeddable = 0;
                    memset(contentsBuffer, 0, sizeof(contentsBuffer));
                    pos = 0;
                    memset(contentsFull, 0, sizeof(contentsFull));
                    finalText = NULL;
                    memset(buffer1, 0, sizeof(buffer1));
                    memset(buffer2, 0, sizeof(buffer2));
                    memset(buffer3, 0, sizeof(buffer3));
                    startI = 0;
                    endI = 0;
                }
                
                j = !j;

            }
        }

        snprintf(newLine, sizeof(newLine), "%s", bufferLine);


        //printf("%s", myString);
        //printf("%s", newLine);

        fprintf(out, "%s", newLine);
    }

    fclose(fptr);
    fclose(out);

    return 0;
}