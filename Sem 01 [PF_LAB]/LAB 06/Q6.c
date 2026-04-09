#include <stdio.h>

int main(){
    int Num, Count;
    int IsPrime = 1;
    int a = 0, b=1;

    printf("Enter a Number: ");
    scanf("%d", &Num);
    if (Num <= 1){
        IsPrime = 0;
    }else{
        for(int i = 2; i * i <= Num; i++){
            if (Num % i == 0){
                IsPrime = 0;
                break;
            }
        } 
        if (IsPrime !=0){
            printf("Is prime!\n");
            printf("Fibonacci series upto %d: ", Num);
            if (Num >=0) {
                printf("%d ", a);
            }
            if (Num >=1) {
                printf("%d ", b);
            }
            Count = a + b;
            while (Count < Num){
                printf ("%d ", Count);
                a = b;
                b = Count;
                Count = a + b;
            }
            printf("\n");
        }else{
            printf("Not a prime!");
        }
    } 
    return 0;
}
