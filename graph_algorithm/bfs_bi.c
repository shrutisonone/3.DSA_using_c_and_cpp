#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Define a structure for a node in the adjacency list representing an edge
struct ListNode {
    int vertex;
    struct ListNode* next;
};

// Define a structure for the graph
struct Graph {
    int numVertices;
    struct ListNode* adjList[MAX_VERTICES];
};

// Function to initialize a graph with a given number of vertices
void initializeGraph(struct Graph* graph, int numVertices) {
    graph->numVertices = numVertices;

    // Initialize adjacency list for each vertex
    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Create a new node for the adjacency list
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src]; // Insert at the beginning
    graph->adjList[src] = newNode;
}

// Function to perform breadth-first search starting from a given vertex
void bfs(struct Graph* graph, int startVertex) {
    // Array to keep track of visited vertices
    int visited[MAX_VERTICES] = {0};

    // Create a queue for BFS and initialize it
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Enqueue the starting vertex and mark it as visited
    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);

    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Explore all adjacent vertices
        struct ListNode* currentNode = graph->adjList[currentVertex];
        while (currentNode != NULL) {
            int adjacentVertex = currentNode->vertex;

            // If the adjacent vertex is not visited, enqueue it and mark it as visited
            if (!visited[adjacentVertex]) {
                queue[rear++] = adjacentVertex;
                visited[adjacentVertex] = 1;
            }

            currentNode = currentNode->next;
        }
    }

    printf("\n");
}

int main() {
    // Example usage
    struct Graph myGraph;
    int numVertices = 6;

    // Initialize the graph
    initializeGraph(&myGraph, numVertices);

    // Add edges
    addEdge(&myGraph, 0, 1);
    addEdge(&myGraph, 0, 2);
    addEdge(&myGraph, 1, 3);
    addEdge(&myGraph, 1, 4);
    addEdge(&myGraph, 2, 4);
    addEdge(&myGraph, 3, 5);
    addEdge(&myGraph, 4, 5);

    // Perform BFS starting from vertex 0
    bfs(&myGraph, 0);

    return 0;
}
