#include <stdio.h>

int main() {
    int Num;
    int count = 0;
    printf("Enter an positive integer (0-255): ");
    scanf("%d", &Num);
    if (Num > 255 || Num <0) {
        printf("Error!! The number exceeds 8 bits. Please enter a number between 0 and 255.\n");
        return 1;
    }
    count = 0;
    count += (Num & 1) ? 1 : 0;
    count += (Num & 2) ? 1 : 0;
    count += (Num & 4) ? 1 : 0;
    count += (Num & 8) ? 1 : 0;
    count += (Num & 16) ? 1 : 0;
    count += (Num & 32) ? 1 : 0;
    count += (Num & 64) ? 1 : 0;
    count += (Num & 128) ? 1 : 0;
    
    int result = count;
    printf("Number of 1s in the binary representation: %d\n", result);

    return 0;
}
