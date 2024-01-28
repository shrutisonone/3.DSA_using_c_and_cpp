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

int seqsearch(struct Node *head,int sv)
{
    struct Node *p=head;

    while(p->next!=NULL)
    {
        if (p->data=sv)
        {
           break;
        }
        else
        {
             p=p->next;
        }
    }

    return sv;
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

    int sv;

   printf("Enter the search Value \n");
   scanf("%d",sv);

   int value=seqsearch(head,3);
   printf("The search value is found and =%d",value);

    return 0;
}