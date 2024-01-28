#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
  int data;
  struct BinaryTree *left;
  struct BinaryTree *right;
};


void insertnewelem(struct BinaryTree *root , int new)
{
    struct BinaryTree *temp;
    struct Queue *Q = createQueue();
    struct BinaryTree *newele;

    newele = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));

    newele->left=newele->right = NULL;

    if(!newele)
     return -1;

    if(!root)
     return newele;

    while(!isEmpty(Q))
    {
        temp=deQueue(Q);
        if(temp->left)
         enQueue(Q);
        else
        {
          temp->left=newele;
          delete(Q);
          return;
        }

        if(temp->right)
         enQueue(Q);
        else
         {
          temp->right=newele;
          delete(Q);
          return;
         }
    }
    deleteQueue(Q);
}