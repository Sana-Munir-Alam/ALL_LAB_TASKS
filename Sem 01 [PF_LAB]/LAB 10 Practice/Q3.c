#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define Max 100

struct Book{
    char Title[50];
    char Author[50];
    int ISBN;
    int PublicationYear; 
    bool IsAvailable;
};

void AddBook(struct Book Info[], int *Count){
    int Status = 0;
    printf("\nEnter Book Title: ");
    fgets(Info[*Count].Title, 50, stdin);
    Info[*Count].Title[strcspn(Info[*Count].Title, "\n")] = '\0';
    printf("Enter Book Author: ");
    fgets(Info[*Count].Author, 50, stdin);
    Info[*Count].Author[strcspn(Info[*Count].Author, "\n")] = '\0';
    printf("Enter Book ISBN: ");
    scanf("%d", &Info[*Count].ISBN);
    printf("Enter Book Publication Year: ");
    scanf("%d", &Info[*Count].PublicationYear);
    printf("Enter Book Status (1 if RETURNED, 2 if CHECKED OUT): ");
    scanf("%d", &Status);
    if (Status == 1){
        Info[*Count].IsAvailable = true;
    } else {
        Info[*Count].IsAvailable = false;
    }
    getchar();

    (*Count)++;
    printf("Book has been added!\n");
}

void SearchBook(const struct Book Info[], int Count) {
    char Search[50];
    int Found = 0;
    if (Count == 0) {
        printf("No Books Available.\n");
        return;
    }
    printf("\nEnter either Book Title or Author to search: ");
    fgets(Search, 50, stdin);
    Search[strcspn(Search, "\n")] = '\0';
    printf("\n");
    for (int i = 0; i < Count; i++) {
        if (strcmp(Info[i].Title, Search) == 0 || strcmp(Info[i].Author, Search) == 0) {
            printf("Book %d:\n", i + 1);
            printf("Title: %s\n", Info[i].Title);
            printf("Author: %s\n", Info[i].Author);
            printf("ISBN: %d\n", Info[i].ISBN);
            printf("Publication Year: %d\n", Info[i].PublicationYear);
            printf("Book Status: %s\n", Info[i].IsAvailable ? "Available" : "Checked Out");
            Found = 1;
        }
    }
    if (!Found) {
        printf("No Books found with the specified Title or Author.\n");
    }
}

void ReturnBook(struct Book Info[], int Count){
    char Search[50];
    printf("\nEnter Book Title you are returning: ");
    fgets(Search, 50, stdin);
    Search[strcspn(Search,"\n")] = '\0';
    printf("\n");
    for(int i = 0; i < Count; i++){
        if (strcmp(Info[i].Title, Search) == 0){
            Info[i].IsAvailable = true;
            printf("Book '%s' has been returned.\n", Info[i].Title);
            return;
        }
    }
}

void CheckOutBook(struct Book Info[], int Count) {
    char Search[50];
    printf("\nEnter Book Title to check out: ");
    fgets(Search, 50, stdin);
    Search[strcspn(Search, "\n")] = '\0';
    for (int i = 0; i < Count; i++) {
        if (strcmp(Info[i].Title, Search) == 0) {
            if (Info[i].IsAvailable) {
                Info[i].IsAvailable = false;
                printf("Book '%s' has been checked out.\n", Info[i].Title);
            } else {
                printf("Book '%s' is already checked out.\n", Info[i].Title);
            }
            return;
        }
    }
    printf("Book with the title '%s' was not found.\n", Search);
}

int main() {
    struct Book Info[Max];
    int Count = 0;
    int Choice = 0;
    while (1) {
        printf("\nLibrary Book Handling\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Return a Book\n");
        printf("4. Check Out a Book\n");
        printf("5. Exit Program\n");
        printf("Enter Choice: ");
        scanf("%d", &Choice);
        getchar();
        switch (Choice) {
            case 1:
                AddBook(Info, &Count);
                break;
            case 2:
                SearchBook(Info, Count);
                break;
            case 3:
                ReturnBook(Info, Count);
                break;
            case 4:
                CheckOutBook(Info, Count);
                break;
            case 5:
                printf("Exiting the Program...\n");
                return 0;
            default:
                printf("Invalid Choice. Please Try Again.\n");
        }
    }
    return 0;
}