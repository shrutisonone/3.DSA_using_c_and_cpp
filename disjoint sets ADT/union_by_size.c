#include<stdio.h>
#include<conio.h>

void Makeset(int arr[],int size)
{
    for(int i=0 ; i<size ; i++)
    {
        arr[i] = i;
    }
}
int Find(int arr[], int size, int SV)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == SV)
        {
            return SV;
        }
        else if (SV >= 0 && SV < size)
        {
            return -1;
        }
        else
        {
            return Find(arr, size, arr[i]);
        }
    }
}

void Union(int arr[], int size, int parent1, int parent2)
{
    if (Find(arr, size, parent1) == Find(arr, size, parent2) && Find(arr, size, parent1) != -1)
    {
        return;
    }
    else if (arr[parent2] < arr[parent1]) // Remove the semicolon
    {
        arr[parent1] = parent2;
        arr[parent2] += arr[parent1];
    }
    else
    {
        arr[parent2] = parent1;
        arr[parent1] += arr[parent2];
    }
}
int main()
{
    int arr[100];
    Makeset( arr,20);
    Find(arr,20,5);
    Union(arr,20,10,20);

    return 0;
}
