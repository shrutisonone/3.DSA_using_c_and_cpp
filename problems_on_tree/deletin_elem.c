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

int delete(struct BinaryTree *root)
{
    if(root == NULL)
     return;
    delete(root->left);
    delete(root->right);
    free(root);
    return 0;
}


int main() {
    // Initialize an empty BST
    struct BinaryTree* root ;

    // Insert values into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    
    insert(root, 80);

  //function to be performed
  if(delete(root) ==  0)
  printf("The tree has been deleted \n");
  

    return 0;
}