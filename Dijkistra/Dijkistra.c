#include <stdio.h>
#include <stdbool.h>

#define MAX 10          // Maximum number of vertices allowed
#define INF 9999        // A very large number used to represent "no connection"

// Function prototype
void dijkstra(int graph[MAX][MAX], int n, int start);

int main() {
    int graph[MAX][MAX], n, i, j;
    int start;

    // Ask user for number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input graph matrix
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) {     // If edge doesn't exist
                graph[i][j] = INF;     // Replace 0 with INF
            }
        }
    }

    // Source vertex
    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Call Dijkstra function
    dijkstra(graph, n, start);

    return 0;
}

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int distance[MAX];     // Stores shortest distances
    bool visited[MAX];     // Tracks visited vertices
    int i, v;

    // Initialize distances and visited array
    for (i = 0; i < n; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[start] = 0;   // Distance to source = 0

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int minDistance = INF;
        int nextNode = -1;

        // Select minimum distance vertex
        for (v = 0; v < n; v++) {
            if (!visited[v] && distance[v] < minDistance) {
                minDistance = distance[v];
                nextNode = v;
            }
        }

        visited[nextNode] = true;  // Mark selected vertex as visited

        // Update distances of neighbors
        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[nextNode][v] != INF) {
                int newDist = distance[nextNode] + graph[nextNode][v];
                if (newDist < distance[v]) {
                    distance[v] = newDist;
                }
            }
        }
    }

    // Output results
    printf("Vertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, distance[i]);
    }
}

