#include<stdio.h>

int main(){
	int Score;
	printf("Enter your score: ");
	scanf("%d",&Score);
	
	if (Score <=100 && Score >= 90){
		printf("A Grade");
	}else if (Score <=89 && Score >= 80){
		printf("B Grade");
	}else if (Score <=79 && Score >= 70){
		printf("C Grade");
	}else if (Score <=69 && Score >= 60){
		printf("D Grade");
	}else if (Score <60){
		printf("F Grade");
	}else{
		printf("Invalid Input");
	}
	return 0;
}
