#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void changeCase(FILE *sourceFile, FILE *targetFile, int caseOption) {
    char ch;
    int sentenceStart = 1;

    while ((ch = fgetc(sourceFile)) != EOF) {
        if (caseOption == 'u') {
            fputc(toupper(ch), targetFile);
        } else if (caseOption == 'l') {
            fputc(tolower(ch), targetFile);
        } else if (caseOption == 's') {
            if (sentenceStart) {
                fputc(toupper(ch), targetFile);
                sentenceStart = 0;
            } else {
                fputc(tolower(ch), targetFile);
            }
            if (ch == '.' || ch == '?' || ch == '!') {
                sentenceStart = 1;
            }
        } else {
            fputc(ch, targetFile);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp [-u|-l|-s] source_file target_file\n");
        return 1;
    }

    char *option = argv[1];
    char *sourcePath = argv[2];
    char *targetPath = argv[3];

    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    FILE *targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    int caseOption = 0;

    if (option != NULL && strlen(option) == 2 && option[0] == '-') {
        caseOption = option[1];
    }

    changeCase(sourceFile, targetFile, caseOption);

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
