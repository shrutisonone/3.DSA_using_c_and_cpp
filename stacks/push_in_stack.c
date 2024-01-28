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

int isFull(struct Stack* S)
{
    return (S->top == S->capacity - 1);
}

  void push(struct Stack* S,int data)
  {
    if (isFull(S))
    {
      printf("Stack is Overflown\n");
    }
    else
    {
      S->array[++S->top]=data;
    }
  }

int main()
{
  int i=0;
  int capacity = 20;
  
  struct Stack* n = createStack(capacity);

  for(i=0;i<capacity;i++)
  {
    push(n,i);
  }
  
  for(i=0;i<capacity;i++)
  {
    printf("%d \n",n[i]);
  }
 
 return 0;
}