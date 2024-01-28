#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
  int data;
  struct BinaryTree *left;
  struct BinaryTree *right;
};


// Function to insert a value into the BST
struct BinaryTree* insert(struct BinaryTree* root, int value) {
    // If the tree is empty, create a new node and return it as the new root
    if (root == NULL) {
        return createNode(root,value);
    }

    // Otherwise, recursively insert the value into the appropriate subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    // Return the unchanged root pointer
    return root;
}

int createNode(struct BinaryTree *root , int value)
{
  struct Queue *Q;
  struct BinaryTree *temp;
  struct BinaryTree *newNode;

  newNode = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));

  if(!newNode)
  {
    printf("Memory not allocated \n");
  }

  if(!root)
  {
    root = newNode;
    return newNode;
  }

  Q = createQueue();
  enQueue(Q, root);
  
  while(!isEmpty(Q))
  {
    temp = deQueue(Q);

    if(temp->left)
    {
      enQueue(Q,temp->left);
    }
    else
    {
      temp->left= newNode;
      deleteQueue(Q);
      return newNode;
    }

     if(temp->right)
    {
      enQueue(Q,temp->right);
    }
    else
    {
      temp->right= newNode;
      deleteQueue(Q);
      return newNode;
    }
  }
  deleteQueue(Q);
}

int findMaxelemnt_withoutrecur(struct BinaryTree *root)
{
    struct BinaryTree *temp;
    int max=0;
    
    struct Queue *Q = createQueue();
    enQueue(Q,root);
    while(!isEmpty(Q))
    {
        temp = deQueue();
        if(max < temp->data);
         max = temp -> data;
        if(temp->left)
         enQueue(Q,temp->left);
        if(temp->right)
         enQueue(Q,temp->right);
    }
    deleteQueue(Q);
    return max;
}
