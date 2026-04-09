#include <stdio.h>
#include <string.h>
struct Invoice {
    char PartNumber[50];
    char PartDescription[100];
    int Quantity;
    float PricePerItem;
};

float calculateInvoiceAmount(struct Invoice invoice) {
    if (invoice.Quantity < 0) {
        invoice.Quantity = 0;
    }
    if (invoice.PricePerItem < 0) {
        invoice.PricePerItem = 0.0;
    }
    return invoice.Quantity * invoice.PricePerItem;
}

int main() {
    struct Invoice Item1 = {"PN12345", "Hammer", 5, 25.50};
    struct Invoice Item2;

    printf("Enter Part Number: ");
    fgets(Item2.PartNumber, sizeof(Item2.PartNumber), stdin);
    Item2.PartNumber[strcspn(Item2.PartNumber, "\n")] = '\0';

    printf("Enter part description: ");
    fgets(Item2.PartDescription, sizeof(Item2.PartDescription), stdin);
    Item2.PartDescription[strcspn(Item2.PartDescription, "\n")] = '\0';

    printf("Enter Quantity: ");
    scanf("%d", &Item2.Quantity);
    getchar();

    printf("Enter price per item: ");
    scanf("%f", &Item2.PricePerItem);
    getchar();

    printf("\nInvoice Details:\n");

    printf("Item 1\n");
    printf("Part Number: %s\n", Item1.PartNumber);
    printf("Part Description: %s\n", Item1.PartDescription);
    printf("Quantity: %d\n", Item1.Quantity);
    printf("Price per Item: $%.2f\n", Item1.PricePerItem);
    printf("Invoice Amount: $%.2f\n\n", calculateInvoiceAmount(Item1));

    printf("Item 2\n");
    printf("Part Number: %s\n", Item2.PartNumber);
    printf("Part Description: %s\n", Item2.PartDescription);
    printf("Quantity: %d\n", Item2.Quantity);
    printf("Price per Item: $%.2f\n", Item2.PricePerItem);
    printf("Invoice Amount: $%.2f\n", calculateInvoiceAmount(Item2));

    return 0;
}
