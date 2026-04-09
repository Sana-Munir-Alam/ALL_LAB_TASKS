#include<stdio.h>

int main(){
	int Num1;
	int Num2;
	
	printf("Enter Number 1:");
	scanf("%d", &Num1);
	printf("Enter Number 2:");
	scanf("%d", &Num2);
	
	if (Num1 > Num2) {
		if (Num1 > 100){
			printf("First Number is significantly larger");
		}else{
			printf("First Number is Larger");
		}
	}else if (Num1<Num2){
		if (Num1 < 0){
			printf("First Number is negative and smaller.");
		}else{
			printf("First Number is smaller");
		}
	}else{
		printf("Invalid Input");
	}
	return 0;
}
