#include <stdio.h>
#include <string.h>

#define MAX 100
struct Cars {
    char Make[30];
    char Model[30];
    int Year;
    float Price, Mileage;
};

void AddCars(struct Cars Info[], int *Count) {
    printf("\n");
    printf("Enter Car Make: ");
    fgets(Info[*Count].Make, 30, stdin);
    Info[*Count].Make[strcspn(Info[*Count].Make, "\n")] = '\0';
    printf("Enter Car Model: ");
    fgets(Info[*Count].Model, 30, stdin);
    Info[*Count].Model[strcspn(Info[*Count].Model, "\n")] = '\0';
    printf("Enter Car Year: ");
    scanf("%d", &Info[*Count].Year);
    printf("Enter Car Price: ");
    scanf("%f", &Info[*Count].Price);
    printf("Enter Car Mileage: ");
    scanf("%f", &Info[*Count].Mileage);
    getchar();

    (*Count)++;
    printf("Car has been added!\n");
}

void DisplayCars(const struct Cars Info[], int Count) {
    if (Count == 0) {
        printf("No cars available.\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < Count; i++) {
        printf("Car %d:\n", i + 1);
        printf(" Make: %s\n", Info[i].Make);
        printf(" Model: %s\n", Info[i].Model);
        printf(" Year: %d\n", Info[i].Year);
        printf(" Price: $%.2f\n", Info[i].Price);
        printf(" Mileage: %.2f miles\n", Info[i].Mileage);
        printf("\n");
    }
}

void SearchCars(const struct Cars Info[], int Count) {
    char Search[50];
    int Found = 0;
    if (Count == 0) {
        printf("No cars available.\n");
        return;
    }
    printf("\nEnter either Car Make or Model to search: ");
    scanf("%s", Search);
     printf("\n");
    for (int i = 0; i < Count; i++) {
        if (strcmp(Info[i].Make, Search) == 0 || strcmp(Info[i].Model, Search) == 0) {
            printf("Car %d:\n", i + 1);
            printf(" Make: %s\n", Info[i].Make);
            printf(" Model: %s\n", Info[i].Model);
            printf(" Year: %d\n", Info[i].Year);
            printf(" Price: $%.2f\n", Info[i].Price);
            printf(" Mileage: %.2f miles\n", Info[i].Mileage);
            printf("\n");
            Found = 1;
        }
    }
    if (!Found) {
        printf("No cars found with the specified make or model.\n");
    }
}

int main() {
    int N;
    int Choice = 0;
    printf("Enter how many cars you want to add: ");
    scanf("%d", &N);
    getchar();
    struct Cars Info[MAX];
    int Count = 0;
    while (1) {
        printf("\nCar Dealership Management System\n");
        printf("1. Add New Car\n");
        printf("2. Display Available Cars\n");
        printf("3. Search Cars by Make or Model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &Choice);
        getchar();
        switch (Choice) {
            case 1:
                AddCars(Info, &Count);
                break;
            case 2:
                DisplayCars(Info, Count);
                break;
            case 3:
                SearchCars(Info, Count);
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
