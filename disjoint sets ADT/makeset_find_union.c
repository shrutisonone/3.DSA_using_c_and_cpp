#include<stdio.h>
#include<conio.h>

void Makeset(int arr[],int size)
{
    for(int i=0 ; i<size ; i++)
    {
        arr[i] = i;
    }
}

int Find(int arr[],int size, int SV)
{
    for(int i =0 ; i<size ; i++)
    {
        if(arr[i] == SV)
        {
            return SV;
        }
        else
        if(SV>= 0 && SV <size)
        {
            return -1;
        }
        else
        {
            return Find(arr[SV],size,SV);
        }
    }
}

void Union(int arr[],int size,int parent1,int parent2)
{
    if(Find(arr,size,parent1) == Find(arr,size,parent2))
    return ;
    else if( !((parent1 >= 0 && parent1 <size) && (parent2 >= 0 && parent2 <size)))
    {
        return;
    }
    arr[parent1] =  parent2;
}

int main()
{
    int arr[100];
    Makeset( arr,20);
    Find(arr,20,5);
    Union(arr,20,10,20);

    return 0;
}