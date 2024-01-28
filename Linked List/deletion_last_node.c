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

struct Node *deletelastnode(struct Node *head)
{
    struct Node *p=head;
    struct Node *q=head->next;

    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
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

    head->data=1;
    head->next = second;  

    second->data=3;
    second->next = third;

    third->data=8;
    third->next = NULL;
    
    printf("Linked List Before Deletion\n");
    traversal(head);

    head=deletelastnode(head);
    printf("Linked List after Deletion\n");
     traversal(head);
}