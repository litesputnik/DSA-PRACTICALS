#include <stdio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void createGraph() {
    int edges, src, dest;
    printf("Enter number of locations (vertices): ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of paths (edges): ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter path %d (source destination): ", i + 1);
        scanf("%d%d", &src, &dest);
        if (src >= 0 && src < n && dest >= 0 && dest < n) {
            adj[src][dest] = 1;
            adj[dest][src] = 1; 
        } else {
            printf("Invalid path! Please enter valid vertex numbers.\n");
            i--;
        }
    }
    printf("Graph created successfully!\n");
}


void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}


void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}


void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("%d ", start);
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int choice, start;
    do {
        printf("\n--- Campus Navigation System ---\n");
        printf("1. Create Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. DFS Traversal\n");
        printf("4. BFS Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                displayMatrix();
                break;
            case 3:
                for (int i = 0; i < n; i++)
                    visited[i] = 0;
                printf("Enter starting location (0 to %d): ", n - 1);
                scanf("%d", &start);
                printf("DFS Traversal: ");
                DFS(start);
                printf("\n");
                break;
            case 4:
                printf("Enter starting location (0 to %d): ", n - 1);
                scanf("%d", &start);
                printf("BFS Traversal: ");
                BFS(start);
                printf("\n");
                break;
            case 5:
                printf("Exiting Navigation System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
    return 0;
}