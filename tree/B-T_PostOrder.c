#include<stdio.h>
#include<conio.h>

struct BinaryTree
{
  int data;
  struct BinaryTree *left;
  struct BinaryTree *right;
};

void Postorder(struct BinaryTree *root)
{
   if(root)
   {
    Postorder(root->left);
    Postorder(root->right);
    printf("%d",root);
   }
}

void NonrecursivePostorder(struct BinaryTree *root)
{
   struct Stack *S = createStack();
   struct BinaryTree *prev = NULL;

   do{
    while(root != NULL)
    {
        push(S,root);
        root= root->left;
    }
    while (root != NULL && !isEmpty(S))
    {
        root= top(S);
        if( root->right = prev)
        {
            printf(" %d",root->data);
            pop(S);
            prev = root;
            root = NULL;
        }
        else
        {
            root = root ->right;
        }
    }
    
   }while(!isEmpty(S));
   
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

// Main function to demonstrate BST Postorder traversal
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
    printf("PostOrder Traversal: ");
    Postorder(root);

    return 0;
}