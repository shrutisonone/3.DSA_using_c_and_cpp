#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

struct ListNode
{
    int vertex;
    struct ListNode *next;
};

struct graph 
{
    int numVertices;
    struct ListNode *adjList[MAX_VERTICES];
};

void CreateGraph(struct graph *G,int numVertices)
{
  G->numVertices = numVertices;
  
  // Initialize adjacency list for each vertex
    for (int i = 0; i < numVertices; ++i) 
    {
        G->adjList[i] = NULL;
    }
}

void addEdge(struct graph *G,int src,int dst)
{
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->vertex=dst;
    newNode->next = G->adjList[src];
    G->adjList[src] = newNode;
}

void bfs(struct graph *G,int startVertex)
{
    // Array to keep track of visited vertices
    //amking an array named visited of size vertex
    int visited[MAX_VERTICES] = {0};

    int queue[MAX_VERTICES]; //creation and initialization of queue
    int front,rear;
    front=0,rear=0;

    queue[rear++]=startVertex;  //queue cha last madhe start vertex takla
    visited[startVertex] = 1;  //ani strt vrtex la visited dakhavla

    printf("Breadth-First Search starting from vertex %d:\n", startVertex);

    while(front < rear)
    {
        //taking the elements out one by one
        int currentVertex = queue[front++];
        printf(" The current vertex is %d",currentVertex);

        struct ListNode *currentNode = G->adjList[currentVertex];
        while(currentNode != NULL)
        {
            int adjacentVertex = currentNode -> vertex;

            if(!visited[adjacentVertex])
            {
                queue[rear++]=adjacentVertex;
                visited[adjacentVertex]=1;
            }
            currentNode = currentNode-> next;
        }
    }
    printf("\n");
}

int main()
{
    struct graph *myGraph;
    int numVertices = 6;

    // Initialize the graph
    CreateGraph(myGraph, numVertices);
    
    // Add edges
    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 2);
    addEdge(myGraph, 1, 3);
    addEdge(myGraph, 1, 4);
    addEdge(myGraph, 2, 4);
    addEdge(myGraph, 3, 5);
    addEdge(myGraph, 4, 5);

    // Perform BFS starting from vertex 0
    bfs(myGraph, 0);

    return 0;
}
