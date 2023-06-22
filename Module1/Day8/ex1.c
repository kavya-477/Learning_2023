#include <stdio.h>

int main() {
    FILE *sourceFile, *targetFile;
    char sourcePath[100], targetPath[100];
    char ch;

    printf("Enter the source file path: ");
    scanf("%s", sourcePath);

    printf("Enter the target file path: ");
    scanf("%s", targetPath);

    // Open the source file in read mode
    sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the target file in write mode
    targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy the contents of source file to target file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, targetFile);
    }

    printf("File copied successfully.\n");

    // Close the file pointers
    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
