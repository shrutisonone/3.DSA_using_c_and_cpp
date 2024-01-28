#include <stdio.h>
#include <conio.h>

void reverse_first_k_ele(struct Queue *Q, int k)
{
    if (!Q)
        return;
    if (k > sizeof(Q))
        return -1;
    
    for(int i = 0 ; i < k ; i++)
    {
        push(S,deQueue(Q));
    }
    while(!isEmpty(S))
    {
        enQueue(Q,pop(S));
    }
    for( int i = 0 ; size(Q)-k ; i++)
    {
        enQueue(Q,deQueue(Q));
    }

}