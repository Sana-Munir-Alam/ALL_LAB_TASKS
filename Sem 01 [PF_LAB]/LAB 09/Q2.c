#include <stdio.h>

int Calculations(int Bolts, int Nuts, int Washers){
    int Sum = 0;
    Sum = (Bolts * 5) + (Nuts * 3) + (1 * Washers);
    //Order Check
    if (Nuts >= Bolts && Washers == (2 * Bolts)){
        printf("Check the Order:\tOrder is OK\n");
    } else if (Nuts < Bolts){
        printf("Check the Order:\tToo few Nuts\n");
    } else if (Washers <= (2 * Bolts)){
        printf("Check thee Order:\tToo few Washers\n");
    }
    printf("Total Cost:\t\t%d\n", Sum);
    return 0;
}

int main(){
    int Bolts, Nuts, Washers;
    printf("Number of Bolts:\t");
    scanf("%d", &Bolts);
    printf("Number of Nuts:\t\t");
    scanf("%d", &Nuts);
    printf("Number of Washers:\t");
    scanf("%d", &Washers);
    printf("\n");
    Calculations(Bolts, Nuts, Washers);
    return 0;
}
