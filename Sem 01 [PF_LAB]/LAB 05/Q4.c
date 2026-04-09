#include<stdio.h>
int main(){
    int Membership;
    int Purchase;
    char DiscountEligible;

    printf("Do you have a membership? Press 1 for \'yes\' or Press 2 for \'no\': ");
    scanf("%d", &Membership);
    printf("Enter the total cost of your purchase: ");
    scanf("%d", &Purchase);

    DiscountEligible = (Purchase > 100 && (Membership == 1) ? 'Y' : 'N');

    printf("Are you elgible for discount: %c", DiscountEligible);

    return 0;
}
