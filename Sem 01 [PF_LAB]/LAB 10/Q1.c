#include <stdio.h>
#include <string.h>

void Reverse(char *Password){
	if(*Password){
		Reverse(Password + 1);
		printf("%c", *Password);
	}
}

int main(){
	char Password[100];
	printf("Enter a Sentence: ");
	fgets(Password, 100, stdin);
	Password[strcspn(Password, "\n")] = '\0';
	Reverse(Password);
	return 0;
}
