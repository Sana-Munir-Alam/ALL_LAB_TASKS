#include <stdio.h>

int main(){
    int Num;
    int Sum = 0;
    do{
        printf("Enter a Number: ");
        scanf("%d", &Num);
        Sum = Sum + Num;
        printf("Current Sum: %d \n", Sum);
    }while (Num!=0);
    printf("Final sum: %d", Sum);
    return 0;
}
