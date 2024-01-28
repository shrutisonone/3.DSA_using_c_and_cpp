#define bckt 10
void bucketsort(int arr[],int n)
{
    int i,j,k;

    int bucket[bckt];

    for(j=0 ; j<bckt ; j++)
    {
        bucket[j]=0;
    }
    
        // This loop iterates through the input array arr and counts the occurrences of each element. 
        // It increments the count in the bucket array at the index corresponding to the value of the element.
    for(i=0 ; i<n ; i++)
    {
        ++bucket[arr[i]];
    }

    /*
    This nested loop constructs the sorted array by iterating through the bucket array. 
    It places elements in the correct order based on the counts stored in the bucket array. 
    The outer loop iterates over each bucket, and the inner loop adds the corresponding element to the sorted array
    */
    for(i=0,j=0 ; j<bckt ; j++)
    {
        for(k= bucket[j] ; k>0 ; --k)
        {
            arr[i++] = j;
        }
    }
}