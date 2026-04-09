#include <stdio.h>

int main() {
    int Number;
    printf("Enter a Number: ");
    scanf("%d", &Number);

    if (Number & 1) {
        printf("%d is Odd.\n", Number);
    } else {
        printf("%d is Even.\n", Number);
    }

    return 0;
}
