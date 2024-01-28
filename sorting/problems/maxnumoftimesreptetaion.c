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
    
    int mostfrequent(int arr[],int n);

     for(i=0;i<n;i++)
    {
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}

int mostfrequent(int arr[],int n)
{
    int i;
    int j;
    int max_cntr=1;
    int current_cntr=1;
    int res=arr[0];

    for(i=0 ; i<n ; i++)
    {
      if(arr[i]==arr[i+1])
      {
        current_cntr++;
      }
      else
      {
        if(current_cntr > max_cntr)
        {
            max_cntr = current_cntr;
            res=arr[i+1];
        }
        current_cntr=1;
      }
    }
    //if last element is most frequent
    if(current_cntr > max_cntr)
    {
        max_cntr=current_cntr;
        res=arr[n-1];
    }
    return res;
}