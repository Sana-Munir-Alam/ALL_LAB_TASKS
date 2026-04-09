#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    

    int **arr = (int **)malloc(rows * sizeof(int *));
    if (arr == NULL) {
        printf("Memory allocation failed for rows.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        if (arr[i] == NULL) {
            printf("Memory allocation failed for columns at row %d.\n", i);
            return 1;
        }
    }

    printf("\nInitializing the 2D array Ourselves (by i * j)!!\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * j;
        }
    }

    int row_to_modify = 1;
    int col_to_modify = 2;
    printf("\nModifying value at arr[%d][%d] to 999 (Again Our Choice).\n", row_to_modify, col_to_modify);
    arr[row_to_modify][col_to_modify] = 999;

    printf("\nArray after modification:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(arr[i]); 
    }
    free(arr);
    return 0;
}
