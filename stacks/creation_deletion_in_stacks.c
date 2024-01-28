#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct stack
{
    int top;
    int capacity;
    int *array;
};

struct stack *createarray(int capacity)
{
   struct stack *S=malloc(sizeof(struct stack));
   S->capacity = capacity;
   S->top=-1;
   S->array = malloc(S -> capacity*sizeof(int));
   if(!S)
   {
     return S;
   }
}

int isEmpty(struct stack *S)
{
    return(S->top == -1);
}

int size(struct stack *S)
{
    return(S -> top+1);
}

int isfull(struct stack *S)
{
    return(S -> top == S -> capacity -1);
}

void push(struct stack *S,int data)
{
    if(isfull(S))
    {
      printf("The stack is overflow\n");
    }
    else
    {
     S -> array[++S -> top] = data;
    }
}

int Pop(struct stack *S)
{
    if(isEmpty(S))
    {
        printf("The stack is Empty\n");
    }
    else
    {
       return S -> array[S -> top--];
    }
}

int peek(struct stack *S)
{
    if(isEmpty(S))
    {
      printf("Stack is Empty\n");
    }
    else
    {
      return(S -> array[S->top]);
    }
}

void deletestack(struct stack *S)
{
    if(S)
    {
        if(!S->array)
        {
            free(S->array);
        }
        free(S);
    }
}

int main()
{
    int i=0;
    int capacity =15;
    struct stack *S = createstack(capacity);
    
    for(i = 0;i<capacity ;i++)
    {
        push(S,i);
    }

    printf("Top Element is %d",S->top);
    printf("Stack Size is %d",size(S));

    for(i=0;i<capacity;i++)
    {
        printf("popped element is %d",Pop(S));
    }

    if(isEmpty(S))
      printf("The Stack is Empty\n");
    else
     printf("Stack is not Empty\n");

     deletestack(S);
     return 0;

}