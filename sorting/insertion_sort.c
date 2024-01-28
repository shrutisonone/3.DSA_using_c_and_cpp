#include<stdio.h>
int main()
{
    int i;
    int j;
    int n;
    int min;
    int temp; 

    printf("Enter the  size of the array \n");
    scanf("%d",&n);
    
    int arr[n];

    printf("Enter the elements of the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    

    // insertion sort 
    for( i=1 ; i < n ;i++)
    {
      int temp = arr[i];
       int j = i-1;

       while(j>=0 && arr[j] > temp)
       {
        arr[j+1]= arr[j];
        j--;
       }
       arr[j+1] = temp;
    }
    
    for(i=0;i<n;i++)
    {
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}