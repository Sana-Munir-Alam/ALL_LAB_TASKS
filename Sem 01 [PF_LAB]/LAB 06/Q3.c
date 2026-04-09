#include<stdio.h>

int main(){
    int Num;

    do{
        printf("Enter Num: ");
        scanf("%d", &Num);
        if (Num > 0){
            printf("Hell yeah ~<_%d_>~", Num);
            break;
        }else{
            printf("No\n");
        }
    } while (Num < 0);
    return 0;
}
