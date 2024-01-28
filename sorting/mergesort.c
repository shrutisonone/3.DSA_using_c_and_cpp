#include<stdio.h>
int main()
{
    int i;
    int j;
    int n;
    int lb;
    int ub;
    int mid ;

    printf("Enter the  size of the array \n");
    scanf("%d",&n);
    
    int arr[n];

    printf("Enter the elements of the array \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    

    //merge sort
    ub = n - 1;
     lb = 0;
     mid = ub - lb /2;
    
    if( lb < ub)
    {
        int temp;
        mergesort(arr,temp,lb,mid);
        mergesort(arr,temp,mid+1,ub);
        merge(arr,temp,lb,mid+1,ub);
    }

    {
        printf("arr[%d] is %d\n",i,arr[i]);
    }

    return 0;
}

int merge( int arr[],int temp, int lb, int mid,int ub)
{
    int i = lb;
    int j = mid+1;
    int k= lb;
    int b[8];

    while( i <= mid && j <= ub)
    {
        if(arr[i] < arr[j])
        {
           b[k] = arr[i];
           i++;
        }
        else
        {
            b[k]= arr[j];
            j++;
        }
        k++;
    }

    if(i>mid)
    {
        while(j <= ub)
        {
          b[k]=arr[j];
          j++;
          k++;
        }
    }
    else
    {
        while(i <= mid)
        {
            b[k]= arr[i];
            i++;
            k++;
        }
    }
}


