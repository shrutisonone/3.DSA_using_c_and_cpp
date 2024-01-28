#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
  int data;
  struct BinaryTree *left;
  struct BinaryTree *right;
};

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


int findMaxelemnt(struct BinaryTree *root)
{
    if(root == NULL)
     return -1;

    int left,right,root_value,max=0;
    
    while(root != NULL)
    {
      root_value = root->data;
      left = findMaxelemnt(root->left);
      right = findMaxelemnt(root->right);

      if(left > right)
      {
        max=left;
      }
      else
       max = right;

       if(root_value > max)
       {
        max = root_value;
       }
       return max;
    }      
}

int main()
{
    struct BinaryTree *root;

    insert(root,70);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("The max element among the tree is : %d",findMaxelemnt(root));

}