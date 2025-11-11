# include <stdio.h>
# include <string.h>

# define MAX 100

struct Contact{
    char name[50];
    long long number;
};

void addcontact(struct Contact contacts[], int *n);
void displaycontacts(struct Contact contacts[], int n);
void sortcontacts(struct Contact contacts[], int n);
void linearsearch(struct Contact contacts[], int n, char key[]);
void binarysearch(struct Contact contacts[], int n, long long key);

int main(){
    struct Contact contacts[MAX];
    int n=0, choice;
    char namekey[50];
    long long numberkey;

    while(1){
        printf("\n========Contact Manager=======\n");
        printf("1. Add Contact.\n");
        printf("2. Display Contact.\n");
        printf("3. Search by name (Linear Search): \n");
        printf("4. Search by number (Binary Search): \n");
        printf("5. Exit.\n");
        printf("Please enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addcontact(contacts, &n);
                break;
            case 2:
                displaycontacts(contacts, n);
                break;
            case 3:
                if(n==0){
                    printf("No contacts to search: \n");
                } else{
                    printf("Enter name to search: ");
                    scanf("%s", namekey);
                    linearsearch(contacts, n, namekey);
                }
                break;
            case 4:
                if(n==0){
                    printf("No contact to search: \n");
                } else {
                    printf("Enter number to search: ");
                    scanf("%lld", &numberkey);
                    binarysearch(contacts, n, numberkey);
                }
                break;
            case 5:
                printf("Exiting....\n");
                return 0;
            default:
                printf("Something went wrong. \n");
        }
    }
}

/* Add Contact */
void addcontact(struct Contact contacts[], int *n){
    printf("Enter name: ");
    scanf("%s", contacts[*n].name);
    printf("Enter number: ");
    scanf("%lld", &contacts[*n].number);
    (*n)++;
    printf("Contact added sucessfully!\n");
    return;
}

/* Display Contacts */
void displaycontacts(struct Contact contacts[], int n){
    if(n==0){
        printf("No contact to display!!!\n");
    } else {
        printf("\n-------Contact List------\n");
        for(int i=0; i<n; i++){
            printf("%d. %-15s %lld\n", i+1, contacts[i].name, contacts[i].number);
        }
    }
}

/* Sort Contacts */
void sortcontacts(struct Contact contacts[], int n){
    struct Contact temp;
    for(int i=0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(contacts[i].number > contacts[j].number){
                temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

/* Linear Search */
void linearsearch(struct Contact contacts[], int n, char key[]){
    int found = 0;
    for(int i=0; i<n; i++){
        if(strcmp(contacts[i].name, key)==0){
            printf("Contact found: %s - %lld\n", contacts[i].name, contacts[i].number);
            found=1;
            break;
        } 
    }
    if(!found){
        printf("Contact not found.\n");
    }
}

/* Binary Search */
void binarysearch(struct Contact contacts[], int n, long long key){
    sortcontacts(contacts, n);
    int low=0, high=n-1, mid, found=0;
    while(low<=high){
        mid = (low+high)/2;
        if(contacts[mid].number==key){
            printf("Contact found: %s - %lld", contacts[mid].name, contacts[mid].number);
            found = 1;
            return;
        } else if(contacts[mid].number<key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if(!found){
        printf("Contact Not Found!\n");
    }
    return;
}