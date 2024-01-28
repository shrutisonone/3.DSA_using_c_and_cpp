int element(int *A,int n,int e)
{
    for(int i =0;i<n;++i)
    if(A[i] == e)
     return 1;
     return 0;
}
int RemoveDuplicates(int *A,int n)
{
    int m=0;
    for(int i = 0;i<n;++i)
    {
        if(!element(A,m,A[i]))
        {
            A[m++]=A[i];
        }
        return m;
    }
}