#include<stdio.h>
#include<conio.h>

struct Queue
{
    int front;
    int rear;
    int capacity;
    int size;
    int *array;
};

//create an empty queue
struct Queue *createQueue(int capacity)
{
    struct Queue *Q = malloc(sizeof(struct Queue));
    if(!Q)
     return NULL;
    
    Q->capacity = capacity;
    Q->front = Q->rear = -1;
    Q->size = 0;
    Q->array = malloc(Q->capacity * sizeof(int));

    if(!Q->array)
    {
        return NULL;
    }
}

//returns queue size
int sizeofqueue(struct Queue *Q)
{
    return Q->size;
}

//returns front element of queue
int frontofQueue(struct Queue *Q)
{
   return Q->array[Q->front];
}

int rearofQueue(struct Queue *Q)
{
    return Q->array[Q->rear];
}

//check is Queue is empty or not 
int isEmpty(struct Queue *Q)
{
    return (Q->size == 0);
}

int ifFull(struct Queue *Q)
{
    return(Q->size == Q->capacity);
}

//adding element in queue
int enQueue(struct Queue *Q,int value)
{
    if(!Q->front)
     return NULL;
    if(isFull(Q))
     printf("The queue is full\n");
    else
    {
        Q->rear= (Q->rear+1) % Q->capacity;  //% Q->capacity is used to make sure that if the rear
        // exceeds the capacity of the queue, it wraps around to the beginning (circular queue)
        Q->array[Q->rear] = value;
        
        if(Q->front == -1)
          Q->front = Q->rear;
        Q->size += 1; //increments the size of the queue by 1, indicating that a new element has been added.
    }
}

int deQueue(struct Queue *Q,int value)
{
    if(!Q->front)
     return NULL;
    if(isEmpty(Q))
     printf("The queue is Empty\n");
    else
    {
        value = Q->array[Q->front];
        if(Q->front = Q->rear)
         Q->front=Q->rear=-1;
        else
         return Q->front = (Q->front+1) % Q->capacity;
    }
    return value;
}

void deletequeue(struct Queue *Q)
{
    if(Q)
    {
        if(Q->array)
        free(Q->array);
        free(Q);
    }
}


