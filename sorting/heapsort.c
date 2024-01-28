#include<stdio.h>
int main()
{
    int i;
    int j;
    int n;
    int min;
    int temp; 

    printf("Enter the  size of the array \n");
    scanf("%d",&n);
    
    int arr[n];

    printf("Enter the elements of the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    

    // heap Sort
    int heapsort(arr,n);
    
    for(i=0;i<n;i++)
    {
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}

int heapsort(int arr[],int n)
{
    /*
    This line initializes a heap data structure using the createHeap function. 
    This function should create a heap structure and allocate memory for the array inside the heap.
    */
    struct Heap *h = createHeap(n);
    int old_size , i , temp;
    
    /*
    This line builds a max heap from the input array arr using the buildheap function. 
    The buildheap function should take the heap structure h, the input array arr, and its size n, and construct a max heap.
    */
    buildheap(h,arr,n);

    /*
    This loop iterates from the end of the array to the beginning.
     In each iteration, it swaps the maximum element (at the root) with the last element in the heap, reduces the heap size by one, and then restores the heap property using percolateDown on the root.
    */
   for (int i = n - 1; i > 0; i--) 
   {
    temp = h->arr[0];
    h->arr[0] = h->arr[i];
    h->arr[i] = temp;
    h->count--;

    percolateDown(h, 0);
    }
    
    //restoring heapsize.
    h-> count = old_size;
}