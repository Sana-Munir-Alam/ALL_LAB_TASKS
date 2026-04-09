#include<stdio.h>

int main(){
	int n;
	
	printf("Enter the Number you want to have displayed as words: ");
	scanf("%d", &n);
	
	switch(n){
		case 1:
			printf("The Number %d is: one",n);
			break;
		case 2:
			printf("The Number %d is: twp",n);
			break;
		case 3:
			printf("The Number %d is: three",n);
			break;
		case 4:
			printf("The Number %d is: four",n);
			break;
		case 5:
			printf("The Number %d is: five",n);
			break;
		case 6:
			printf("The Number %d is: six",n);
			break;
		case 7:
			printf("The Number %d is: seven",n);
			break;
		case 8:
			printf("The Number %d is: eight",n);
			break;
		case 9:
			printf("The Number %d is: nine",n);
			break;
		case 10:
			printf("The Number %d is: ten",n);
			break;
		case 11:
			printf("The Number %d is: eleven",n);
			break;
		case 12:
			printf("The Number %d is: twelve",n);
			break;
		case 13:
			printf("The Number %d is: thirteen",n);
			break;
		case 14:
			printf("The Number %d is: fourteen",n);
			break;
		case 15:
			printf("The Number %d is: fifteen",n);
			break;
		case 16:
			printf("The Number %d is: sixteen",n);
			break;
		case 17:
			printf("The Number %d is: seventeen",n);
			break;
		case 18:
			printf("The Number %d is: eighteen",n);
			break;
		case 19:
			printf("The Number %d is: nineteen",n);
			break;
		case 20:
			printf("The Number %d is: twenty",n);
			break;
		default:
			printf("Number is greater than 20");
	}
	return 0;
}
