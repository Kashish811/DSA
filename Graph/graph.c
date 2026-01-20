#include <stdio.h>
#include <stdlib.h>

// Node structure for adjacency list
struct Node {
    int data;               // Vertex number
    struct Node* next;      // Pointer to next node
};

// Create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert an edge between src and dest (undirected graph)
void insertEdge(struct Node* adj[], int src, int dest) {
    struct Node* newNode1 = createNode(dest);
    newNode1->next = adj[src];
    adj[src] = newNode1;

    struct Node* newNode2 = createNode(src);
    newNode2->next = adj[dest];
    adj[dest] = newNode2;
}

// Display the adjacency list of the graph
void displayAdjList(struct Node* adj[], int V) {
    printf("\nAdjacency List:\n");

    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        struct Node* temp = adj[i];

        while (temp != NULL) {
            printf("-> %d ", temp->data);
            temp = temp->next;
        }
        printf("-> NULL\n");
    }
}

// Delete an edge between src and dest
void deleteEdge(struct Node* adj[], int src, int dest) {
    struct Node *temp, *prev;

    // Delete dest from src's list
    temp = adj[src];
    prev = NULL;

    while (temp != NULL && temp->data != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL)
            adj[src] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    // Delete src from dest's list
    temp = adj[dest];
    prev = NULL;

    while (temp != NULL && temp->data != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL)
            adj[dest] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
}

// Delete a vertex and all its edges
void deleteNode(struct Node* adj[], int V, int vertex) {
    if (vertex < 0 || vertex >= V) {
        printf("Invalid vertex! Please enter a value between 0 and %d.\n", V - 1);
        return;
    }

    struct Node* temp = adj[vertex];

    // Delete all edges connected to this vertex
    while (temp != NULL) {
        int connectedVertex = temp->data;
        deleteEdge(adj, vertex, connectedVertex);
        temp = adj[vertex]; // Update after deletion
    }

    printf("Vertex %d and all its connected edges deleted.\n", vertex);
    displayAdjList(adj, V);
}

int main() {
    int V;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    struct Node** adj = (struct Node**)malloc(V * sizeof(struct Node*));
    if (adj == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < V; i++) {
        adj[i] = NULL;
    }

    int choice, src, dest, vertex;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert Edge\n");
        printf("2. Delete Node\n");
        printf("3. Display Adjacency List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source and destination vertices (src dest): ");
                scanf("%d %d", &src, &dest);

                if (src >= 0 && src < V && dest >= 0 && dest < V) {
                    insertEdge(adj, src, dest);
                    printf("Edge from %d to %d inserted.\n", src, dest);
                } else {
                    printf("Invalid vertices! Please enter values between 0 and %d.\n", V - 1);
                }
                break;

            case 2:
                printf("Enter vertex to delete: ");
                scanf("%d", &vertex);
                deleteNode(adj, V, vertex);
                break;

            case 3:
                displayAdjList(adj, V);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }

    } while (choice != 4);

    return 0;
}

