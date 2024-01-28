#include<stdio.h>
#include<conio.h>

int findlargestnum(int arr[],int n)
{
    int i,large = arr[0];
    
    for(int i =0;i<n;i++)
    {
        if(arr[i]>large)
        {
            large = arr[i];
        }
    }
    return large;
}

int findsmallestnum(int arr[],int n)
{
    int i, small = arr[0];

    for(int i =0;i<n;i++)
    {
        if(arr[i]<small)
        {
            small = arr[i];
        }
    }
    return small;
}

void main()
{
    int arr[5]={1,2,3,4,5};
    int n=5;
    printf("The largest number is %d",findlargestnum(arr,5));
    printf("The smallest number is %d",findsmallestnum( arr,5));

}