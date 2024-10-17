#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

// Function prototypes
void BFS(int graph[MAX][MAX], int visited[MAX], int n, int start);
void DFS(int graph[MAX][MAX], int visited[MAX], int n, int start);
void DFSUtil(int graph[MAX][MAX], int visited[MAX], int n, int vertex);

// Main function
int main() {
    int graph[MAX][MAX], visited[MAX] = {0};
    int n, i, j, start;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (0 for no edge, 1 for edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the starting vertex for BFS and DFS
    printf("Enter the starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);

    // Perform BFS
    printf("\nBFS starting from vertex %d:\n", start);
    BFS(graph, visited, n, start);

    // Reset visited array for DFS
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS
    printf("\nDFS starting from vertex %d:\n", start);
    DFS(graph, visited, n, start);

    return 0;
}
// BFS function
void BFS(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    int queue[MAX], front = -1, rear = -1;
    visited[start] = 1;  // Mark the starting vertex as visited
    queue[++rear] = start;  // Enqueue the starting vertex

    while (front != rear) {
        front++;
        int currentVertex = queue[front];
        printf("%d ", currentVertex);  // Print the current vertex

        // Traverse all the adjacent vertices of the current vertex
        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;  // Mark as visited
                queue[++rear] = i;  // Enqueue the vertex
            }
        }
    }
}
// DFS function
void DFS(int graph[MAX][MAX], int visited[MAX], int n, int start) {
    visited[start] = 1;  // Mark the starting vertex as visited
    printf("%d ", start);  // Print the current vertex

    // Traverse all the adjacent vertices of the current vertex
    for (int i = 0; i < n; i++) {
        if (graph[start][i] == 1 && !visited[i]) {
            DFS(graph, visited, n, i);  // Recur for the adjacent vertex
        }
    }
}