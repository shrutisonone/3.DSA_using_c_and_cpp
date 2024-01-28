#include<bits/stdc++.h>
using namespace std;

class MaxHeap{

  int *arr; //pointer pointing to elements in array in heap
  int maxSize; //max possible size of max heap
  int heapSize; //number of elements in heap

  public:
     MaxHeap(int maxSize); //constructor function

     void MaxHeapify(int); //heapify a sub tree given as root

     int parent(int i)  //returns the index of parent
     {
        return(i-i) / 2;
     }

     int leftchild(int i)
     {
        return (2*i +1);
     }

    int rightchild(int i)
     {
        return (2*i +2);
     }
  
    int removeMax();  //remove root that contains max elements
 
    void increaseKey(int i,int new_val);  //increase the value of key i+1 to some new value

    int getMax()
    {
        return arr[0];
    }

    int currentSize()
    {
        return heapSize;
    }

    void deleteKey(int i);

    void insertKey(int i); 
};

//constructor function builds a heap
//from the given array arr[]

MaxHeap::MaxHeap(int totSize)
{
  heapSize = 0;
  maxSize = totSize;
  arr = new int[totSize];
}

//inserting a new key
void MaxHeap::insertKey(int x)
{
    //to check key is inserted or not 
    if(heapSize == maxSize)
    {
        cout <<" \ Overflow : Could not inser key\n";
        return;
    }

    heapSize++; //newkey inserted at end

    int i = heapSize -1;
    arr[i] = x;

    while( i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[i] ,arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::increaseKey(int i,int newVal)
{
    arr[i] = newVal;
    while( i != 0 && arr[parent(i)] < arr[i])
    {
        arr[i] = newVal;
        while( 1 != 0  )
    }
}