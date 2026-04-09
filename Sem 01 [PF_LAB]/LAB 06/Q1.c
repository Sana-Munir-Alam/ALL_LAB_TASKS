#include<stdio.h>
int main(){
	int Num;
	int Factorial = 1;
	printf("Enter the Number you want to find the factorial of: ");
	scanf("%d", &Num);
	if (Num >= 0){
		for(int i=Num; i>0; i--){
		Factorial = Factorial * i;
	}
	printf("The factorial of the number is: %d",Factorial);	
	}else{
		printf("Invalid Input! The number should be positive");
	}
	return 0;
}
