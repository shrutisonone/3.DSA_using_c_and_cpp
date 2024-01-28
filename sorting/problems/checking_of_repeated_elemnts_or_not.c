int chckDups(int arr[],int n)
{
    for(int i =0 ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[j]== arr[i])
            return 1;
            else
            return ;
        }
    }
}