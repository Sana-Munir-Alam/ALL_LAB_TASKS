#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *OriginalFile, *CopiedFile;
    char OriginalFileName[100], CopiedFileName[100];
    char ch;

    printf("Enter the Original File Name: ");
    scanf("%s", OriginalFileName);
    printf("Enter the Secondary File Name: ");
    scanf("%s", CopiedFileName);

    OriginalFile = fopen(OriginalFileName, "r");
    if (OriginalFile == NULL) {
        printf("Error: Could not open source file %s\n", OriginalFileName);
        return 1;
    }
    CopiedFile = fopen(CopiedFileName, "w");
    if (CopiedFile == NULL) {
        printf("Error: Could not open destination file %s\n", CopiedFileName);
        fclose(OriginalFile);
        return 1;
    }

    while ((ch = fgetc(OriginalFile)) != EOF) {
        if (islower(ch)) {
            ch = toupper(ch);
        }
        fputc(ch, CopiedFile);
    }

    fclose(OriginalFile);
    fclose(CopiedFile);
    printf("File copied successfully!! All Lowercase Characters are now Uppercase.\n");
    return 0;
}
