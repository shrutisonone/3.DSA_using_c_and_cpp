#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<assert.h>
#include<stdlib.h>

struct ListNode
{
  int vertex;
  struct ListNode *next;
};

struct Edge
{
    int src;
    int dst;
};

struct graph
{
 int V;
 int E;
 struct ListNode *adjList[];
};

void rand_init(void)
{
  time_t t;
  srand((unsigned)time(&t));
}

int insertEdge(struct graph *G,int src,int dst)
{
    int n,from,to;
    from = src;
    to = dst;
    n = G -> V;
   
    if( to >= n || from >= n)
    {

        return -1;
    }

    struct ListNode *prev = NULL ,*ptr = G->adjList[from];
    
    while(ptr != NULL)
    {
      if(ptr ->vertex == to)
       return 0;
      else
      {
        prev = ptr;
        ptr = ptr -> next;
      }
    }
    if(ptr == NULL)
    {
        struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->vertex = to;
        newNode->next = NULL;

        if(prev == NULL)
        {
            G->adjList[from] = newNode;
        }
        else
        {
            prev->next = newNode;
        }
    }
    return 1;
}

int removeEdge(struct  graph *G,int src,int dst)
{ 

  int n , from , to;
  n =  G-> V;
  from =src;
  to = dst;

  if( from >n || from <0 || to <0 || to >n)
  {
    return -1;
  }

  struct ListNode *prev = NULL , *ptr = G->adjList[from];
  while( ptr!= NULL )
  {
    if(ptr->vertex == to)
    {
        if(prev == NULL)
        {
            G->adjList[from] = ptr->next;
            free(ptr);
        }
        else
        {
            prev->next = ptr->next;
        }
    }
  }
 return 0;
}

struct graph *createGraph(int numVertices)
{
  assert( numVertices >= 0);

  int i,j;

  //create a graph with numvertices
  struct graph *G = (struct graph*)malloc(sizeof(struct graph));
  G->V = numVertices;
  G->E = 0;

  //allocation of memory to column
  for( i=0 ; i<numVertices ; i++)
  {
   G->adjList[i]= (struct ListNode*)malloc(sizeof(struct ListNode));
   assert(G->adjList != NULL);
   G->adjList[i]->vertex = i;
   G->adjList[i]->next = NULL;
  }
  return G;
 }

 struct Edge newEdge(int x,int y)
 {
  struct Edge e;
  e.src = x;
  e.dst = y;
  return e;
 };

 struct graph *randomGraph(int N,float p)
 {
  //random graph of N vertices and probabilty p for each edge
  int i,j;
  struct Edge e;
  struct graph *G = createGraph(N);
  rand_init();

  for(i=0 ; i<N ; i++)
  {
    if(rand() < p*RAND_MAX)
    {
      e= newEdge(i,j);
      insertEdge(G,i,j);
    }
  }
  return G;
 }

void DisplayGraph(struct graph *G)
{
  int i;

  for(i=0 ; i<G->V ; i++)
  {
    printf("%d \t",G->adjList[i]);
  }
}

void DestroyGraph(struct graph *G)
{
  int i;
  struct ListNode *temp,*ptr;
  for(i=0 ; i<G->V ; i++)
  {
    ptr = G->adjList[i];
     while( ptr != NULL)
     {
      temp = ptr;
      ptr= ptr-> next;
      free(temp);
     }
     G->adjList[i] = NULL;
  }
  printf("The Graph is deleted \n");
}

int main()
{
 struct Edge E;
 struct graph *G = randomGraph(10,0.15);
 DisplayGraph(G);
 E=newEdge(4,5);
 insertEdge(G,4,5);
 DisplayGraph(G);
 printf("\n");
 removeEdge(G,4,5);
 DisplayGraph(G);
 printf("\n");
 DestroyGraph(G);
 return 0;
}


