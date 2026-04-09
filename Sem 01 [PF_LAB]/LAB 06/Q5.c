#include <stdio.h>
int main(){
    int Num;
    int IsPrime =1;
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
            printf("Is prime!");
        }else{
            printf("Not a prime!");
        }
    } 
    return 0;
}
