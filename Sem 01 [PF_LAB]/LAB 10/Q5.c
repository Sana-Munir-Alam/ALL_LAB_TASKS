#include <stdio.h>

int DigitsSum(int Num){
    if (Num == 0){
        return 0;
    }
    return (Num%10) + DigitsSum(Num/10);

}
int main(){
    int Num, Result;
    printf("Enter the Number you want to find the sum of: ");
    scanf("%d", &Num);
    Result = DigitsSum(Num);
    printf("Sum of Digits: %d\n", Result);
    return 0;
}
