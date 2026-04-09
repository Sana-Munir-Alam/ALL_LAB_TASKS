#include<stdio.h>
int main() {
    int Temp;
    int Array[10];
    for (int i = 0; i < 10; i++) {
        printf("Enter Array[%d] value:", i);
        scanf("%d", &Array[i]);
    }
    Temp = Array[0];
    for (int i = 0; i < 9; i++) {
        Array[i] = Array[i + 1];
    }
    Array[9] = Temp;
    printf("Array after shifting left by one position:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d, ", Array[i]);
    }
    return 0;
}
