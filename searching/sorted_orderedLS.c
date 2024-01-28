#include<stdio.h>
#include<conio.h>

int orderedlinearsearch(int arr[],int n,int data)
{
    for(int i = 0 ; i<n ; i++)
    {
        if(arr[i]= data)
        {
            return arr[i];
        }
        else if(arr[i]> data)
        {
            return -1;
        }
        else
         return -1;
    }
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
        printf(" \n %d",orderedlinearsearch(*arr,10,data));
    }

   return ;
}