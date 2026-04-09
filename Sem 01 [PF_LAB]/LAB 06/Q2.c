#include<stdio.h>
int main(){
	int Num;
	int Even;
	printf("Enter Number PLease: ");
	scanf("%d", &Num);
	if (Num >= 1){
		while (Num != 0){
			if (Num % 2 == 0){
				Even = Num;
				printf("The Number (%d) is Even \n", Even);
				Num = Num - 1;
			}else{
				Num = Num -1;
			}
		}
	}else{
		printf("The number has to be greater than or equal to 1");
	}
	return 0;
}
