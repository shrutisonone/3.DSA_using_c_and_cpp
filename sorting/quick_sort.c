void Quicksort(int arr[],int low,int high)
{
    int pivot;

    if(low < high)
    {
        pivot = partition(arr,low,high);
        Quicksort(arr,low,pivot-1);
        Quicksort(arr,pivot+1,high);
    }
}

int partition(int arr[],int low,int high)
{
    int left,right,pivotpnt;
    left = low;
    right = high;
    pivotpnt = arr[left];

    while(left<right)
    {
        while(arr[left] <= pivotpnt)
        {
            left++;
        }
        while(arr[right] > pivotpnt)
        {
            right++;;
        }
        if(left > right)
        {
            swap(arr,left,right);
        }
    };
    arr[low]=arr[right];
    arr[right]=pivotpnt;
    return right;
}