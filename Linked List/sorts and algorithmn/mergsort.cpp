#include<iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e)/2;

    int len1=(mid - s)+1;

    int len2 = (e- mid);

    int *first = new int[len1];
    int *second = new int[len2];

    int  mainarrind = s;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[ mainarrindx++];
    }
    
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[ mainarrindx++];
    }

}


void mergesort(int *arr,int s,int e)
{
    if(s < e)
    {
    int mid = (s + e)/2;

    //left part sort
    mergesort(arr,s,mid);

    //right part sort
    mergesort(arr,mid+1,e);

    //merging both right and left part
    merge(arr,s,mid,e);
    }
}
