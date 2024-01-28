#include<stdio.h>
#include "bubble_sort.h"
int main()
{
int i;
int j;
int temp;
int n;
int flag=1;

NewFunction();
scanf("%d",&n);
    
int arr[n];

printf("Enter the elements of the array \n");
for(i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}

for(i=0;i<n;i++)
{
    flag=1;
    for(j=i+1;j<n-i;j++)
    {   
        
        if(arr[j]>arr[j+1])
        {
          flag=0;
          temp=arr[j];
          arr[j]=arr[j+1];
          arr[j+1]=temp;
        }
        if(flag==1)
        {
            break;
        }
    }
}

for(i=0;i<n;i++)
    {
        printf("arr[%d] is %d\n",i,arr[i]);
    }
    
    return 0;
}
void NewFunction()
{
printf("Enter the  size of the array \n");
}