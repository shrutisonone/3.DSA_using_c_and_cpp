// insert at begin

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void traversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf(" Element %d \n",ptr->data);
        ptr=ptr->next;
    }
}

struct Node * insertAtFirst(struct Node *head,int data)
{
     struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
     ptr->next=head;
     ptr->data=data;
     return ptr;

}

int main()
{
     struct Node *head;
    struct Node *second;
    struct Node *third;

    //allocate memory for Nodes in ll in heap
    head=(struct Node*)malloc(sizeof(struct Node*));
    second=(struct Node*)malloc(sizeof(struct Node*));
    third=(struct Node*)malloc(sizeof(struct Node*));

    head->data=8;
    head->next = second;  

    second->data=89;
    second->next = third;

    third->data=90;
    third->next = NULL;

    traversal(head);

    head= insertAtFirst(head,54);

    traversal(head);
 
}