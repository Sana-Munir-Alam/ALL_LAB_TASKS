#include <stdio.h>
#include <string.h>

void AccessCheck(char Username[20], char Password[20]){
    char CorrectUsername[20] = {"admin"};
    char CorrectPassword[20] = {"1234"};
    if ((strcmp(Username, CorrectUsername) == 0) && (strcmp(Password, CorrectPassword) == 0)){
        printf("Access Granted\n");
        return;
    } else{
        printf("Access Denied\n");
        return;
    }
}

int main(){
    char Username[20];
    char Password[20];
    printf("Enter Username: ");
    scanf("%s", Username);
    printf("Enter Password: ");
    scanf("%s", Password);
    AccessCheck(Username, Password);
    return 0;
}
