#include<stdio.h>

struct Graph *adjMatofGraph()
{
    int i; 
    int V;
    int E;
    int **adj;
    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph*));
    if(!G)
    {
        return ;
    }

    scanf("Number of vertices %d, Number of Edges %d",&G->V,&G->E);
    G->adj=malloc(sizeof(int*)*G->V);

    for(int u = 0 ; u < G->V ; u++)
    {
        for(int v = 0 ; v < G->V ; v++)
        { 
            G -> adj[v][v] =0;
        }
    }
    for( i = 0 ; i < G->E ; i++)
    {
        scanf("Reading Edge: %d%d",&u,&v);

        G->adj[u][v]=1;
        G->adj[v][u]=1;
    }
    return G;
};

