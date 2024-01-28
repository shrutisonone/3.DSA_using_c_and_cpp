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

int isinkdlistnumbereven(struct Node *head)
{
    while(head && head->next)
    {
        head=head->next->next;
        if(!head)
        {
            return 0;
        }
        return 1;
    }
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

    int num;
    if(isinkdlistnumbereven(head)==0)
    printf("The linked list is Even\n");
    else
    printf("The linked list is odd for a change \n");

}