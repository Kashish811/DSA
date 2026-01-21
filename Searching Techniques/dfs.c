#include <stdio.h>
#include <stdlib.h>

#define MAX 100    // Define the maximum number of vertices allowed

int stack[MAX], top = -1;
int visited[MAX];
int graph[MAX][MAX];   // Adjacency matrix to represent the graph
int n;

/* Function to push a vertex onto the stack */
void push(int vertex)
{
    if (top == MAX - 1) {   // Check for overflow condition
        printf("Stack overflow\n");
    } else {
        stack[++top] = vertex;   // Increment top and insert vertex
    }
}

/* Function to pop a vertex from the stack */
int pop()
{
    if (top == -1) {        // Check if stack is empty
        return -1;
    } else {
        return stack[top--]; // Return top element and decrement top
    }
}

/* Function to perform Depth-First Search (DFS) */
void dfs(int start)
{
    int i;

    push(start);
    visited[start] = 1;

    printf("DFS Path: ");

    while (top != -1) {     // Continue until stack becomes empty
        int current = pop();
        printf("%d ", current);

        // Check all adjacent vertices
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                push(i);           // Push unvisited adjacent vertex
                visited[i] = 1;    // Mark it as visited
            }
        }
    }
}

int main()
{
    int edges, src, dest;
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;   // No edge initially
        }
    }

    // Input edges for an undirected graph
    for (i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);

        // Validate input vertices
        if (src < 0 || src >= n || dest < 0 || dest >= n) {
            printf(
                "Invalid edge! Vertices must be between 0 and %d.\n",
                n - 1
            );
            i--;    // Retry this edge
            continue;
        }

        graph[src][dest] = 1;
        graph[dest][src] = 1;
    }

    printf("\nDFS starting from vertex 0:\n");
    dfs(0);

    return 0;
}

