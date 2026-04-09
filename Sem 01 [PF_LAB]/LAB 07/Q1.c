#include<stdio.h>
int main(){
    int Num, sizeArray, Index;
    int found = 0;
    int Array[] = {1,1,1,1,1,1,5,1,1,1,1,1};
    sizeArray = sizeof(Array)/sizeof(Array[0]);
    printf("Enter the number you want to find in the array: ");
    scanf("%d", &Num);
    for (int i =0; i < sizeArray; i++){
        if (Num == Array[i]){
            found = 1;
            Index = i + 1;
            break;
        }else{
            found = 0;
        }
    }
    if (found == 1){
        printf("%d found at index %d", Num, Index);
    }else{
        printf("Number not found");
    }
    return 0;
}
