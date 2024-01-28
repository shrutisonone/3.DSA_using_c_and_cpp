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

    for(i =0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
          if(arr[j]<arr[min])
          {
            min=j;
          } 
        }
        if(i!=arr[min]);
     {
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
     }
    }
    
    for(i=0;i<n;i++)
    {
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}