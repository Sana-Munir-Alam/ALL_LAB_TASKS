#include <stdio.h>

int main() {
    int Number, Sum, Temp;

    printf("Enter a number: ");
    scanf("%d", &Number);
    while(Number >= 10){
        Sum = 0;
        Temp = Number;
        
        while (Temp != 0) {
            Sum = Sum + (Temp % 10);
            Temp = Temp / 10;
        }
        Number = Sum;
    }
    printf("The sum of digits of number is %d\n", Number);

    return 0;
}
