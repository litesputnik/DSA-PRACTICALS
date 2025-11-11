# include <stdio.h>
# include <string.h>

# define MAX 100

struct Book{
    char title[100];
    char author[50];
    float price;
    int ISBN;
};

void addbook(struct Book books[], int *n){
    printf("Enter Book's Title: ");
    scanf("%s", books[*n].title);
    printf("Enter Book's Author: ");
    scanf("%s", books[*n].author);
    printf("Enter Book's price: ");
    scanf("%f", &books[*n].price);
    printf("Enter Book's ISBN: ");
    scanf("%d", &books[*n].ISBN);
    printf("Book was added!\n");
    (*n)++;
    return;
}

void displaybooks(struct Book books[], int n){
    if(n==0){
        printf("Book Store is Empty...\n");
    } else{
        printf("\n%-5s %-25s %-20s %-10s %-10s\n", "No.", "Title", "Author", "Price", "ISBN");
        printf("--------------------------------------------------------------\n");

        for(int i=0; i<n; i++){
            printf("\n%-5d %-25s %-20s %-10.2f %-10d", i+1, books[i].title, books[i].author, books[i].price, books[i].ISBN);
        }
        printf("\n");
    }
}

void bubblesort(struct Book books[], int n){
    struct Book temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j< n-i-1; j++){
            if(books[j].price > books[j+1].price){
                temp = books[j];
                books[j] = books[j+1];
                books[j+1] = temp;
            }
        }
    }
}

void selectionsort(struct Book books[], int n){
    int minindex;
    struct Book temp;
    for(int i=0; i<n-1; i++){
        minindex = i;
        for(int j=i+1; j<n; j++){
            if(books[j].ISBN < books[minindex].ISBN){
                minindex = j;
            }
        }
        temp = books[i];
        books[i] = books[minindex];
        books[minindex] = temp;
    }
}

void insertionsort(struct Book books[], int n){
    struct Book key;
    int j;

    for (int i = 1; i < n; i++) {
        key = books[i];
        j = i - 1;

        while (j >= 0 && strcmp(books[j].author, key.author) > 0) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }
}

int main(){
    struct Book books[MAX];
    int n = 0, choice;

    while(1){
        printf("===========Online Book Store==========\n");
        printf("1. Add book to book store.\n");
        printf("2. Display Books.\n");
        printf("3. Sort books using Bubble sort.\n");
        printf("4. Sort books using Selection sort.\n");
        printf("5. Sort books using Insertion sort.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addbook(books, &n);
                break;
            case 2:
                if(n == 0){
                    printf("No books in the store.\n");
                } else{
                    displaybooks(books, n);
                }
                break;
            case 3:
                if(n == 0){
                    printf("No books in the store please add books before sorting.\n");
                } else{
                    bubblesort(books, n);
                    printf("Sorted using Bubble sort.\n");
                }
                break;
            case 4:
                if(n == 0){
                    printf("No books in the store please add books before sorting.\n");
                } else{
                    selectionsort(books, n);
                    printf("Sorted using Selection sort.\n");
                }
                break;
            case 5:
                if(n == 0){
                    printf("No books in the store please add books before sorting.\n");
                } else{
                    insertionsort(books, n);
                    printf("Sorted using Insertion sort.\n");
                }
                break;
            case 6:
                printf("Exiting.\n");
                return 0;
            default:
                printf("Something went wrong.\n");
        }
    }
    return 0;
}
