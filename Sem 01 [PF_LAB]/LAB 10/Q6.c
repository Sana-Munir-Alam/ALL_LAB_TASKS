#include <stdio.h>
#include <string.h>

void Reversing(char *UserWord){
    if (*UserWord == '\0'){
        return;
    }
    while (*UserWord == ' '){
        UserWord++;
    }
    // Mark the start of the word
    char *Word = UserWord;
    // Move the pointer to the end of the word
    while (*Word != '\0' && *Word != ' '){
        Word++;
    }
    
    Reversing(Word);
    // Print the current word
    while (UserWord != Word){
        putchar(*UserWord);
        UserWord++;
    }
    if (*Word != '\0' || *Word <= '\0'){
        putchar(' ');
    }
}

int main(){
    char UserWord[100];

    printf("Enter Text: ");
    fgets(UserWord, 100, stdin);
    UserWord[strcspn(UserWord, "\n")] = '\0';

    printf("\nReversed Text is: ");
    Reversing(UserWord);
    printf("\n");

    return 0;
}
