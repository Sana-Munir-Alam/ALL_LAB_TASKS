#include <stdio.h>
#include <stdlib.h>

#define MaxItems 100
#define MaxBoxes 100

struct Box {
    int weight;
    int items[MaxItems];
    int itemCount;
    struct Box* nestedBox;
};
int calculateTotalWeight(struct Box* box) {
    int totalWeight = box->weight;
    for (int i = 0; i < box->itemCount; i++) {
        totalWeight += box->items[i];
    }
    if (box->nestedBox != NULL) {
        totalWeight += calculateTotalWeight(box->nestedBox);
    }
    return totalWeight;
}

struct Box* createBox() {
    struct Box* newBox = (struct Box*)malloc(sizeof(struct Box));
    newBox->nestedBox = NULL;

    printf("Enter the weight of this box: ");
    scanf("%d", &newBox->weight);

    printf("Enter the number of items in this box: ");
    scanf("%d", &newBox->itemCount);
    if (newBox->itemCount > 0) {
        newBox->nestedBox = NULL;
    } else {
        printf("Does this box contain another box? (1 for yes, 0 for no): ");
        int hasNestedBox;
        scanf("%d", &hasNestedBox);

        if (hasNestedBox == 1) {
            printf("Creating nested box:\n");
            newBox->nestedBox = createBox();
        }
    }
    for (int i = 0; i < newBox->itemCount; i++) {
        printf("Enter weight of item %d: ", i + 1);
        scanf("%d", &newBox->items[i]);
    }

    return newBox;
}

int main() {
    printf("Creating the outermost box:\n");
    struct Box* mainBox = createBox();

    int totalWeight = calculateTotalWeight(mainBox);
    printf("\nThe total weight of the box (including nested boxes) is: %d\n", totalWeight);
    return 0;
}
