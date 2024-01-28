struct ListNode
{
    int vertexNumber;
    struct ListNode *next;
}

struct Graph *adjListOfGraph()
{
    int x,y,i;
    struct ListNode *temp;

    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
    if(!G)
    {
        return NULL;
    }

    scanf("Number of Vertices %d , Number of Edges %d",&G->V,&G->E);
    G->adj = malloc(G->V *sizeof(struct ListNode));

    for(i=0 ; i < G->V ; i++)
    {
        scanf("Reading Edge %d %d",&x,&y);
        temp = (struct ListNode *)malloc(struct ListNode);
        temp->vertexNumber = y;
        temp->next = G->adj[x];
        G->adj[x]->next=temp;
        temp = (struct ListNode*)malloc(struct ListNode);
        temp->vertexNumber=y;
        temp->next=G->adj[y];
        G->adj[y]->next=temp;
    }
    return G;
}