#include <stdio.h>

void PercentageCalculator(int Num){
    float Percent;
    for (int i = 1; i <= 100; i++){
        Percent = Num * (i/100.0);
        printf("%d Percent = %.2f\n", i,Percent);
    }
}
int main(){
    int Num;
    printf("Enter a Value to find it's percentage: ");
    scanf("%d", &Num);
    PercentageCalculator(Num);
    return 0;
}
