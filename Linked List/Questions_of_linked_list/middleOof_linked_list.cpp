#include<iostream>
#include<map>
using namespace std;

class Node
{
    public:
     int data;
     Node* next;

    //constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
      int value = this->data;
      if(this->next != NULL)
      {
        delete next;
        next= NULL;
      }

      cout<< "memory is free for node with data " << value <<endl;
    }
};

void insertNode(Node* tail,int element,int d)
{
    //empty list
    if(tail == NULL)
    {
        Node* newNode = newNode(d);
        tail =newNode;
    }
    else
    
    {
        //element found 
        Node temp =new Node(d);
        temp-> nest = curr->next;
        curr->next=temp;
         Node* curr =tail;
         while(surr->data != element)
         {
            curr=curr->next;
         }
    }

     
        //element found 
        Node temp =new Node(d);
        temp-> nest = curr->next;
        curr->next=temp;
}

void printnode(Node* tail)
{
    Node* temp =tail;

    //empty list
    if(tail == NULL)
    {
        cout<<"List is empty ,please check again"<<endl;
        return;
    }

    do
    {
       cout<< tail ->data <<"  ";
       tail=tail->next;
    } while (tail != temp);

    cout<<endl;
    
}

void deleteNode(Node *tail,int value)
{
   if(tail =NULL)
   {
    cout<<"List is empty please check again"<<endl;
    return;
   }
   else
   {
     // assuming the value is present in the linked list 
     Node* prev = tail;

   }
}

int main()
{
    Node* node1 = new Node(10);

    Node* head= node1;
    Node* tail =NULL;

    insertNode(tail,12);

    insertNode(tail,15);

    insertatindex(tail,head,4,22);

    
}


