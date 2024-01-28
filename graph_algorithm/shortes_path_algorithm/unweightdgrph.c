void unweightedSA(struct graph *G,int s)
{
    /*
    Create a Queue: Imagine you have a line (queue) where you can add people (vertices) at the end and remove them from the front.
    */
    struct Queue *Q = createQueue();

    // Initialize Variables and Enqueue Source: Set up some variables and put the starting point (source) in the line.
    int v,w;
    enQueue(Q,s);
    
    // Initialize Distances: Pretend you have a list to keep track of how far each person is from the starting point. Initially, 
    // assume everyone is infinitely far away.
    for(int i=0 ; i<G->V ; i++)
    {
        Distance[i] = -1;
    }
    // Set Source Distance: But we know the distance from the starting point to itself is 0.
    Distance[s]=0;

    //checking untill it is empty
    while( !isEmpty(Q))
    {
        //first person la line madhe anla
        v = deQueue(Q);
        
        //for all adjacent vertices of v, if not visited yet then mark them and enqueue them.
        for each w adjacent to v

        //If a friend hasn't been visited yet, do the followin.
        if(Distance[w] == -1)
        {
            Distance[w] = Distance[v] + 1; //upadation of distance
            Path[w] = v;
            enQueue(Q,w); //adding into the queue
        }
    }
    deleteQueue(Q);
}