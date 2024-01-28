int checkdup(int arr[],int n)
{
    Heapsort(arr,n);
    {
        for(int i=0 ; i<n ; i++)
        {
            if(arr[i] == arr[i+1])
            return 1;

            return ;
        }
    }
}