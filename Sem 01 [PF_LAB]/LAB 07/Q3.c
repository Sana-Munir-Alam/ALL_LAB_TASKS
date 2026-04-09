#include<stdio.h>
int main(){
    int Array1[12];
    int Array2[6];
    int j = 0;
    for(int i=0; i < 12; i++){
        printf("Enter Array[%d] value: ", i);
        scanf("%d", &Array1[i]);
    }
    for(int i=0; i < 12; i = i+2){
        Array2[j] = Array1[i] + Array1[i+1];
        j++;
    }
    printf("Input Array \t:{");
    for(int i=0; i < 12; i++){
        printf("%d,", Array1[i]);
    }
    printf("}\n");
    printf("Pair Sum Array \t:{");
    for(int i=0; i < 6; i++){
        printf("%d,", Array2[i]);
    }
    printf("}");
    return 0;
}
