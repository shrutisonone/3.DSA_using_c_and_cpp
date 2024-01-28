#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* link;

    Node(int n)
    {
        this->data = n;
        this -> link = NULL;
    }
};

class Stack 
{
    Node* top;

    public:
     stack()
     {
        top = NULL;
     }

};

void push(int data)
{
    Node* temp = new Node(data);

    if(!temp)
    {
        cout<<"\n Stack Overflow\n";
        exit(1);
    }

    temp ->data = data;

    temp -> link = top;
    
    top = temp;
}

bool isEmpty()
{
    return top= NULL;
}

int peek()
{
    if(!isEmpty)
     return top->data;
    else
     exit(1);
}

void 