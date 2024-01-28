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


struct Node *removedupli(struct Node* head)
{
    if(head == NULL && head->next == NULL)
    {
        return head;
    }

    struct Node* temp = head;
    struct Node* curr = head;

    while(curr != NULL || curr -> next != NULL)
    {
        temp = curr -> next;

        while(temp != NULL || temp -> next != NULL)
        {
            if(curr -> data == temp -> data)
            {
                curr -> next = curr -> next -> next;
                free(temp);
            }
            else
            {
                curr = curr -> next;
                temp = temp -> next;
            }
        }
    }
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
    
    printf("Linked List Before removal\n");
    traversal(head);

    head=removedupli(head);
    printf("Linked List after removal of duplication\n");
     traversal(head);
}