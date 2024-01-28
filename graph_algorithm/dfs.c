#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

struct ListNode 
{
    int vertex;
    struct ListNode *next;
};

struct graph
{
  int numVertices;
  struct ListNode* adjList[MAX_VERTICES];
};

void createGraph(struct graph *G,int numVertices)
{
    G->numVertices = numVertices;
    //initialize all the array elements of adj list to null
    for(int i= 0 ; i< numVertices ;i++)
    {
        G->adjList[i] = NULL;
    }
}

void addEdge(struct graph *G,int src,int dest)
{
  struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
  newNode->vertex = dest;
  newNode->next = G->adjList[src]; 
  G->adjList[src]=newNode;
}

// Recursive function to perform depth-first search from a given vertex
void dfsHelper(struct graph *G, int vertex, int visited[]) 
{
  visited[vertex]=1;
  //marking of 1st vertex to visited

  printf("The 1st Visited Vertex %d",vertex);

  // Traverse all adjacent vertices
    struct ListNode* currentNode = G->adjList[vertex];
    while( currentNode != NULL)
    {
        int adjacentVertex = currentNode->vertex;

        if(adjacentVertex != visited)
        {
            dfsHelper(G,adjacentVertex,visited);
        }
        currentNode = currentNode -> next;
    }
}

// Function to perform depth-first search starting from a given vertex
void dfs(struct Graph* G, int startVertex) {
    // Array to keep track of visited vertices
    int visited[MAX_VERTICES] = {0};

    printf("Depth-First Search starting from vertex %d:\n", startVertex);
    dfsHelper(G, startVertex, visited);
    printf("\n");
}


int main() {
    // Example usage
    struct Graph *myGraph;
    int numVertices = 5;

    // Initialize the graph
    createGraph(&myGraph, numVertices);

    // Add edges
    addEdge(&myGraph, 0, 1);
    addEdge(&myGraph, 0, 2);
    addEdge(&myGraph, 1, 3);
    addEdge(&myGraph, 2, 4);

    // Perform DFS starting from vertex 0
    dfs(&myGraph, 0);

    return 0;
}