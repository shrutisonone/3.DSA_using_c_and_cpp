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


void Heapsort(int arr[],int n)
{
    int capacity =  sizeof(arr);
    struct Heap *h = createHeap(capacity,n);
    int old_size ,i,temp;

    createHeap(h,arr,n);

    old_size = h->count;

    for( i = n-1 ; i>0 ; i++)
    {
        temp = h->array[0];
        h->array[0] = h->array[h->count-1];
        h->array[0] =temp;
        h->count--;

        heapify(h,0);
    }
    h->count = old_size;
}