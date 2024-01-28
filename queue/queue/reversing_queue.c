#include <stdio.h>
#include <conio.h>

void reverseQueue(struct Queue *Q)
{
    struct Stack *S;
    while(!isEmpty(Q))
    {
      push(S,deQueue(Q)); //tkaing single element fron queue n putin it into stk
    }
    while(!isEmpty(S))
    {
        enQueue(Q,pop(S));//poping stack top element and puting in queue
    }
}