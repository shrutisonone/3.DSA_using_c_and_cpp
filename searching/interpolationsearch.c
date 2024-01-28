#include<stdio.h>
#include<conio.h>

int IS(int arr[],int data)
{
    int low = 0 ;
    int high = sizeof(arr[0]) -1;
    int mid ;
    
    while (low <= high ) 
    {
        mid = low + ( data - arr[low]) * ( high - low )/ arr[high] - arr[low];

        if( arr[mid] == data)
        {
            return mid+1;
        }
        if( data < arr[mid])
        {
            high = mid +1;
        }
        else
        low = mid - 1;
    }
    return -1;
}