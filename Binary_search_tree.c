#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[15];
    struct Node *left, *right;
};


struct Node* createNode(char name[], char phone[]) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct Node* insert(struct Node *root, char name[], char phone[]) {
    if (root == NULL)
        return createNode(name, phone);
    
    if (strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, phone);
    else if (strcmp(name, root->name) > 0)
        root->right = insert(root->right, name, phone);
    else
        printf("Contact already exists!\n");
    
    return root;
}


struct Node* search(struct Node *root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;

    if (strcmp(name, root->name) < 0)
        return search(root->left, name);
    else
        return search(root->right, name);
}


void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %-20s | Phone: %s\n", root->name, root->phone);
        inorder(root->right);
    }
}


void preorder(struct Node *root) {
    if (root != NULL) {
        printf("Name: %-20s | Phone: %s\n", root->name, root->phone);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("Name: %-20s | Phone: %s\n", root->name, root->phone);
    }
}


int main() {
    struct Node *root = NULL;
    int choice;
    char name[50], phone[15];
    struct Node *found;

    do {
        printf("\n--- Online Directory System (BST) ---\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Inorder (Alphabetical)\n");
        printf("4. Display Preorder\n");
        printf("5. Display Postorder\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter Phone Number: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = '\0';
                root = insert(root, name, phone);
                printf("Contact added successfully!\n");
                break;

            case 2:
                printf("Enter Name to Search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                found = search(root, name);
                if (found != NULL)
                    printf("Contact Found: %s - %s\n", found->name, found->phone);
                else
                    printf("Contact Not Found!\n");
                break;

            case 3:
                printf("\n--- Inorder Traversal (Alphabetical Order) ---\n");
                inorder(root);
                break;

            case 4:
                printf("\n--- Preorder Traversal ---\n");
                preorder(root);
                break;

            case 5:
                printf("\n--- Postorder Traversal ---\n");
                postorder(root);
                break;

            case 6:
                printf("Exiting Directory System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}