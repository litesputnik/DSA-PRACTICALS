#include <stdio.h>
#include <string.h>

#define MAX 5   

struct Parcel {
    int id;
    char sender[50];
    char receiver[50];
    float weight;
};

struct Queue {
    struct Parcel parcels[MAX];
    int front;
    int rear;
};


void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}


int isFull(struct Queue *q) {
    return q->rear == MAX - 1;
}


int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}


void addParcel(struct Queue *q) {
    if (isFull(q)) {
        printf("\nQueue is full. Cannot add more parcels.\n");
        return;
    }

    struct Parcel p;
    printf("\nEnter Parcel ID: ");
    scanf("%d", &p.id);
    printf("Enter Sender Name: ");
    scanf("%s", p.sender);
    printf("Enter Receiver Name: ");
    scanf("%s", p.receiver);
    printf("Enter Parcel Weight (kg): ");
    scanf("%f", &p.weight);

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->parcels[q->rear] = p;

    printf("Parcel added successfully.\n");
}


void dispatchParcel(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nNo parcels to dispatch.\n");
        return;
    }

    struct Parcel p = q->parcels[q->front];
    printf("\nParcel Dispatched:\n");
    printf("ID: %d | Sender: %s | Receiver: %s | Weight: %.2f kg\n",
           p.id, p.sender, p.receiver, p.weight);

    q->front++;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}


void displayQueue(struct Queue *q) {
    int i;
    if (isEmpty(q)) {
        printf("\nNo parcels in queue.\n");
        return;
    }

    printf("\nParcels in Queue:\n");
    printf("---------------------------------------------\n");
    printf("%-10s %-15s %-15s %-10s\n", "ID", "Sender", "Receiver", "Weight");
    printf("---------------------------------------------\n");

    for (i = q->front; i <= q->rear; i++) {
        printf("%-10d %-15s %-15s %-10.2f\n",
               q->parcels[i].id,
               q->parcels[i].sender,
               q->parcels[i].receiver,
               q->parcels[i].weight);
    }
    printf("---------------------------------------------\n");
}


int main() {
    struct Queue q;
    int choice;
    initQueue(&q);

    do {
        printf("\n--- Post Office Parcel Handling System ---\n");
        printf("1. Add Parcel\n");
        printf("2. Dispatch Parcel\n");
        printf("3. Display Parcels\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addParcel(&q);
                break;
            case 2:
                dispatchParcel(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}