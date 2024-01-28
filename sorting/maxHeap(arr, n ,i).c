maxHeap(arr, n ,i)
{
    int largest = i;
    int l = (2*i);
    int r = (2*i)+1;

    while( l <=n && arr[l] > arr[largest])
    {
        largest = l;
    }
    while( r <=n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}