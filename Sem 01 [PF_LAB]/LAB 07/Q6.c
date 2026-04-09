#include<stdio.h>
int main(){
	int Max, Min;
	int sizeArray;
	int Array[30];
	for (int i=0; i < 30; i++){
		printf("Enter Array[%d] value: ", i);
		scanf("%d", & Array[i]);
	}
	Min = Array[0];
	Max = Array[0];
	sizeArray = sizeof(Array)/sizeof(Array[0]);
	for (int i = 0; i < sizeArray; i++){
		if (Array[i] > Max){
			Max = Array[i];
		}
		if (Array[i] < Min){
			Min = Array[i];
		}
	}
	printf("The Max value is: %d\n", Max);
	printf("the Min value is: %d", Min);
	return 0;
}
