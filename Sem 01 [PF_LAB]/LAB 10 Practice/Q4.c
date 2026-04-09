#include <stdio.h>
#include <string.h>

#define MaxFlights 100

struct Flight {
    char flightNumber[10];
    char departureCity[50];
    char arrivalCity[50];
    char departureTime[10];
    char arrivalTime[10];
    int availableSeats;
};

void BookSeat(struct Flight flights[], int flightCount) {
    char flightNum[10];
    printf("\nEnter the Flight Number to book a seat: ");
    fgets(flightNum, 10, stdin);
    flightNum[strcspn(flightNum, "\n")] = '\0';

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNum) == 0) {
            if (flights[i].availableSeats > 0) {
                flights[i].availableSeats--;
                printf("Seat booked successfully on flight %s. Remaining seats: %d\n",
                       flights[i].flightNumber, flights[i].availableSeats);
            } else {
                printf("No seats available on flight %s.\n", flights[i].flightNumber);
            }
            return;
        }
    }
    printf("Flight number %s not found.\n", flightNum);
}

void DisplayAvailableFlights(struct Flight flights[], int flightCount) {
    char fromCity[50], toCity[50];
    printf("\nEnter Departure City: ");
    fgets(fromCity, 50, stdin);
    fromCity[strcspn(fromCity, "\n")] = '\0';

    printf("Enter Arrival City: ");
    fgets(toCity, 50, stdin);
    toCity[strcspn(toCity, "\n")] = '\0';

    printf("\nAvailable Flights from %s to %s:\n", fromCity, toCity);
    int found = 0;
    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].departureCity, fromCity) == 0 &&
            strcmp(flights[i].arrivalCity, toCity) == 0) {
            printf("Flight Number: %s\n", flights[i].flightNumber);
            printf("Departure Time: %s\n", flights[i].departureTime);
            printf("Arrival Time: %s\n", flights[i].arrivalTime);
            printf("Available Seats: %d\n\n", flights[i].availableSeats);
            found = 1;
        }
    }
    if (!found) {
        printf("No flights available from %s to %s.\n", fromCity, toCity);
    }
}

void UpdateFlightDetails(struct Flight flights[], int flightCount) {
    char flightNum[10];
    printf("\nEnter the Flight Number to update: ");
    fgets(flightNum, 10, stdin);
    flightNum[strcspn(flightNum, "\n")] = '\0';

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i].flightNumber, flightNum) == 0) {
            printf("Enter new Departure City: ");
            fgets(flights[i].departureCity, 50, stdin);
            flights[i].departureCity[strcspn(flights[i].departureCity, "\n")] = '\0';

            printf("Enter new Arrival City: ");
            fgets(flights[i].arrivalCity, 50, stdin);
            flights[i].arrivalCity[strcspn(flights[i].arrivalCity, "\n")] = '\0';

            printf("Enter new Departure Time: ");
            fgets(flights[i].departureTime, 10, stdin);
            flights[i].departureTime[strcspn(flights[i].departureTime, "\n")] = '\0';

            printf("Enter new Arrival Time: ");
            fgets(flights[i].arrivalTime, 10, stdin);
            flights[i].arrivalTime[strcspn(flights[i].arrivalTime, "\n")] = '\0';

            printf("Enter new number of Available Seats: ");
            scanf("%d", &flights[i].availableSeats);
            getchar();

            printf("Flight details updated successfully.\n");
            return;
        }
    }
    printf("Flight number %s not found.\n", flightNum);
}

int main() {
    struct Flight flights[MaxFlights] = {
        {"AI123", "New York", "Los Angeles", "10:00", "13:00", 150},
        {"BA456", "London", "Paris", "08:00", "09:30", 50}
    };
    int flightCount = 2;
    int choice;
    while (1) {
        printf("\nFlight Booking System\n");
        printf("1. Add Flight\n");
        printf("2. Book a Seat\n");
        printf("3. Display Available Flights\n");
        printf("4. Update Flight Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                if (flightCount < MaxFlights) {
                    printf("\nEnter Flight Number: ");
                    fgets(flights[flightCount].flightNumber, 10, stdin);
                    flights[flightCount].flightNumber[strcspn(flights[flightCount].flightNumber, "\n")] = '\0';

                    printf("Enter Departure City: ");
                    fgets(flights[flightCount].departureCity, 50, stdin);
                    flights[flightCount].departureCity[strcspn(flights[flightCount].departureCity, "\n")] = '\0';

                    printf("Enter Arrival City: ");
                    fgets(flights[flightCount].arrivalCity, 50, stdin);
                    flights[flightCount].arrivalCity[strcspn(flights[flightCount].arrivalCity, "\n")] = '\0';

                    printf("Enter Departure Time: ");
                    fgets(flights[flightCount].departureTime, 10, stdin);
                    flights[flightCount].departureTime[strcspn(flights[flightCount].departureTime, "\n")] = '\0';

                    printf("Enter Arrival Time: ");
                    fgets(flights[flightCount].arrivalTime, 10, stdin);
                    flights[flightCount].arrivalTime[strcspn(flights[flightCount].arrivalTime, "\n")] = '\0';

                    printf("Enter number of Available Seats: ");
                    scanf("%d", &flights[flightCount].availableSeats);
                    getchar();
                    flightCount++;
                    printf("Flight added successfully.\n");
                } else {
                    printf("Maximum flight limit reached.\n");
                }
                break;
            case 2:
                BookSeat(flights, flightCount);
                break;
            case 3:
                DisplayAvailableFlights(flights, flightCount);
                break;
            case 4:
                UpdateFlightDetails(flights, flightCount);
                break;
            case 5:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
