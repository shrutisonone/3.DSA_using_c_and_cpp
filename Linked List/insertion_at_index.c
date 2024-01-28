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

struct Node * insertatindex(struct Node *head,int data,int index)
{
     struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
     struct Node *p=head;

     int i=0;
     while(i=!index-1)
     {
        p=p->next;
        i++;
     }
     ptr->data =data;
     ptr->next =p->next;
     p->next =ptr;

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

    head->data=8;
    head->next = second;  

    second->data=89;
    second->next = third;

    third->data=90;
    third->next = NULL;

    traversal(head);

    head= insertatindex(head,54,1);

    traversal(head);
 
}