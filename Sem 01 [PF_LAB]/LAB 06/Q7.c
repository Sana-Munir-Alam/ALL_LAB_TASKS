#include<stdio.h>

int main(){
    int Num;
    int Sum = 0;
    int Temp, a;
    printf("\n Enter a three-digit number: ");
    scanf("%d", &Num);
    Temp = Num;
    while (Temp!=0){
        a = Temp % 10;
        Sum = Sum + (a * a * a);
        Temp = Temp / 10;
    }
    if (Sum == Num){
        printf("It is an Armstrong Number");
    }else{
        printf("It is not an Armstrong Number");
    }
    return 0;
}
