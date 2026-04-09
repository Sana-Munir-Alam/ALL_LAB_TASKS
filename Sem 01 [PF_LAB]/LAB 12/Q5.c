#include <stdio.h>
#include <stdlib.h>

void insertElement(int **arr, int *n, int x, int pos) {
    *arr = realloc(*arr, (*n + 1) * sizeof(int));
    for (int i = *n - 1; i >= pos; i--) {
        (*arr)[i + 1] = (*arr)[i];
    }
    (*arr)[pos] = x;
    (*n)++;
}

void deleteElement(int **arr, int *n, int pos) {
    if (*n == 1) {
        free(*arr);
        *arr = NULL;
        (*n)--;
        return;
    }
    for (int i = pos; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = realloc(*arr, (*n - 1) * sizeof(int));
    (*n)--;
}

int main() {
    int n; // Number of elements in the array
    scanf("%d", &n); //Take the number of elements
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { //Input the value of the array
        scanf("%d", &arr[i]);
    }

    int t; // Number of Test Cases
    scanf("%d", &t);
    // Loop over test cases
    while (t--) { 
        // Handle operations (Insertion/Deletion)
        char opt;
        scanf(" %c", &opt);
        if (opt == 'I') {  // Insertion
            int pos, x;
            scanf("%d %d", &pos, &x);
            if (pos - 1 >= 0 && pos - 1 <= n) { // Adjust for 0-based index
                insertElement(&arr, &n, x, pos - 1);
                // After insertion
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            } else {
                printf("Invalid position for insertion!\n");
            }
        } else if (opt == 'D') {  // Deletion
            int pos;
            scanf("%d", &pos);
            if (pos - 1 >= 0 && pos - 1 < n) { // Adjust for 0-based index
                deleteElement(&arr, &n, pos - 1);
                // After deletion
                if (n > 0) {
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                } else {
                    printf("Array is empty.");
                }
                printf("\n");
            } else {
                printf("Invalid position for deletion!\n");
            }
        }
    }
    free(arr); // Free memory for the current test case
    return 0;
}
