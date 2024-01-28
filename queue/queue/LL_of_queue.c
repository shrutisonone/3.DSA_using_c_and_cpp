#include <stdio.h>
#include <conio.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct Queue
{
    int *front;
    int *rear;
};

struct Queue *createQueue(int capacity)
{
    struct Queue *Q = malloc(sizeof(struct Queue));

    Q->front = Q->rear = NULL;
    return Q;
}

int isEmpty(struct Queue *Q)
{
    return (Q->front == NULL);
}

void enQueue(struct Queue *Q, int data)
{
    struct ListNode *newNode;
    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (!newNode)
        return NULL;

    newNode->data = data;
    newNode->next = NULL;
    if(Q->front == NULL)
    {
        Q->front = Q->rear = NULL;
    }
    else
    {
        Q->rear = NULL;

    }
    
}

int deQueue(struct Queue *Q,int data)
{
   data = 0;
   struct ListNode *temp;

   if(Q->front == NULL)
    printf("Queue is Empty\n");
   else
    {
      temp = Q->front ;
      data = temp->data;
      Q->front = temp ->next;
      free(temp);
    }
    return data;
}

void deletequeue(struct Queue *Q)
{
    struct ListNode *temp;
    while(Q)
    {
        temp=Q->front;
        Q->front=temp->next;
        free(temp);
    }
    free(Q);
}
int main()
{
    struct ListNode *front;
    struct ListNode *rear;

    return 0;
}