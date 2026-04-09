#include<stdio.h>
int main(){
	int sizeArray;
	int Array[20];
	for (int i=0; i < 20; i++){
		printf("Enter Array[%d] value: ", i);
		scanf("%d", & Array[i]);
	}
	sizeArray = sizeof(Array)/sizeof(Array[0]);
	printf("The Reverse Order of your Array is: ");
	for (int i = 19; i>=0; i--){
		printf("%d, ",Array[i]);
	}
	return 0;
}
