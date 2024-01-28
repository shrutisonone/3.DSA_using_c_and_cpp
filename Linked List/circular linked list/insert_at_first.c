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
    while(ptr->next!=NULL)
    {
        printf(" Element %d \n",ptr->data);
        ptr=ptr->next;
    }
}


struct Node *insertatfirst(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc (sizeof(struct Node*));
    ptr->data=data;

    struct Node *p=head->next;

    while(p->next!=head)
    {
        p=p->next;
    }
    //at this point p points to last node of circular list
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    
    return head;
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
    
    printf("Linked List Before insetion\n");
    traversal(head);

    head=insertatfirst(head,90);
    printf("Linked List after insertion\n");
     traversal(head);
}