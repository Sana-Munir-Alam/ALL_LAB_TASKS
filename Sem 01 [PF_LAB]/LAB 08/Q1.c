#include<stdio.h>

int main(){
	int SumRow[3]={0,0,0};
	int SumColumn[3]={0,0,0};
	int Array[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	for(int i= 0; i<3;i++){
		for (int j = 0; j<3; j++){
			printf("Enter value for Array[%d][%d]: ", i,j);
			scanf("%d", &Array[i][j]);
		}
	}
	//sum row
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			SumRow[i]= SumRow[i] + Array[i][j];
		}
	}
	//sum column
	for(int j = 0; j<3; j++){
		for(int i = 0; i<3; i++){
			SumColumn[i]= SumColumn[i] + Array[j][i];
		}
	}
	printf("The Sum of rows is:\n");
	for (int i = 0; i<3;i++){
		printf("Row[%d] is: %d\n",i, SumRow[i]);
	}
	printf("\nThe Sum of column is:\n");
	for (int i = 0; i<3;i++){
		printf("Column[%d] is: %d\n",i, SumColumn[i]);
	}
	return 0;
}
