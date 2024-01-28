#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>

struct Stack
{
  int top;
  int capacity;
  int *array;
};

struct Stack* createStack(int capacity)
{
    struct Stack* S= malloc(sizeof(struct Stack));
    if(!S)
    {
        return NULL;
    }

    S->capacity=capacity;
    S->top = -1;
    S->array=malloc(S->capacity* sizeof(int));
    if(!S->array)
     return NULL;
    return S;
}

int isEmpty(struct Stack* S)
{
    return (S->top == -1);
}

int size(struct Stack *S)
{
    return (S->top +1);
}

int isFull(struct Stack* S)
{
    return (S->top == S->capacity - 1);
}

void push(struct Stack* S ,int data)
{
    if(isFull(S))
    {
        printf("Stack Overflow");
    }
    else
    {
        S->array[++S->top]=data;
    }
}

int pop(struct Stack* S)
{
    if(isEmpty(S))
    {
        printf("\nString is Empty \n");
        return INT_MIN;
    }
    else
    {
        return (S->array[S->top--]);
    }
}                              

int peek(struct Stack* S)
{
    if(isEmpty(S))
    {
    printf(" Stack is Empty\n");
    return INT_MIN;
    }
    else
    {
        return (S->array[S->top]);
    }
}

void delete(struct Stack* S)
{
    if(S)
    {
        if(S->array)
        free(S->array);
        free(S);
    }
}

int main()
{
    int i=0,capacity = 15;
    
    struct Stack *newstack = createStack(capacity);
  
    for(i=0;i<capacity;i++)
    {
        push(newstack,i);
    }

    printf(" Top Element is %d \n",peek(newstack));
    printf("The stack size is %d \n",size(newstack));

    for(i=0;i<capacity;i++)
    {
        printf(" Popped Element is %d \n",pop(newstack));
    }
    if(isEmpty(newstack))
    {
        printf("Stack is Empty \n");
    }
    else
    {
        printf("Stack is not Empty\n");
    }
    delete(newstack);
    return 0; 
}