#include<stdio.h>
int pattern(int N){
	for (int i = N+1; i >= 1; i--){
		for (int j = 0; j <= i; j++){
			if (j >= i && j <= N+1){
				for (int k = j; k <= N+1; k++){
					printf("O");
				}	
			}else{
				printf(". ");
				
			}
		}
		printf("\n");
	}
	for(int i = 2; i <= N +1; i++){
		for (int j = 0; j <= i; j ++){
			if ( j >= i && j <= N +1){
				for (int k = j; k <= N+1; k++){
					printf("O");
				}
			}else{
				printf(". ");
			}
		}
		printf("\n");
	}
	return 0;
} 

int main(){
	int N;
	printf("Enter the number of N: ");
	scanf("%d", &N);
	pattern(N);
	return 0;
}
