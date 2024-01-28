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

int countnodes(struct Node *head)
{
  struct Node *p=head;
  int count=0;

  for(p=head;p->next!=NULL;)
  {
    p=p->next;
    count++;
  }
  return count;
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
    
    traversal(head);
    int count=countnodes(head);
    printf("The count is %d",count);
    

    return 0;
}