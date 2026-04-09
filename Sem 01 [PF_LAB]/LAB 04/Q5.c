#include <stdio.h>

int main(){
    int Time;
    
    printf("Enter the time in a 24hr format: ");
    scanf("%d", &Time);
    
    if (Time >=6 && Time < 12){
        printf("Good Morning");
    }else if (Time >=12 && Time < 18){
        printf("Good Afternoon");
    }else if (Time >=18 && Time < 24){
        printf("Good Evening");
    }else if (Time >=0 && Time <= 5){
        printf("Good Night");
    }else{
        printf("Invalid Input");
    }
    return 0;
}
