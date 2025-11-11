#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    char url[100];
    struct Node *next;
};

struct Node *top = NULL;


void visitSite() {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMemory allocation failed.\n");
        return;
    }

    printf("\nEnter website URL: ");
    scanf("%s", newNode->url);

    newNode->next = top;
    top = newNode;

    printf("Website visited and added to history.\n");
}


void goBack() {
    struct Node *temp;

    if (top == NULL) {
        printf("\nNo previous history.\n");
        return;
    }

    temp = top;
    printf("\nGoing back from: %s\n", top->url);
    top = top->next;
    free(temp);
}


void showHistory() {
    struct Node *temp = top;
    int count = 0;

    if (temp == NULL) {
        printf("\nNo browsing history.\n");
        return;
    }

    printf("\n--- Browser History ---\n");
    while (temp != NULL) {
        count++;
        printf("%d. %s\n", count, temp->url);
        temp = temp->next;
    }
}


void clearHistory() {
    struct Node *temp;

    if (top == NULL) {
        printf("\nHistory already empty.\n");
        return;
    }

    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }

    printf("\nAll browsing history cleared.\n");
}


int main() {
    int choice;

    do {
        printf("\n=== Browser History System ===\n");
        printf("1. Visit New Website\n");
        printf("2. Go Back\n");
        printf("3. Show History\n");
        printf("4. Clear History\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                visitSite();
                break;
            case 2:
                goBack();
                break;
            case 3:
                showHistory();
                break;
            case 4:
                clearHistory();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}