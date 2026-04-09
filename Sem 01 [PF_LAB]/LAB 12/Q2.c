#include <stdio.h>
#include <stdlib.h>

void modifyArray(int *Array, int Size) {
    for (int i = 0; i < Size; i++) {
        if (Array[i] % 2 != 0) {
            Array[i] -= 1;
        }
    }
}

int main() {
    int Size;

    printf("Enter the size of the Array: ");
    scanf("%d", &Size);

    int *Array = (int *)malloc(Size * sizeof(int));
    if (Array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("\nEnter %d elements: \n", Size);
    for (int i = 0; i < Size; i++) {
        printf("Enter Array[%d]: ", i+1);
        scanf("%d", &Array[i]);
    }

    modifyArray(Array, Size);

    printf("\nModified Array (Contains Even Numbers Only): {");
    for (int i = 0; i < Size; i++) {
        printf("%d ", Array[i]);
    }
    printf("}\n");
    free(Array);
    return 0;
}
