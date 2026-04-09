#include<stdio.h>

int main(){
	int Angle1;
	int Angle2;
	int Angle3;
	int Sum;
	printf("Enter Angle 1, ANgle 2 and Angle 3 of the triangle: ");
	scanf("%d, %d, %d", &Angle1, &Angle2, &Angle3);
	Sum = Angle1 + Angle2 + Angle3;
	if (Sum == 180 && Angle1>0 && Angle2>0 && Angle3>0){
		printf("This is a triangle.");
	}else{
		printf("This is not a triangle");
	}
	return 0;
}
