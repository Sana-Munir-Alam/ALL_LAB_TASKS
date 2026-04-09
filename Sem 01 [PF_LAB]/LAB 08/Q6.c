#include<stdio.h>

int main(){
    int Num;
    printf("Enter the Number of Rows you wish for the pattern: ");
    scanf("%d", &Num);

    for (int i = 0; i < Num; i++){
        for (int j = 0; j < Num; j++){
            if (i == 0 || i == Num - 1 || j == 0 || j == Num - 1 || i == j || j == Num - i - 1){
                printf("* ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
