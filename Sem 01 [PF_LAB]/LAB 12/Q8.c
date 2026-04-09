#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_points;
    float *fees;
    float total_profit = 0;

    // Step 1: Input the number of points
    printf("Enter the total number of pointsin the facility: ");
    scanf("%d", &num_points);
    // Error handling: Ensure num_points is valid
    if (num_points <= 0) {
        printf("Invalid input! The number of points must be greater than 0.\n");
        return 1;
    }
    // Step 2: Dynamically allocate memory for the array of fees
    fees = (float *)malloc(num_points * sizeof(float));
    if (fees == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    // Step 3: Input fees for each point
    for (int i = 0; i < num_points; i++) {
        printf("Enter the fee for point %d: $", i + 1);
        scanf("%f", &fees[i]);

        // Error handling: Reject negative fees
        if (fees[i] < 0) {
            printf("Invalid fee! Fee cannot be negative. Please re-enter the fee for point %d: $", i + 1);
            scanf("%f", &fees[i]);
        }
    }
    // Step 4: Calculate the total profit
    for (int i = 0; i < num_points; i++) {
        total_profit += fees[i];
    }
    // Step 5: Display the total profit
    printf("Total profit generated: $%.2f\n", total_profit);
    // Step 6: Free the dynamically allocated memory
    free(fees);
    return 0;
}
