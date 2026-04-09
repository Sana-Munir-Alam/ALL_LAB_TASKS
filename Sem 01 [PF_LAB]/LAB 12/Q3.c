#include <stdio.h>
#include <stdlib.h>

void AddNumber(float **Arr, int *Size, int *Capacity, float Number) {
    if (*Size >= *Capacity) {
        *Capacity *= 2;
        *Arr = (float *)realloc(*Arr, *Capacity * sizeof(float));
        if (*Arr == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
    (*Arr)[*Size] = Number;
    (*Size)++;
}

void RemoveLastNumber(float *Arr, int *Size) {
    if (*Size > 0) {
        (*Size)--;
    } else {
        printf("Array is Empty. Cannot remove elements!!\n");
    }
}

void ResizeArray(float **Arr, int *Size, int *Capacity) {
    if (*Size < *Capacity / 4) {
        *Capacity /= 2;
        *Arr = (float *)realloc(*Arr, *Capacity * sizeof(float));
        if (*Arr == NULL) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
    }
}

void DisplayArray(float *Arr, int Size) {
    if (Size == 0) {
        printf("The Array is empty.\n");
    } else {
        printf("Array contents: ");
        for (int i = 0; i < Size; i++) {
            printf("%.2f ", Arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int Size = 0;
    int Capacity = 4;
    float *Arr = (float *)malloc(Capacity * sizeof(float));

    if (Arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int choice;
    float Number;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add a new Number\n");
        printf("2. Display all Numbers\n");
        printf("3. Remove the last Number\n");
        printf("4. Resize the Array (Reduction)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter a floating-point Number: ");
                scanf("%f", &Number);
                AddNumber(&Arr, &Size, &Capacity, Number);
                break;
            case 2:
                DisplayArray(Arr, Size);
                break;
            case 3:
                RemoveLastNumber(Arr, &Size);
                break;
            case 4:
                ResizeArray(&Arr, &Size, &Capacity);
                break;
            case 5:
                free(Arr);
                printf("Memory freed, Exiting....\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
