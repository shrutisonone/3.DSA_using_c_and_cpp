#include<stdio.h>
int main()
{
    int i,count,n;
    int arr[n];
    int maxcount=0;
    int elemnt= arr[0];

    printf("Enter the  size of the array \n");
    scanf("%d",&n);


    printf("Enter the elements of the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   
    
     
    for(i=0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[i] == arr[j])
            count++;
        }
         if(count > maxcount)
        {
           maxcount=count;
           elemnt = arr[i];
        }
    }
   
    
    for(i=0;i<n;i++)
    {
        printf("maxcount is [%d] is %d\n",arr[i],maxcount);
    }

    return 0;
}
