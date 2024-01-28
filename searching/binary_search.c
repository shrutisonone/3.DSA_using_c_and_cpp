    #include<stdio.h>
    int main()
    {
        int i;
        int n;
        int mid;
        int l=0;
        int r=n-1;
        int sv;

        printf("Enter the size of the array \n");
        scanf("%d",&n);

        int arr[n];

        printf("Enter the elements of the array \n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        
        printf("Enter the value to be searched \n");
        scanf("%d",&sv);
        
        do
        {
            mid=l+(r-l)/2;
            if(arr[mid]==sv)
            { 
                printf("The Search value found at %d",mid);
                break;
            }
            else 
            {
               if(arr[mid]>sv)
               {
                r=mid-1;
                printf("Enter\n");
               }
               else
               {
                l=mid+1;
               }
            } 
        }while(l<=r);
        
        if(l<=r)
        {
         printf("Search value found \n");
        }
        else
        {
         printf("Search value not found \n");
        }

        return 0;
    }