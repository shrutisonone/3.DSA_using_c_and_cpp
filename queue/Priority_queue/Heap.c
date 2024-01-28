#include<stdio.h>
#include<conio.h>

struct Heap
{
    int *array;
    int count;
    int capacity;
    int Heap_type;
};

struct Heap *createHeap(int capacity,int Heap_type)
{
    struct Heap *h = (struct Heap*)malloc(sizeof(struct Heap));
    if(!h)
    {
        return NULL;
    }

    h->Heap_type = Heap_type;
    h->count = 0;
    h->capacity = capacity;
    h->array = (int*)malloc(sizeof(int)*h->capacity);
    if(!h->array)
    {
        return NULL;
    }
    return h;
}

int parent(struct Heap *h,int i)
{
    if(i <= 0 || i>=h->count)
     return -1;
    return i-1/2;
}

int leftchild(struct Heap *h,int i)
{
  int left = 2*i+1;

  if(left >= h->count)
  {
    return -1;
  }
  return left;
}
int rightchild(struct Heap *h,int i)
{
  int right = 2*i+2;

  if(right >= h->count)
  {
    return -1;
  }
  return right;
}

int max_element(struct Heap *h)
{
  if(h->count == 0)
  {
    return -1;
  }
  return h->array[0];
}


//Heapifying an element
void heapify(struct Heap *h,int i)
{
    int lft,ryt,temp; int max;
    lft= leftchild(h,i);
    ryt= rightchild(h,i);

    if( lft = -1 && h->array[lft] > h->array[i])
    {
         max = lft;
    }
    else
    {
        max = i;
    }
    
    if(ryt = -1 && h->array[ryt] > h->array[i])
    {
      max = ryt;
    }
    else
    {
        max = i;
    }
    if(max != i)
    {
        //swap the elements
        temp = h->array[i];
        h->array[i] =  h->array[max];
        h->array[max] = temp;
        heapify(h,max);
    }
}

void insert(struct Heap *h,int i)
{
  int i;
  if(h->count == h->capacity)
  resizeHeap(h);
  
}

void deleteElement(struct Heap *h,int data)
{
  if(h->count == 0)
    return -1;
  data = h->array[0];
  h->array[0]= h->array[h->count-1];
  h->count--;
  heapify(h,0);

  return data;
}
