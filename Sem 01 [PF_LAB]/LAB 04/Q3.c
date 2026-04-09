#include <stdio.h>

int main(){
    float OriginalAmount,AmountSaved,FinalAmount;
    
    printf("Enter the Total Amount of your Shopping:");
    scanf("%f", &OriginalAmount);
    
    if (OriginalAmount < 1500){
        AmountSaved = OriginalAmount * (7.0/100.0);
        FinalAmount = OriginalAmount - AmountSaved;
    }else if (OriginalAmount >= 1500 && OriginalAmount < 3000){
        AmountSaved = OriginalAmount * (12.0/100.0);
        FinalAmount = OriginalAmount - AmountSaved;
    }else if (OriginalAmount >= 3000 && OriginalAmount < 5000){
        AmountSaved = OriginalAmount * (22.0/100.0);
        FinalAmount = OriginalAmount - AmountSaved;
    }else if (OriginalAmount >=5000){
        AmountSaved = OriginalAmount * (30.0/100.0);
        FinalAmount = OriginalAmount - AmountSaved;
    }else{
        printf("Invalid Input)");
    }
    printf("The Original Amount of your shopping is: %.2f \n",OriginalAmount);
    printf("The Amount Saved due to discount is: %.2f \n", AmountSaved);
    printf("The Amount after Discount is: %.2f \n", FinalAmount);
    return 0;
}
