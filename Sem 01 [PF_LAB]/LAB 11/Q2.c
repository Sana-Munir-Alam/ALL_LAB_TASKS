#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char FileName[100];
    char line[256];
    int LineNumber = 1;

    printf("\nEnter the File Name to open (e.g Animal.txt): ");
    scanf("%s", FileName);
    file = fopen(FileName, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", FileName);
        return 1;
    }
    printf("Contents of the file with line numbers:\n\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", LineNumber, line);
        LineNumber++;
    }
    fclose(file);
    return 0;
}
