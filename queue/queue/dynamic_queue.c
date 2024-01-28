#include<stdio.h>
#include<conio.h>

struct DynaQueue
{
    int front;
    int rear;
    int capacity;
   // since the  int size;
    int *array;
};

//create an empty DynaQueue
struct DynaQueue *createDynaQueue(int capacity)
{
    struct DynaQueue *Q = malloc(sizeof(struct DynaQueue));
    if(!Q)
     return NULL;
    
    Q->capacity = capacity;
    Q->front = Q->rear = -1;
     // Q->size = 0;
    Q->array = malloc(Q->capacity * sizeof(int));

    if(!Q->array)
    {
        return NULL;
    }
}

//returns DynaQueue size
// int sizeofDynaQueue(struct DynaQueue *Q)
// {
// return Q->capacity
// }

//returns front element of DynaQueue
int frontofDynaQueue(struct DynaQueue *Q)
{
   return Q->array[Q->front];
}

int rearofDynaQueue(struct DynaQueue *Q)
{
    return Q->array[Q->rear];
}

//check is DynaQueue is empty or not 
int isEmpty(struct DynaQueue *Q)
{
    return (Q->front == -1);
}

int ifFull(struct DynaQueue *Q)
{
    return(Q->rear+1)% Q->capacity == Q->front;
}

int QueueSize(struct DynaQueue *Q)
{
    return (Q->capacity -Q->front +Q->rear +1)% Q->capacity;
}

//adding element in DynaQueue
int enDynaQueue(struct DynaQueue *Q,int value)
{
    if(!Q->front)
     return NULL;
    if(isFull(Q))
      resizeQueue(Q);
    else
    {
        Q->rear= (Q->rear+1) % Q->capacity;  //% Q->capacity is used to make sure that if the rear
        // exceeds the capacity of the DynaQueue, it wraps around to the beginning (circular DynaQueue)
        Q->array[Q->rear] = value;
        
        if(Q->front == -1)
          Q->front = Q->rear;
        //Q->size += 1; //increments the size of the DynaQueue by 1, indicating that a new element has been added.
    }
}

int resizeQueue(struct DynaQueue *Q)
{
    int size =  Q->capacity;
    Q->capacity = Q->capacity * 2;
    Q->array = malloc(sizeof(Q->capacity));
    if(!Q->array)
     printf("memory not allocated\n");
    if(Q->front > Q->rear)
    {
        for(int i = 0 ;  i<Q->front ; i++)
        {
            Q->array[i+size] =  Q->array[i];
        }
        Q->rear = Q->rear + size;
    }
}

int deDynaQueue(struct DynaQueue *Q,int value)
{
    if(isEmpty(Q))
     printf("The DynaQueue is Empty\n");
    else
    {
        value = Q->array[Q->front];
         // Check if there is only one element in the queue
        if(Q->front = Q->rear)
         Q->front=Q->rear=-1;
        else
        // Update the front index for the circular queue
         return Q->front = (Q->front+1) % Q->capacity;
    }
    return value;
}

void deleteDynaQueue(struct DynaQueue *Q)
{
    if(Q)
    {
        if(Q->array)
        free(Q->array);
        free(Q);
    }
}


