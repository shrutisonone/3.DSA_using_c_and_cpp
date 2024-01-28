#include<stdio.h>
#include<conio.h>

void dijkstra(struct graph *G,int s)
{
  struct PriorityQueue *PQ = createPriorityQueue();
  
  int v,w;
  int Distance[sizeof(PQ)];
  enqueue(PQ,s);

  for(int i =0 ; i< G->V ; i++)
  {
    Distance[i] = -1;
  }
  Distance[s]=0;
  
  while(!isempty(PQ))
  {

    v=deleteMin(PQ);

    for all adjacent vertices w of v
    {
        int newdistance = Distance[w] + weight[v][w];
        if(Distance[w] == -1)
        {
            Distance[w] = new distance d;
            insert w in PriorityQueue with priority newdistance
            Path[w]= v;
        }

        if(Distance[w] > new distance )
        {
            Distance[w] = new distance d;
            update priority of vertex w to be d;
            Path[w]=v;
        }
    }
  };
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = 
    {
        {0, 2, 0, 1, 0, 0},
        {2, 0, 4, 4, 3, 0},
        {0, 4, 0, 0, 5, 0},
        {1, 4, 0, 0, 0, 6},
        {0, 3, 5, 0, 0, 8},
        {0, 0, 0, 6, 8, 0}
    };

    // Perform Dijkstra's algorithm starting from vertex 0
    dijkstra(graph, 0);

    return 0;
}