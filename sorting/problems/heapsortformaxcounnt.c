#include<stdio.h>
int main()
{
    int i,count,n;
    int arr[n];
//     int maxcount=0;
//     int elemnt= arr[0];

    printf("Enter the  size of the array \n");
    scanf("%d",&n);


    printf("Enter the elements of the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   
    int checkwhowinselection(int arr[],int n);
//      Heapsort(arr,n);

//     for(i=0 ; i<n ; i++)
//     {
//         if(arr[i] == arr[0])
//         count++;
        
//          if(count > maxcount)
//         {
//            maxcount=count;
//            elemnt = arr[i];
//         }
//     }
   
    
//     for(i=0;i<n;i++)
//     {
//         printf("maxcount is [%d] is %d\n",arr[i],maxcount);
//     }

    return 0;
}
 //

 int checkwhowinselection(int arr[],int n)
 {
    int i,j;
    int current_counter=1;
    int max_counter=1;
    int currentcandidate;
    int maxcandidate;
    currentcandidate=maxcandidate=arr[0];

    Heapsort(arr,n);

    for(i=0 ; i<n ; i++)
    {
        if(arr[i] = currentcandidate)
        {
            current_counter++;
        }
        else
        {
        currentcandidate=arr[i];
        current_counter=1;
        }
        if(current_counter > max_counter)
        {
            maxcandidate=currentcandidate;
            max_counter=current_counter;
        }
    }
    return currentcandidate;
 } 

 int heapsort(int arr[],int n)
{
     struct Heap *h = createHeap(n);
    int old_size , i , temp;

    buildheap(h,arr,n);

    for(i=n-1 ; i>=0 ; i--)
    {
      temp= h->arr[0];
      h->arr[0]=h->arr[i];
      h->arr[0]=temp;

      percolateDown(h,0);
    }

    h->count = old_size;
}