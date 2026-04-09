#include <stdio.h>
#include <string.h>

void Cyphering(char UserWord[100], char Key[100], char CypherText[100]){
    int LengthWord = strlen(UserWord);
    int LengthKey = strlen(Key);
    int j = 0;
    for (int i = 0; i <= LengthWord; i++){
        char Word = UserWord[i];
        char KeyChar = Key[j];
        // Space working
        if (Word == ' '){
            CypherText[i] = (((20 + (Key[j] - 'A' + 1)) % 26) +'A' -1);
            j++;
            continue;
        }

        int UserValue = Word - 'A' + 1;
        int KeyValue = KeyChar - 'A' + 1;
        int CypherValue = (UserValue + KeyValue) % 26;

        if (CypherValue == 0){
            CypherValue = 26;
        }
        CypherValue += 'A' - 1;
        CypherText[i] = CypherValue;

        j++;
        if (j >= LengthKey){
            j = 0;
        }
    }
    CypherText[LengthWord] = '\0';
}

int main(){
    char UserWord[100];
    char Key[100];
    char CypherText[100];

    printf("Enter Plain Text (CAPITAL-LETTER): ");
    fgets(UserWord, 100, stdin);
    UserWord[strcspn(UserWord, "\n")] = '\0';

    printf("Enter Key (CAPITAL-LETTER): ");
    fgets(Key, 100, stdin);
    Key[strcspn(Key, "\n")] = '\0';

    Cyphering(UserWord, Key, CypherText);

    printf("\nCypherText is: %s\n", CypherText);
    return 0;
}
