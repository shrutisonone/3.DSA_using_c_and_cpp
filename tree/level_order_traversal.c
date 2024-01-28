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

int LevelOrderTraversal(struct BinaryTree *root)
{
    struct BinaryTree *temp ;

    struct Queue *Q = createQueue();

    if(!root)
     return;

    enQueue(Q,root);
    while(!isEmpty(Q))
    {
      temp = deQueue(Q); //1st elements that is dequeued is put into temp

      printf("%d",temp->data);
      /* First we check the left child */
     if(temp ->left)
     {
        enQueue(Q,temp->left);
     }
     if(temp ->right)
     {
        enQueue(Q,temp->right);
     }
    }


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
    printf("Level Order Traversal: ");
    LevelOrderTraversal(root);

    return 0;
}