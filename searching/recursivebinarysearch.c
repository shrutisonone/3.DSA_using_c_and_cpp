#include<stdio.h>
#include<conio.h>

int binarysearch(int arr[],int low,int high,int data)
{
    int mid = low + (high - low )/ 2;
     
    if( low < high)
    return -1;
    else if(data == arr[mid])
    {
        return mid;

    }
    else if(arr[mid] < data)
    {
        return binarysearch(arr,mid+1,high,data);
    }
    else
    {
        return binarysearch(arr,low,mid-1,data);
    }

    return 0;
}


void main()
{
    int arr[10];
    int data;

    printf("Enter the elements of array : ");
    
    for( int i =0 ; i<10 ; i++)
    {
        scanf("%d",&arr[i]);
    }

   printf("Enter the data to be searched\n");
   scanf(" %d",&data);


    printf("The Ordered List is as");
    for (int i=0;i<10;i++)
    {
        printf(" \n %d",binarysearch(arr,0,10,data));
    }

   return ;
}