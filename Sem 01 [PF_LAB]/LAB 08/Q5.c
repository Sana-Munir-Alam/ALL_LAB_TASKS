#include<stdio.h>

int main(){
    int Array[4][4];
    int Temp = 0;
    printf("\n");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("For Team %d, Enter the Round Score[%d][%d]: ", i+1,i+1,j+1);
            scanf("%d", &Array[i][j]);
        }
        printf("\n");
    }
    // Sorting
    for (int k = 0; k < 4; k++){
        for (int i = 0; i < 3; i++){
            for (int j = (i+1); j < 4; j++){
                if (Array[i][k] > Array[j][k]){
                    Temp = Array[i][k];
                    Array[i][k] = Array[j][k];
                    Array[j][k] = Temp;
                }
            }
        }
    }
    // Printing
    printf("Sorted Matrice: \n");
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("Team %d Round[%d]: %d ",i+1, j+1,Array[i][j]);
        }
        printf("\n");
    }
    return 0;
}
