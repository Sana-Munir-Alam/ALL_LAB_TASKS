#include <stdio.h>

struct Rectangle{
	float Length;
	float Width;	
};

int check(struct Rectangle Info){
	if ((Info.Length >= 0.0 && Info.Width <= 20.0) && (Info.Width >=0.0 && Info.Width <= 20.0)){
		return 1;
	}else{
		return 0;
	}
}

void CalculateParameter(struct Rectangle Info){
	float Parameter;
	Parameter = (2*(Info.Length) + 2*(Info.Width));
	printf("\nParameter of Rectangle: %.1f", Parameter);
	return;
}
void CalculateArea(struct Rectangle Info){
	float Area;
	Area = Info.Length * Info.Width;
	printf("\nArea of Rectangle: %.1f", Area);
	return;
}
int main(){
	struct Rectangle Info;
	printf("Enter the Length of Rectangle: ");
	scanf("%f", &Info.Length);
	printf("Enter the Width of Rectangle: ");
	scanf("%f", &Info.Width);
	
	if(check(Info)){
		CalculateArea(Info);
		CalculateParameter(Info);
	}else{
		printf("Invalid Input!");
	}
	return 0;
}
