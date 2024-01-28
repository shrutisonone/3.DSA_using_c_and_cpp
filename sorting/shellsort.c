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
    

    //shell sort
    for(int gap = n/2 ; gap > 1 ; gap = gap / 2)
    {
        for ( j = gap ; j < n ; j++)
        {

            for( i = j - gap ; i>=0 ; i-gap)
            {
                if(arr[i+gap] > arr[i])
                  break;            
               else
               {
                int temp = arr [i+gap];
                arr[i+gap] = arr[i];
                arr[i] = temp;
                }
        }
    }


    {
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}
}
