#include<stdio.h>
int main()
{
    int i;
    int value;
    int size;
   
    printf("Enter the size of the array \n");
    scanf("%d",&size);

    int arr[size];
    printf("Enter the elements for the array \n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter the value for the search\n");
    scanf("%d",&value);
    for(i=0;i<size;i++)
    {
     if(arr[i]==value)
        {
         break;
        }
    }
    if(i==size)
    {
     printf("The value to be searched is not FOUND  \n");
    }
    else
    {
      printf("The value to be searched is found at %d",i);
    }
    
    
    return 0;
}