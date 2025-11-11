#include <stdio.h>
#include <string.h>

#define MAX 100

struct Employee {
    char name[50];
    int id;
    float salary;
};

void sort(struct Employee e[], int n) {
    struct Employee temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j].id > e[j + 1].id) {
                temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

void add(struct Employee e[], int *n) {
    printf("Enter Name of Employee: ");
    scanf("%s", e[*n].name);
    printf("Enter Employee ID: ");
    scanf("%d", &e[*n].id);
    printf("Enter Employee's Salary: ");
    scanf("%f", &e[*n].salary);
    (*n)++;
    printf("Employee added successfully!\n");
}

void display(struct Employee e[], int n) {
    printf("\n------------- Employee Database -------------\n");
    printf("%-5s %-15s %-10s %-10s\n", "Sr.No", "Name", "ID", "Salary");
    printf("---------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-15s %-10d %-10.2f\n", i + 1, e[i].name, e[i].id, e[i].salary);
    }
}

void search(struct Employee e[], int n, int by, char nameKey[], int idKey) {
    int found = 0;
    if (by == 1) {
        for (int i = 0; i < n; i++) {
            if (strcmp(e[i].name, nameKey) == 0) {
                printf("Employee Found: %s | ID: %d | Salary: %.2f\n", e[i].name, e[i].id, e[i].salary);
                found = 1;
                break;
            }
        }
    } else if (by == 2) {
        sort(e, n);
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (e[mid].id == idKey) {
                printf("Employee Found: %s | ID: %d | Salary: %.2f\n", e[mid].name, e[mid].id, e[mid].salary);
                found = 1;
                break;
            } else if (e[mid].id < idKey)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    if (!found)
        printf("Employee not found...\n");
}

void modify(struct Employee e[], int n, int idKey) {
    for (int i = 0; i < n; i++) {
        if (e[i].id == idKey) {
            printf("Enter new name: ");
            scanf("%s", e[i].name);
            printf("Enter new salary: ");
            scanf("%f", &e[i].salary);
            printf("Employee modified successfully!\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void deleteEmp(struct Employee e[], int *n, int idKey) {
    for (int i = 0; i < *n; i++) {
        if (e[i].id == idKey) {
            for (int j = i; j < *n - 1; j++) {
                e[j] = e[j + 1];
            }
            (*n)--;
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

int main() {
    struct Employee e[MAX];
    int n = 0, choice;

    while (1) {
        printf("\n======= Employee Database Menu =======\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Modify Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) break;

        switch (choice) {
            case 1:
                add(e, &n);
                break;
            case 2:
                display(e, n);
                break;
            case 3: {
                int by;
                printf("Search by (1) Name or (2) ID: ");
                scanf("%d", &by);
                if (by == 1) {
                    char nameKey[50];
                    printf("Enter name to search: ");
                    scanf("%s", nameKey);
                    search(e, n, by, nameKey, 0);
                } else {
                    int idKey;
                    printf("Enter ID to search: ");
                    scanf("%d", &idKey);
                    search(e, n, by, "", idKey);
                }
                break;
            }
            case 4: {
                int idKey;
                printf("Enter ID to modify: ");
                scanf("%d", &idKey);
                modify(e, n, idKey);
                break;
            }
            case 5: {
                int idKey;
                printf("Enter ID to delete: ");
                scanf("%d", &idKey);
                deleteEmp(e, &n, idKey);
                break;
            }
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}