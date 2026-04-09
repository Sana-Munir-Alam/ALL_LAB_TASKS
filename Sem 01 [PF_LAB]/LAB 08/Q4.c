#include <stdio.h>

int main(){
    int m,n;
    printf("Enter the m value of matrix[m][n] limit: ");
    scanf("%d", &m);
    printf("Enter the n value of matrix[m][n] limit: ");
    scanf("%d", &n);
    int Array1[m][n];
    int Array2[m][n];
    int Sum[m][n];
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            Sum[i][j] = 0;
        }
    }
    printf("\n");
    for (int i = 0; i < m ; i++){
        for (int j = 0; j < n; j++){
            printf("Enter Value of Matrice1 [%d][%d]: ",i,j);
            scanf("%d", &Array1[i][j]);
        }
    }
    printf("\n");
    for (int i = 0; i < m ; i++){
        for (int j = 0; j < n; j++){
            printf("Enter Value of Matrice2 [%d][%d]: ",i,j);
            scanf("%d", &Array2[i][j]);
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            Sum[i][j] = Array1[i][j] + Array2[i][j];
        }
    }
    printf("\nOUTPUT\n");
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Sum[%d][%d]: %d\n", i, j, Sum[i][j]);
        }
    }
    return 0;
}
