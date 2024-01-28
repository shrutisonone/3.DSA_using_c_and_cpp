int Find(int arr[],int size,int n)
{
    if( ! (n >= 0 && n <= size) )
    return -1; // Invalid input
    if(arr[n] <= 0)
    return -2; // Element not found in array
    else
    {
      return( arr[n] =  Find(arr,size,n));
    }
}
int find(int arr[] , int size , int n)
{
    int i,temp;

    for( i = n ; arr[n] > 0 ; i = arr[i])
    {
      
      while(arr[n] > 0)
      {
        temp = n;
        n = arr[n];
        arr[temp] = i;
      }
      return i;
    }
}