#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];
int graph[MAX][MAX];   // Adjacency matrix representation of graph
int n;                 // Number of vertices (global)

/* Function to insert an element into the queue */
void enqueue(int vertex)
{
    if (rear == MAX - 1) {   // Queue overflow check
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;          // Initialize front on first insertion
    }

    rear++;
    queue[rear] = vertex;
}

/* Function to remove an element from the queue */
int dequeue()
{
    int vertex;

    if (front == -1) {      // Queue underflow check
        printf("Queue is empty\n");
        return -1;
    }

    vertex = queue[front];
    front++;

    // Reset front and rear when queue becomes empty
    if (front > rear) {
        front = rear = -1;
    }

    return vertex;
}

/* Function to perform Breadth First Search traversal */
void bfs(int start)
{
    int i;

    enqueue(start);         // Enqueue the starting vertex
    visited[start] = 1;

    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);

        // Check all adjacent vertices
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main()
{
    int edges, src, dest;
    int i, j;

    printf("Enter number of vertices - ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    // Initialize graph and visited arrays to zero
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter number of edges - ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge (src dest) - ");
        scanf("%d %d", &src, &dest);

        // Validate vertex numbers before adding edge
        if (src >= 0 && src < n && dest >= 0 && dest < n) {
            // Undirected graph
            graph[src][dest] = 1;
            graph[dest][src] = 1;
        } else {
            printf("Invalid edge! Try again.\n");
            i--;    // Retry this iteration
        }
    }

    // Perform BFS starting from vertex 0
    printf("BFS starting from vertex 0:\n");
    bfs(0);

    return 0;
}
 
