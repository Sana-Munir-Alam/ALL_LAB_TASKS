#include<stdio.h>

int main(){
	int n;
	printf("Enter the number of patter you want: ");
	scanf("%d", &n);
	for(int i = n; i>=1; i--){
		for(int space = 0; space<(n-i); space++){
			printf(" ");
		}
		for(int j = i; j>=1; j--){
			printf("%d ",j);
		}
		printf("\n");
	}
	for (int i = 2; i <= n; i++){
		for(int space = 0; space<(n-i); space++){
			printf(" ");
		}
		for(int j = i; j >=1; j--){
			printf("%d ", j);
		}
		printf("\n");
	}
	return 0;
}
