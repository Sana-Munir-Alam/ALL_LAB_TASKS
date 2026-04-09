#include<stdio.h>

int main(){
	int Age;
	int CitizenshipStatus;
	
	printf("Enter your Citizenship Status (1 for Pakistani and 0 for Not-Pakistani): ");
	scanf("%d", &CitizenshipStatus);
	printf("Enter your age: ");
	scanf("%d", &Age);
	
	if (CitizenshipStatus == 1){
		if (Age >=18){
			printf("You are eligible to vote.");
		}
		else{
			printf("Sorry, you are underage and can not vote.");
		}
	}else{
		printf("Sorry you have to be a Pakistani citizen to vote.");
	}
	return 0;
}
