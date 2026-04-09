#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define FILENAME "books.txt"

struct Book {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int quantity;
    float price;
};

int loadBooks(struct Book books[]) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        return 0;
    }
    
    int count = 0;
    while (fscanf(file, "%d\n", &books[count].id) != EOF) {
        fgets(books[count].title, MAX_TITLE, file);
        books[count].title[strcspn(books[count].title, "\n")] = '\0';
        fgets(books[count].author, MAX_AUTHOR, file);
        books[count].author[strcspn(books[count].author, "\n")] = '\0';
        fscanf(file, "%d %f\n", &books[count].quantity, &books[count].price);
        count++;
    }

    fclose(file);
    return count;
}
void saveBooks(struct Book books[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d\n", books[i].id);
        fprintf(file, "%s\n", books[i].title);
        fprintf(file, "%s\n", books[i].author);
        fprintf(file, "%d %.2f\n", books[i].quantity, books[i].price);
    }

    fclose(file);
}

void addBook(struct Book books[], int *count) {
    struct Book newBook;

    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    getchar(); 
    for (int i = 0; i < *count; i++) {
        if (books[i].id == newBook.id) {
            printf("Error: Duplicate Book ID!\n");
            return;
        }
    }
    printf("Enter Book Title: ");
    fgets(newBook.title, MAX_TITLE, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(newBook.author, MAX_AUTHOR, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &newBook.quantity);

    printf("Enter Price: ");
    scanf("%f", &newBook.price);

    books[*count] = newBook;
    (*count)++;

    saveBooks(books, *count);
    printf("Book added successfully!\n");
}

void viewBooks(struct Book books[], int count) {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\nID\tTitle\t\tAuthor\t\tQuantity\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%s\t%d\t\t%.2f\n", books[i].id, books[i].title, books[i].author, books[i].quantity, books[i].price);
    }
}

void searchByID(struct Book books[], int count) {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\nPrice: %.2f\n", books[i].id, books[i].title, books[i].author, books[i].quantity, books[i].price);
            return;
        }
    }

    printf("Book with ID %d not found.\n", id);
}

void searchByTitle(struct Book books[], int count) {
    char title[MAX_TITLE];
    printf("Enter Book Title to search: ");
    getchar();
    fgets(title, MAX_TITLE, stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strstr(books[i].title, title) != NULL) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\nQuantity: %d\nPrice: %.2f\n", books[i].id, books[i].title, books[i].author, books[i].quantity, books[i].price);
            return;
        }
    }

    printf("Book with title '%s' not found.\n", title);
}

void updateBook(struct Book books[], int count) {
    int id;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Enter new Quantity: ");
            scanf("%d", &books[i].quantity);

            printf("Enter new Price: ");
            scanf("%f", &books[i].price);

            saveBooks(books, count);
            printf("Book updated successfully!\n");
            return;
        }
    }

    printf("Book with ID %d not found.\n", id);
}

void deleteBook(struct Book books[], int *count) {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (books[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--;
            saveBooks(books, *count);
            printf("Book deleted successfully!\n");
            return;
        }
    }

    printf("Book with ID %d not found.\n", id);
}

void calculateInventoryValue(struct Book books[], int count) {
    float totalValue = 0.0;
    for (int i = 0; i < count; i++) {
        totalValue += books[i].quantity * books[i].price;
    }

    printf("Total Inventory Value: %.2f\n", totalValue);
}

int main() {
    struct Book books[MAX_BOOKS];
    int count = loadBooks(books);

    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. View All Books\n");
        printf("3. Search Book by ID\n");
        printf("4. Search Book by Title\n");
        printf("5. Update Book\n");
        printf("6. Delete Book\n");
        printf("7. Calculate Total Inventory Value\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(books, &count);
                break;
            case 2:
                viewBooks(books, count);
                break;
            case 3:
                searchByID(books, count);
                break;
            case 4:
                searchByTitle(books, count);
                break;
            case 5:
                updateBook(books, count);
                break;
            case 6:
                deleteBook(books, &count);
                break;
            case 7:
                calculateInventoryValue(books, count);
                break;
            case 8:
                printf("Exiting system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);

    return 0;
}
