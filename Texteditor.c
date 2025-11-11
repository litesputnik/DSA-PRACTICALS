#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char text[100];
    struct Node *next;
};

struct Node *head = NULL;


struct Node* createNode(char line[]) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->text, line);
    newNode->next = NULL;
    return newNode;
}


void insertLine(char line[]) {
    struct Node *newNode = createNode(line);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void displayText() {
    if (head == NULL) {
        printf("\nNo text available.\n");
        return;
    }
    struct Node *temp = head;
    int lineNo = 1;
    printf("\n--- Text Content ---\n");
    while (temp != NULL) {
        printf("%d: %s\n", lineNo++, temp->text);
        temp = temp->next;
    }
}


void deleteLine(int position) {
    if (head == NULL) {
        printf("No text to delete.\n");
        return;
    }
    struct Node *temp = head;
    if (position == 1) {
        head = temp->next;
        free(temp);
        printf("Line 1 deleted.\n");
        return;
    }
    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid line number.\n");
        return;
    }
    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
    printf("Line %d deleted.\n", position);
}


void searchWord(char word[]) {
    struct Node *temp = head;
    int lineNo = 1, found = 0;
    while (temp != NULL) {
        if (strstr(temp->text, word)) {
            printf("Found '%s' in line %d: %s\n", word, lineNo, temp->text);
            found = 1;
        }
        temp = temp->next;
        lineNo++;
    }
    if (!found)
        printf("Word '%s' not found.\n", word);
}


void countLines() {
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total number of lines: %d\n", count);
}

int main() {
    int choice, lineNo;
    char line[100], word[50];

    do {
        printf("\n--- Simple Text Editor ---\n");
        printf("1. Insert Line\n");
        printf("2. Display Text\n");
        printf("3. Delete Line\n");
        printf("4. Search Word\n");
        printf("5. Count Lines\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter line of text: ");
                fgets(line, sizeof(line), stdin);
                line[strcspn(line, "\n")] = '\0'; 
                insertLine(line);
                break;
            case 2:
                displayText();
                break;
            case 3:
                printf("Enter line number to delete: ");
                scanf("%d", &lineNo);
                deleteLine(lineNo);
                break;
            case 4:
                printf("Enter word to search: ");
                scanf("%s", word);
                searchWord(word);
                break;
            case 5:
                countLines();
                break;
            case 6:
                printf("Exiting Text Editor. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
