#include <stdio.h>
#include <string.h>

void NameSearching(char Name[15]){
    char StudentName[6][15] = {"Thorin", "Edward", "Severus", "Brandon", "Adam", "Toji"};
    int Length = sizeof(StudentName)/sizeof(StudentName[0]);
    int Found = 0;
    for (int i = 0; i < Length; i++){
        if (strcmp(Name, StudentName[i]) == 0){
            Found = 1;
            break;
        }
    }
    if (Found == 1){
        printf(" Name Found");
        return;
    }else{
        printf("Name Not Found.");
        return;
    }
}

int main(){
    char Name[15];
    printf("Enter Name: ");
    scanf("%s", Name);
    NameSearching(Name);
    return 0;
}
