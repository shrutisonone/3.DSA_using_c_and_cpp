#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct Stack
{
    struct ListNode *top;
};

struct Stack *createStack(struct Stack *S)
{
    struct Stack *S;
    S = malloc(sizeof(struct Stack));
    S -> top = NULL;
    return S;
}

void push(struct Stack *S,int data)
{
    struct ListNode *temp;
    temp = malloc (sizeof(struct ListNode));
    if(!temp)
    {
      printf("Heap Overflow\n");
    return;
    }
    temp -> data = data;
    temp -> next = S -> top;
    S -> top =temp;
}

int size(struct Stack *S)
{
    int count = 0;
    struct ListNode *temp;
    if(isEmpty(S))
    {
        return 0;
    }
    temp = S -> top;
    while(temp)
    {
      count++;
      temp = temp -> next;
    }
    return count;
}

int isEmpty(struct Stack  *S)
{
    return S ->top =NULL;
}

int pop(struct Stack *S)
{
    int data;
    if(isEmpty(S))
    {
        return;
    }
    struct ListNode *temp;
    temp = S-> top;
    S ->top = S ->top -> next;
    data = temp -> data;
    free(temp);
}

int peek(struct Stack *S)
{
    if(isEmpty(S))
    {
        return;
    }
    return S -> top -> data;
}

void deleteStack(struct Stack *S)
{
    struct ListNode *temp,*p;
    p = S ->top;
    while(p)
    {
        temp = p-> next;
        p = p-> next;
        free(temp);
    }
    free(S);
}

int main()
{
    int i=0;
    struct Stack *S = createStack(S);
    for(i=0;i<10;i++)
    {
        push(S,i);
    }
    printf("Top Element is %d \n",peek(S));
    printf("The size of the element is %d \n",size(S));
    
    for(i=0;i<10;i++)
    {
        printf("The popped off element is %d ",pop(S));
    }
    
    if(isEmpty(S))
    {
        printf("The stack is empty\n");
    }
    else
    {
        printf("The stack is not empty\n");
    }

    delete(S);
    return 0;
}