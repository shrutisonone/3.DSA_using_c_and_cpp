#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<assert.h>
#include<stdlib.h>

#define MAX_VERTICES 50
#define MAX_EDGES 50

struct graph
{
  int V;
  int E;
  int **adjMat;
};

struct Edge
{
   int src;
   int dest;
};

struct graph CreateGraph(const int NumVertices)
{
    assert(NumVertices >= 0); 
    int i,j;

    struct graph *G = (struct graph*)malloc(sizeof(struct graph)); //allocation of memory to grapg variable G same as of struct graph
    G->V =NumVertices; 
    G->E = 0;

    G->adjMat = malloc(sizeof(int*)* NumVertices);    //allocation of memory to row i.e. vertices
    assert(G != NULL);

    for(i=0 ; i < NumVertices ; i++)
    {
      G->adjMat[i] = calloc(NumVertices,sizeof(int));
      assert(G -> adjMat[i] != NULL);
    }
    return *G;
    
};

void DisplayGraph( struct graph *G)
{
    int i,j,v;
    v= G-> V;

    printf("Vertices %d,Edges %d \n",G->V,G->E);
    
    for(i=0 ; i< v ;i++)
    {
      for(j=0 ; j<v ; j++)
      {
         printf("%3d",(G->adjMat[i][j]));
         printf("\n");
      }
    }
}

void insertEdge(const struct graph *G,const struct edge *E)
{
  int x,y,v;
  v = G->V;
  
  x=E.src;
  y=E.dst;

  if(x>=v || y>=v)
  {
   printf(" Error\n");
   exit(EXIT_FAILURE);
  }

  if(G->adjMat[x][y] == 0)
  {
    G->adjMat[x][y] = 1;
    G->adjMat[y][x] = 1;
    G->E++;
  }
}

void DisplayEdge(const struct graph *G)
{
  int i,j,v;
  v = G->V;

  for(i=0 ; i<v ; i++)
  {
    for(j=0 ; j<v ; j++)
    {
      if(G->adjMat[i][j] == 1)
      {
        printf(" %d - %d",i,j);
      }
    }
  }
}

void removeEdge(struct graph *G,const struct edge *E)
{
  int x,v,y;
  v = G->V;

  x = E.src;
  y = E.dst;

  if(x>=v || y>=v)
  {
    printf(" Error \n");
    exit(EXIT_FAILURE);
  }

  if(G->adjMat [x][y] == 1)
  {
    G->adjMat[x][y] == 0;
    G->adjMat[y][x] == 0;
    (G->E);
  }
}

void destroyGraph(struct graph *G)
{
  if(G)
  {
    if(G->adjMat)
    {
      int i;
      for(i=0 ; i<G->V ; i++)
      {
        free(G->adjMat[i]);
        free(G->adjMat);
      }
      free(G);
    }
  }
}

struct edge newEdge(int x,int y)
{
  struct edge E;

  E.src= x;
  E.dst= y;

  return E;
};

struct graph *randomGraph(const int N,const float p)
{
    /* data */
    int i,j;
    struct edge E;
    struct graph *G = createGraph(N);

    for(i=0 ; i<N ; i++)
    {
       for(j=0 ; j<N ; j++)
       {
         if(rand() > p * RAND_MAX)
         {
          E=newEdge(i,j);
          insertEdge(G,E);
         }
       }
    }
    
};

int main(void)
{
//   struct egde E;
  struct graph *G = randomGraph(10,0.15);
  DisplayGraph(G);

}



