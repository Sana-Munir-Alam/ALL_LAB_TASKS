#include<stdio.h>
int main(){
	int sum;
	int sizeArray;
	int Array[15];
	for (int i=0; i < 15; i++){
		printf("Enter Array[%d] value: ", i);
		scanf("%d", & Array[i]);
	}
	sizeArray = sizeof(Array)/sizeof(Array[0]);
	for (int i = 0; i< sizeArray; i++){
		sum = sum + Array[i];
	}
	printf("The sum of your given array is: %d", sum);
	return 0;
}
