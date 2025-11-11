#include <stdio.h>

void pattern1() {
    int i, j;
    for(i = 0; i <= 4; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}

void pattern2() {
    int rows, i, j, spaces;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    for(i = 0; i <= rows; i++) {
        for(spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
    for(i = rows - 1; i >= 1; i--) {
        for(spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

void pattern3() {
    int i, j, rows, spaces;
    printf("Enter no of rows: ");
    scanf("%d", &rows);
    for(i = 0; i <= rows; i++) {
        for(spaces = 1; spaces <= rows - i; spaces++) {
            printf(" ");
        }
        for(j = 1; j <= i; j++) {
            printf(" *");
        }
        printf("\n");
    }
}

void pattern4() {
    int i, spaces, rows;
    char ch;
    printf("Enter Number of rows: ");
    scanf("%d", &rows);
    for(i = 0; i <= rows; i++) {
        for(spaces = 1; spaces <= rows - i; spaces++) {
            printf("  ");
        }
        for(ch = 'A'; ch < 'A' + i; ch++) {
            printf("%c ", ch);
        }
        for(ch = 'A' + i - 2; ch >= 'A'; ch--) {
            printf("%c ", ch);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Pattern Menu ---\n");
        printf("1. Number Pattern 1\n");
        printf("2. Number Pyramid Pattern\n");
        printf("3. Star Pyramid Pattern\n");
        printf("4. Alphabet Pyramid Pattern\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: pattern1(); break;
            case 2: pattern2(); break;
            case 3: pattern3(); break;
            case 4: pattern4(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 5);
    return 0;
}
