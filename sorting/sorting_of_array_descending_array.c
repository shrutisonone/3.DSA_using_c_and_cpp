    #include<stdio.h>
    int main()
    {
        int n;
        int i;
        int j;
        int x;

        printf("Enter the size of the array \n");
        scanf("%d",&n);

        int arr[n];
        
        printf("Enter the elements of the array  \n");
        for(i=0;i<n;i++)
        {
        scanf("%d",&arr[i]);
        }
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(arr[i]<arr[j])
                x=arr[i];
                arr[i]=arr[j];
                arr[j]=x;
            }
        }
        

        return 0;
    }