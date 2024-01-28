void countingsort(int arr[],int n, int brr[],int k)
{
    int crr[k],i,j;

    //c-array che sarve elements zero
    for(i =0 ; i<k ;i++)
    {
        crr[i]=0;
    }

    //c[i] has now elements of i
    /*
    This loop iterates through the input array arr and counts the occurrences of each element. 
    It increments the count in the crr array at the index corresponding to the value of the
     element.
    */
    for(j=0 ; j<n ; j++)
    {
      crr[arr[j]] = crr[arr[j]]+1;
    }

    //c[i] now contains elements <=i
    /*
    This loop modifies the counting array crr to store the cumulative count of elements. 
    After this loop, crr[i] will contain the count of elements less than or equal to i.
    */
    for(i=1 ; i<k ; i++)
    {
        crr[i] = crr[i] + crr[i-1];
    }
    

    /*
    This loop builds the output array brr by placing elements in their correct sorted order.
     It uses the counting array crr to determine the position where each element should be placed.
    */
    for(j=n-1 ; j>=0 ; j--)
    {
        brr[crr[arr[j]]] = arr[j];
        crr[arr[j]] = crr[arr[j]] - 1;
    }
}