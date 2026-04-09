#include <stdio.h>

void MaxCutLength(int length, int *counter3, int *counter2, int *counter1) {
    if (length == 0) {
        return;
    } else if (length >= 3) {
        (*counter3)++;
        MaxCutLength(length - 3, counter3, counter2, counter1);
    } else if (length >= 2) {
        (*counter2)++;
        MaxCutLength(length - 2, counter3, counter2, counter1);
    } else if (length >= 1) {
        (*counter1)++;
        MaxCutLength(length - 1, counter3, counter2, counter1);
    }
}

int main() {
    int length, Sum;
    printf("Enter the length of the rope: ");
    scanf("%d", &length);
    int counter3 = 0, counter2 = 0, counter1 = 0;

    MaxCutLength(length, &counter3, &counter2, &counter1);
    Sum = counter1 + counter2 + counter3;
    printf("\nThe Max number of pieces that rope can be cut into is: %d\n", Sum);
    printf("Number of 3-length cuts: %d\n", counter3);
    printf("Number of 2-length cuts: %d\n", counter2);
    printf("Number of 1-length cuts: %d\n", counter1);
    return 0;
}
