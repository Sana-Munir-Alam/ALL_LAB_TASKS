#include <stdio.h>
#include <string.h>

#define Max 50

struct TravelPackages{
    char Name[100];
    char Destination[100];
    int Duration;
    float Cost;
    int Seats;
};

void DisplayPackage(const struct TravelPackages Packages[], int Count){
    if(Count == 0){
        printf("\nNo Travel Package Available!");
        return;
    }
    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < Count; i++){
        printf("Package %d:\n", i+1);
        printf(" Package Name: %s\n", Packages[i].Name);
        printf(" Destination: %s\n", Packages[i].Destination);
        printf(" Duration: %d days\n", Packages[i].Duration);
        printf(" Cost: $%.2f per person\n", Packages[i].Cost);
        printf(" Seats Available: %d\n", Packages[i].Seats);
        printf("\n");
    }
}
void BookPackage(struct TravelPackages Packages[], int Count){
    int Index, SeatsBook;
    DisplayPackage(Packages, Count);
    printf("\nEnter the Package Number you want to book: ");
    scanf("%d", &Index);
    if (Index < 1 || Index > Count){
        printf("\nInvalid Package Number!!");
        return;
    }
    Index--;
    if (Packages[Index].Seats == 0){
        printf("\nSorry, No seats available for this package.");
    }
    printf("\nEnter the number of seats you want to book: ");
    scanf("%d", &SeatsBook);
    if(SeatsBook <=0){
        printf("\nInvalid Number of Seats.");
    }else if (SeatsBook > Packages[Index].Seats){
        printf("\nOnly %d seats are avilable, Kindly enter a Valid Number.", Packages[Index].Seats);
    }else{
        Packages[Index].Seats = Packages[Index].Seats - SeatsBook;
        printf("\nBooking Successful, %d seats have been booked.", SeatsBook);
    }

}
int main(){
    struct TravelPackages Packages[Max];
    int Choice;
    int Count = 0;
    
    // Sample Packages
    strcpy(Packages[0].Name, "Beach Paradise");
    strcpy(Packages[0].Destination, "Maldives");
    Packages[0].Duration = 7;
    Packages[0].Cost = 1500.0;
    Packages[0].Seats = 10;
    
    strcpy(Packages[1].Name, "Mountain Adventure");
    strcpy(Packages[1].Destination, "Swiss Alps");
    Packages[1].Duration = 10;
    Packages[1].Cost = 2000.0;
    Packages[1].Seats = 5;

    Count = 2;
    while (1){
        printf("\nTravel Management System\n");
        printf("1. Displlay Available Packages\n");
        printf("2. Book a Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &Choice);
        getchar();
        switch (Choice) {
            case 1:
                DisplayPackage(Packages, Count);
                break;
            case 2:
                BookPackage(Packages, Count);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
