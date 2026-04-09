#include <stdio.h>

void BubbleSort(int Array[], int N){
    if (N == 1){
        return;
    }
    for (int i = 0; i < N - 1; i++){
        if (Array[i] > Array[i+1]){
            int Temp = Array[i];
            Array[i] = Array[i+1];
            Array[i+1] = Temp;
        }
    }
    BubbleSort(Array, N-1);
}

int main(){
    int N;
    printf("Enter The Total Number of Elements In An Array: ");
    scanf("%d", &N);
    printf("\n");
    int Array[N];
    for (int i = 0; i < N; i++){
        printf("Enter Element[%d]: ", i+1);
        scanf("%d", &Array[i]);
    }
    printf("\nBefore Buble Sirt Array is: {");
    for (int i = 0; i < N; i++){
        printf("%d,", Array[i]);
    }
    printf("}");
    printf("\nAfter Bubble Sort Array is: {");
    BubbleSort(Array, N);
    for (int i = 0; i < N; i++){
        printf("%d,", Array[i]);
    }
    printf("}");
    return 0;
}
