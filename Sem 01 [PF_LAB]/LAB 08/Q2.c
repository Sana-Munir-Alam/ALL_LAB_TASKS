#include<stdio.h>

int main(){
	int InputArray[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	for (int i = 0; i<4; i++){
		for (int j = 0; j<4; j++){
			printf("Enter Marks[%d][%d]: ", i,j);
			scanf("%d", &InputArray[i][j]);
		}
	}
	for (int i = 0; i<4; i++){
		for (int j = 0; j<4; j++){
			if(InputArray[i][j] < 0){
				InputArray[i][j] = 0;
			}else{
				continue;
			}
		}
	}
	printf("Correct Array is: {");
	for (int i = 0; i<4; i++){
		for (int j = 0; j<4; j++){
			printf("%d, ", InputArray[i][j]);
		}
	}printf("}");
	return 0;
}
