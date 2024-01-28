//If the linked list has even number of nodes then finding the middle of the linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node *middlenode(struct Node *head)
{
    if(head==NULL)
    {
        printf("Error :List is Empty");
        return NULL;
    }

    struct Node *slow,*fast;
    slow=fast=head;
    while(fast!=NULL &&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

int main()
{
     struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //allocate memory for Nodes in ll in heap
    head=(struct Node*)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    third=(struct Node*)malloc(sizeof(struct Node*));
    fourth=(struct Node*)malloc(sizeof(struct Node*));

    head->data=1;
    head->next = second;  

    second->data=3;
    second->next = third;

    third->data=8;
    third->next = fourth;

    fourth->data=10;
    fourth->next=NULL;

    int mn = middlenode(head);
    printf("The Middle node is %d",mn);
}