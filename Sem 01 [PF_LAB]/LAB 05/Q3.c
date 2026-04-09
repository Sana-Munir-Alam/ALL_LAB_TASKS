#include<stdio.h>

int main(){
	int Percentage;
	char grade;
	printf("Enter Your Percentage: ");
	scanf("%d", &Percentage);

	grade = (Percentage >= 90) ? grade='A' : 
	(Percentage>=80 && Percentage<90) ? grade='B': 
	(Percentage>=70 && Percentage<80) ? grade='C': 
	(Percentage>=60 && Percentage<70) ? grade='D': 
	(Percentage<60) ? grade='F' : grade='X';

	printf("Your Grade is %c", grade);
	return 0;
}
