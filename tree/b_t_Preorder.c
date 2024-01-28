#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
  int data;
  struct BinaryTree *left;
  struct BinaryTree *right;
};

void Preorder(struct BinaryTree *root)
{
  if(root)
  {
    printf(" %d",root->data);
    Preorder(root->left);
    Preorder(root->right);  //recursive call for preorder
  }
}

void NonrecursivePreOrder(struct BinaryTree *root)
{
  struct stack *S = createStack();
  
  if(root == NULL)
  {
    return;
  }


  while(1)
  {
    while (root)
    {
        printf("%d",root ->data);  //process current data
        push(S,root);
        root=root->left;  //if left sub-tree then add to stack
    }
    if(isEmpty(S))
      break;
    root=pop(S);  //completion of left and root node now goin to right node
    root = root->right; 
  }
  deleteStack(S);
}

// Function to insert a value into the BST
struct BinaryTree* insert(struct BinaryTree* root, int value) {
    // If the tree is empty, create a new node and return it as the new root
    if (root == NULL) {
        return createNode(value);
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

// Main function to demonstrate BST preorder traversal
int main() {
    // Initialize an empty BST
    struct Bin* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform preorder traversal and print the result
    printf("Preorder Traversal: ");
    preorderTraversal(root);

    return 0;
}
