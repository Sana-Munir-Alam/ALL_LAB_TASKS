#include <stdio.h>

struct Phone {
    int AreaCode;
    int Exchange;
    int Number;
};

int main(){
    struct Phone MyNumber = {212, 767, 8900};
    struct Phone YourNumber;
    printf("Enter area code: ");
    scanf("%d", &YourNumber.AreaCode);
    printf("Enter exchange: ");
    scanf("%d", &YourNumber.Exchange);
    printf("Enter number: ");
    scanf("%d", &YourNumber.Number);

    printf("\nMy number is (%d) %d-%d\n", MyNumber.AreaCode, MyNumber.Exchange, MyNumber.Number);
    printf("Your number is (%d) %d-%d\n", YourNumber.AreaCode, YourNumber.Exchange, YourNumber.Number);

    return 0;
}
