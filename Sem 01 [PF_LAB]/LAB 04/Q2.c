#include <stdio.h>

int main(){
    int Units;
    float Amount, TotalAmount, SurCharge;
    
    printf("Enter The Total Units Consumed: ");
    scanf("%d", &Units);
    
    if (Units<=30){
        Amount = Units *0.60;
    }else if (Units <= 110){
        Amount =(30*0.6) + ((Units-30)*0.85);
    }else if (Units <= 210){
        Amount = (30*0.6) + (80*0.85) + ((Units - 110)*1.30);
    }else{
        Amount =(30*0.6) + (80*0.85) + (100*1.30) + ((Units- 210)*1.60);
    }
    SurCharge = Amount * (15.0/100.0);
    TotalAmount = Amount + SurCharge;
    
    printf("Your bill for the %d Unit consumed is %.2f", Units, TotalAmount);
    return 0;
}
