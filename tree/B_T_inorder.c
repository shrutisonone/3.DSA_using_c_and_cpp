#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
  int data;
  struct BinaryTree *left;
  struct BinaryTree *right;
};

void InOrder(struct BinaryTree *root)
{
  if(root)
  {
    Inorder(root->left);
    printf(" %d",root->data);
    Inorder(root->right);  //recursive call for Inorder
  }
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

void NonrecursiveIOrder(struct BinaryTree *root)
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
        // root=root->left;  //if left sub-tree then add to stack 
        push(S,root);
        root=root->left;
    }
    if(isEmpty(S))
      break;
    root=pop(S);  
    printf("%d",root ->data);  //after popping process the current node
    root = root->right; 
  }
  deleteStack(S);
}

// Main function to demonstrate BST InOrde traversal
int main() {
    // Initialize an empty BST
    struct BinaryTree* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform InOrder traversal and print the result
    printf("InOrder Traversal: ");
    InOrderTraversal(root);

    return 0;
}