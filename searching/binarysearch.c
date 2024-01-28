#include<stdio.h>
#include<conio.h>

int binarysearch(int arr[],int n,int data)
{
    int low = 0;
    int high = n-1;
    
    
    while(low < high)
    {
        int mid = low + (high - low )/ 2;
        if(arr[mid] == data)
        {
            return arr[mid];
        }
        else if(data > arr[mid])
        {
            return low = mid + 1;
        }
        else
           return high = mid - 1;
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
        printf(" \n %d",binarysearch(*arr,10,data));
    }

   return ;
}